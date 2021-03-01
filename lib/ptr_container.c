/*
 * ptr_container.c
 *
 *  Created on: Jan 13, 2021
 *      Author: user
 */
#include <stdint.h>
#include <stddef.h>
#include "ptr_container.h"
#include "debug.h"

#define SEQ_RING_PTR_LIST_MAX_SIZE 16
volatile uint32_t srpl_read_pos = 0;
volatile uint32_t srpl_write_pos = 0;
volatile struct ptr_container srp_list[SEQ_RING_PTR_LIST_MAX_SIZE];
volatile size_t srpl_size = 0;

void srpl_test()
{
	void *buffers[2];
	srpl_init((void**)&buffers, 2);
	void *buffer;
	int32_t ret_val = 0;

	ret_val = srpl_write_get(&buffer);
	printk(INFO, "%s:  srpl_write_get 1 returned: %ld\r\n", __func__, ret_val);
	ret_val = srpl_write_set();
	printk(INFO, "%s:  srpl_write_set 1 returned: %ld\r\n", __func__, ret_val);

	ret_val = srpl_write_get(&buffer);
	printk(INFO, "%s:  srpl_write_get 2 returned: %ld\r\n", __func__, ret_val);
	ret_val = srpl_write_set();
	printk(INFO, "%s:  srpl_write_set 2 returned: %ld\r\n", __func__, ret_val);

	ret_val = srpl_write_get(&buffer);
	printk(INFO, "%s:  srpl_write_get 3 returned: %ld\r\n", __func__, ret_val);
	ret_val = srpl_write_set();
	printk(INFO, "%s:  srpl_write_set 3 returned: %ld\r\n", __func__, ret_val);

	/*******/

	ret_val = srpl_read_get(&buffer);
	printk(INFO, "%s:  srpl_read_get 1 returned: %ld\r\n", __func__, ret_val);
	ret_val = srpl_read_set();
	printk(INFO, "%s:  srpl_read_set 1 returned: %ld\r\n", __func__, ret_val);

	ret_val = srpl_read_get(&buffer);
	printk(INFO, "%s:  srpl_read_get 2 returned: %ld\r\n", __func__, ret_val);
	ret_val = srpl_read_set();
	printk(INFO, "%s:  srpl_read_set 2 returned: %ld\r\n", __func__, ret_val);

	ret_val = srpl_read_get(&buffer);
	printk(INFO, "%s:  srpl_read_get 3 returned: %ld\r\n", __func__, ret_val);
	ret_val = srpl_read_set();
	printk(INFO, "%s:  srpl_read_set 3 returned: %ld\r\n", __func__, ret_val);

}

void srpl_init(void **ptr_list, size_t ptr_list_size)
{
	srpl_size = ptr_list_size;
	uint32_t i = 0;
	for (; i < ptr_list_size; ++i) {
		srp_list[i].data_ptr = ptr_list[i];
		srp_list[i].data_state = empty;
		srp_list[i].lock_state = unlocked;
	}
	srpl_read_pos = 0;
	srpl_write_pos = 0;
}

int32_t srpl_read_get(void **ptr)
{
//	printk(INFO, "%s(): srpl_read_pos=%ld, srp_list[srpl_read_pos].data_state=%d, srp_list[srpl_read_pos].lock_state=%d\r\n",
//			__func__, srpl_read_pos, srp_list[srpl_read_pos].data_state, srp_list[srpl_read_pos].lock_state);
	/* unlock->lock */

	if (srp_list[srpl_read_pos].data_state == empty)
		return -SRPL_READ_EMPTY;

	if (srp_list[srpl_read_pos].lock_state == locked)
		return -SRPL_READ_LOCKED;

	srp_list[srpl_read_pos].lock_state = locked;

	*ptr = srp_list[srpl_read_pos].data_ptr;

	return SRPL_READ_OK;
}

int32_t srpl_read_set(void)
{
	uint32_t pos = srpl_read_pos;
//	printk(INFO, "%s(): srpl_read_pos=%ld, srp_list[srpl_read_pos].data_state=%d, srp_list[srpl_read_pos].lock_state=%d\r\n",
//			__func__, srpl_read_pos, srp_list[srpl_read_pos].data_state, srp_list[srpl_read_pos].lock_state);
	/* lock->unlock */
	if (srp_list[pos].lock_state == unlocked)
		return -SRPL_READ_UNLOCKED;

//	if (pc_ptr_list[pc_read_pos].data_state == empty)
//		return -PC_READ_EMPTY;

	srpl_read_pos = (srpl_read_pos + 1) % srpl_size;

	srp_list[pos].data_state = empty;
	srp_list[pos].lock_state = unlocked;

	return SRPL_READ_OK;
}

