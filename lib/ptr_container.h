/*
 * ptr_container.h
 *
 *  Created on: Jan 13, 2021
 *      Author: user
 */

#ifndef _PTR_CONTAINER_H_
#define _PTR_CONTAINER_H_

#define SRPL_READ_OK		0
#define SRPL_READ_LOCKED	1
#define SRPL_READ_EMPTY		2
#define SRPL_READ_UNLOCKED	3

#define SRPL_WRITE_OK		0
#define SRPL_WRITE_LOCKED	1
#define SRPL_WRITE_FULL		2
#define SRPL_WRITE_UNLOCKED	3

enum lock_state {
	unlocked = 0,
	locked
};

enum data_state {
	empty = 0,
	full
};

struct ptr_container {
	void	*data_ptr;
	enum	data_state data_state;
	enum	lock_state lock_state;
};

void srpl_init(void **ptr_list, size_t ptr_list_size);

int32_t srpl_read_get(void **ptr);
int32_t srpl_read_set(void);
int32_t srpl_read_cancel(void);
size_t srpl_read_size_get(void);

int32_t srpl_write_get(void **ptr);
int32_t srpl_write_set(void);
int32_t srpl_write_cancel(void);
size_t srpl_write_size_get(void);

#endif /* _PTR_CONTAINER_H_ */
