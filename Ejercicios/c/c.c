/*
 * c.c
 *
 *  Created on: Apr 6, 2022
 *      Author: gianfranco
 */


#include "c.h"


void zeros(uint32_t *p, uint32_t size) {
   for (uint32_t i = 0; i < size; i++) {
      p[i] = 0;
   }
}

void dot_product_32(uint32_t *in, uint32_t *out, uint32_t size, uint32_t k) {
   for (uint32_t i = 0; i < size; i++) {
      out[i] = k * in[i];
   }
}

void dot_product_16(uint16_t *in, uint16_t *out, uint32_t size, uint16_t k) {
   for (uint32_t i = 0; i < size; i++) {
      out[i] = k * in[i];
   }
}

void dot_product_12(uint16_t *in, uint16_t *out, uint32_t size, uint16_t k) {
   for (uint32_t i = 0; i < size; i++) {
      out[i] = k * in[i];

      if (out[i] > 0xfff) {
         out[i] = 0xfff;
      }
   }
}

void window_filter(uint16_t *in, uint16_t *out, uint32_t size) {
   for (uint32_t i = 0; i < size; i++) {
      uint32_t sum = 0;
      for (uint32_t j = 0; j < 10; j++) {
         sum += in[(i + j) % size];
      }

      out[i] = sum / 10;
   }
}

void pack_32_to_16(int32_t *in, int16_t *out, uint32_t size) {
   for (uint32_t i = 0; i < size; i++) {
      out[i] = (int16_t) (0x0000FFFF & (in[i] >> 16));
   }
}

int32_t max(int32_t *in, uint32_t size) {
   int32_t max_index = 0;
   for (uint32_t i = 1; i < size; i++) {
      if (in[i] > in[max_index]) {
         max_index = i;
      }
   }

   return max_index;
}

void downsample(int32_t *in, int32_t *out, uint32_t size, uint32_t n) {
   uint32_t c = 0;
   uint32_t j = 0;
   for (uint32_t i = 0; i < size; i++) {
      if (c == n) {
         c = 0;
         continue;
      }
      out[j] = in[i];
      j++;
      c++;
   }
}

void reverse(uint16_t *in, uint32_t size) {
   for (uint32_t i = 0; i < size / 2; i++) {
      uint16_t temp = in[i];
      in[i] = in[size - i - 1];
      in[size - i - 1] = temp;
   }
}

void echo(int16_t *in, int16_t *out, uint32_t size) {
   for (uint32_t i = 0; i < size; i++) {
      if (i < 882) {
         out[i] = in[i];
      } else {
         out[i] = in[i] + in[i - 882] / 2;
      }
   }
}

