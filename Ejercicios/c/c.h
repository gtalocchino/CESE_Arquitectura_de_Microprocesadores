/*
 * c.h
 *
 *  Created on: Apr 6, 2022
 *      Author: gianfranco
 */

#ifndef C_H_
#define C_H_


#include "inttypes.h"


/**
 * @brief Resets an input array of 32-bit integers to zero.
 *
 * @param[in] p Pointer to the array.
 * @param[in] size Size of the array.
 *
 */
void zeros(uint32_t *p, uint32_t size);

/**
 * @brief Performs dot product with 32-bit unsigned integers.
 *
 * @param[in] in Pointer to the input array 
 * @param[out] out Pointer to the output array
 * @param[in] size Array size
 * @param[in] k Scalar value
 *
 */
void dot_product_32(uint32_t *in, uint32_t *out, uint32_t size, uint32_t k);

#endif /* C_H_ */
