/**
 * @file data.c
 * @brief Basic data manipulation
 *
 * This implementation file provides functions for basic data
 * manipulation.
 *
 * @author Namya Malik
 * @date July 2020
 *
 */

#include <stdint.h>
#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
	uint8_t i = 0;
	uint8_t rem;
	uint8_t negative = 0;
	
	if (base < 2 || base > 16){
		return 0;
	}
	
	if (data == 0){
		*ptr = 48;
	}
	 
	if (data < 0){
		negative = 1;
		data = -data;
	}
	while (data != 0){
		rem = data % base;
		if (rem <= 9){
			*(ptr + i) = rem + '0';
		}
		else{
			*(ptr + i) = rem - 10 + 'A';
		}
		i++;
		data = data/base;
	}
	
	if (negative == 1){
		*(ptr + i) = '-';
		i++;
	}
	
	my_reverse(ptr, i);
	*(ptr + i) = '\0';
	return i;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
	int i;
	int32_t dst = 0;
	uint8_t negative = 0;
	
	if (base < 2 || base > 16){
		return 0;
	}
	
	if (*ptr == 0){
		return 0;
	}
	
	if (*ptr == '-'){
		negative = 1;
	}
	
	my_reverse(ptr, digits);
	
	if (negative == 0){
		for (i = 0; i < digits; i++){
			if (*(ptr + i) <= '9'){
				dst += power(base, i) * (*(ptr + i) - '0');
			}
			else{
				dst += power(base, i) * (*(ptr + i) - 'A' + 10);
			}
		}
	}
	
	else if (negative == 1){
		for (i = 0; i < (digits -1); i++){
			if ( *(ptr + i) <= '9'){
				dst += power(base, i) * (*(ptr + i) - '0');
			}
			else{
				dst += power(base, i) * (*(ptr + i) - 'A' + 10);
			}
		}
	dst = -dst;
	}
	my_reverse(ptr, digits);
	return dst;
}

uint32_t power(uint32_t base, uint8_t factor){
	int i;
	uint32_t val = 1;
	for (i = 0; i < factor; i++){
		val *= base;
	}
	return val;
}
