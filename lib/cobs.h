/*
 * cobs.h
 *
 *  Created on: Mar 1, 2021
 *      Author: user
 */

#ifndef COBS_H_
#define COBS_H_

void cobs_encode(uint8_t marker, const void *data_buf, size_t data_buf_len, void *enc_buf);
void cobs_decode(uint8_t marker, const void *encoded_buf, size_t encoded_buf_len, void *dec_buf);

#endif /* COBS_H_ */
