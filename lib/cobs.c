/*
 * cobs.c
 *
 *  Created on: Mar 1, 2021
 *      Author: user
 */


static size_t cobs_marker_find(uint8_t marker, size_t start_index, const void *data_buf, size_t data_buf_len)
{
	if (start_index >= data_buf_len)
		return 0;

	size_t cur_index = start_index;

	for (; cur_index < data_buf_len; ++cur_index) {
		if (((uint8_t*)data_buf)[cur_index] == marker)
			return cur_index - start_index;
	}
	return cur_index - start_index;
}

void cobs_encode(uint8_t marker, const void *data_buf, size_t data_buf_len, void *enc_buf)
{
	size_t out_index = 0;
	((uint8_t*)enc_buf)[out_index++] = marker;
	size_t in_index = 0;
	((uint8_t*)enc_buf)[out_index++] = cobs_marker_find(marker, in_index, data_buf, data_buf_len) + 1;
	for (; in_index < data_buf_len; ++in_index, ++out_index) {
		if (((uint8_t*)data_buf)[in_index] != marker)
			((uint8_t*)enc_buf)[out_index] = ((uint8_t*)data_buf)[in_index];
		else {
			if (in_index == (data_buf_len - 1)) {
				((uint8_t*)enc_buf)[out_index++] = 0x01;
				((uint8_t*)enc_buf)[out_index] = marker;
				return;
			} else {
				((uint8_t*)enc_buf)[out_index] = cobs_marker_find(marker, in_index + 1, data_buf, data_buf_len) + 1;
			}
		}
	}
	((uint8_t*)enc_buf)[out_index] = marker;
}

void cobs_decode(uint8_t marker, const void *encoded_buf, size_t encoded_buf_len, void *dec_buf)
{
	if (((uint8_t*)encoded_buf)[0] != marker || ((uint8_t*)encoded_buf)[encoded_buf_len - 1] != marker)
		return;

	size_t in_index = 1;
	size_t out_index = 0;
	size_t copy_count;

	copy_count = ((uint8_t*)encoded_buf)[in_index++] - 1;

	for (; in_index < encoded_buf_len; ++in_index) {

		if (copy_count == 0 && ((uint8_t*)encoded_buf)[in_index] == marker)
			return;

		for (; copy_count != 0; copy_count--, in_index++, out_index++)
			((uint8_t*)dec_buf)[out_index] = ((uint8_t*)encoded_buf)[in_index];

		((uint8_t*)dec_buf)[out_index++] = marker;

		copy_count = ((uint8_t*)encoded_buf)[in_index] - 1;

		if (((uint8_t*)encoded_buf)[in_index + 1] == marker)
			return;
	}
}
