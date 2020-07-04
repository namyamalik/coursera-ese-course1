/**
 * @file data.h
 * @brief Basic data manipulation
 *
 * This header file provides some functions for basic data
 * manipulation.
 *
 * @author Namya Malik
 * @date July 2020
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Converts data from standard integer type to ASCII string
 *
 * Given a signed 32-bit int and a pointer to an 8-bit int array,
 * this fxn will convert the 32-bit int into its corresponding ASCII
 * string (using the given base value) and then copy the converted 
 * character string to the given 8-bit int pointer.
 *
 * @param data 32-bit int that gets converted
 * @param ptr Pointer to 8-bit int
 * @param base 32-bit int used as the value of the base to convert to
 *
 * @return 8-bit int representing the length of the pointer
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts data from ASCII string to integer type
 *
 * Given a pointer to an 8-bit int array (that represents the character
 * set), this fxn will convert a certain number of digits in the 
 * character set into its corresponding int type (using the given base value).
 *
 * @param ptr Pointer to 8-bit int
 * @param digits 8-bit int data
 * @param base 32-bit int used as the value of the base
 *
 * @return 8-bit int representing the length of the pointer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