int32_t srpl_read_cancel(void)
{
	/* lock->unlock */
	/* full->full */
	if (srp_list[srpl_read_pos].lock_state == unlocked)
		return -SRPL_READ_UNLOCKED;

	srp_list[srpl_read_pos].lock_state = unlocked;
//	pc_ptr_list[pc_read_pos].data_state = full;

	return SRPL_READ_OK;
}

size_t srpl_read_size_get(void)
{
//	printk(INFO, "%s(): srpl_read_pos=%ld, srp_list[srpl_read_pos].data_state=%d, srp_list[srpl_read_pos].lock_state=%d\r\n",
//		__func__, srpl_read_pos, srp_list[srpl_read_pos].data_state, srp_list[srpl_read_pos].lock_state);

	if (srpl_write_pos == srpl_read_pos) {
		if (srp_list[srpl_read_pos].data_state == empty || srp_list[srpl_read_pos].lock_state == locked)
			return 0;
		else
			return 1;
	}


	if (srp_list[srpl_read_pos].lock_state == locked)
		return (srpl_write_pos - srpl_read_pos) % srpl_size - 1;
	else
		return (srpl_write_pos - srpl_read_pos) % srpl_size;
}

int32_t srpl_write_get(void **ptr)
{
//	printk(INFO, "%s(): srpl_write_pos=%ld, srp_list[srpl_write_pos].data_state=%d, srp_list[srpl_write_pos].lock_state=%d\r\n",
//			__func__, srpl_write_pos, srp_list[srpl_write_pos].data_state, srp_list[srpl_write_pos].lock_state);
	/* unlock->lock */

	if (srp_list[srpl_write_pos].data_state == full)
		return -SRPL_WRITE_FULL;

	if (srp_list[srpl_write_pos].lock_state == locked)
		return -SRPL_WRITE_LOCKED;

	*ptr = srp_list[srpl_write_pos].data_ptr;

	srp_list[srpl_write_pos].lock_state = locked;

	return SRPL_WRITE_OK;
}

int32_t srpl_write_set(void)
{
	uint32_t pos = srpl_write_pos;
//	printk(INFO, "%s(): srpl_write_pos=%ld, srp_list[srpl_write_pos].data_state=%d, srp_list[srpl_write_pos].lock_state=%d\r\n",
//				__func__, srpl_write_pos, srp_list[srpl_write_pos].data_state, srp_list[srpl_write_pos].lock_state);
	/* lock->unlock */
	if (srp_list[pos].lock_state == unlocked)
		return -SRPL_WRITE_UNLOCKED;

//	if (pc_ptr_list[pc_write_pos].data_state == full)
//		return -1;

	srpl_write_pos = (srpl_write_pos + 1) % srpl_size;

	srp_list[pos].data_state = full;
	srp_list[pos].lock_state = unlocked;

	return SRPL_WRITE_OK;
}

int32_t srpl_write_cancel(void)
{
	/* lock->unlock */
	/* empty->empty */
	if (srp_list[srpl_write_pos].lock_state == unlocked)
		return -SRPL_WRITE_UNLOCKED;

//	if (pc_ptr_list[pc_write_pos].data_state == full)
//		return -1;

	srp_list[srpl_write_pos].lock_state = unlocked;
//	srp_list[srpl_write_pos].data_state = empty;

	return SRPL_WRITE_OK;
}

size_t srpl_write_size_get(void)
{
//	printk(INFO, "%s(): srpl_write_pos=%ld, srp_list[srpl_write_pos].data_state=%d, srp_list[srpl_write_pos].lock_state=%d\r\n",
//			__func__, srpl_write_pos, srp_list[srpl_write_pos].data_state, srp_list[srpl_write_pos].lock_state);


	if (srpl_write_pos == srpl_read_pos &&
		(srp_list[srpl_write_pos].data_state == full ||
		srp_list[srpl_write_pos].lock_state == locked)) {

		return 0;
	} else {
		return 1;
	}

	if (srp_list[srpl_write_pos].lock_state == locked)
		return (srpl_size) - ((srpl_write_pos - srpl_read_pos) % srpl_size) - 1;
	else
		return (srpl_size) - ((srpl_write_pos - srpl_read_pos) % srpl_size);
}
