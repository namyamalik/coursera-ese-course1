/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves data of a certain length from source to destination
 *
 * Given two pointers to an 8-bit int array, this will move a block
 * of data (which is of a certain length) from one pointer to the other. 
 *
 * @param src Pointer to 8-bit int array
 * @param dst Pointer to 8-bit int array
 * @param length Number of elements to move
 *
 * @return Pointer to 8-bit int array
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies data of a certain length from source to destination
 *
 * Given two pointers to an 8-bit int array, this will copy a block
 * of data (which is of a certain length) from one pointer to the other.
 *
 * @param src Pointer to 8-bit int array
 * @param dst Pointer to 8-bit int array
 * @param length Number of elements to copy
 *
 * @return Pointer to 8-bit int array
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets the data in a source memory location to a given value
 *
 * Given a pointer to an 8-bit int source array, this will set the data 
 * of a certain length to a given value.
 *
 * @param src Pointer to 8-bit int source array
 * @param length Number of elements to change
 * @param value 8-bit int to change the data to
 *
 * @return Pointer to 8-bit int array
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets the data in a source memory location to zero
 *
 * Given a pointer to an 8-bit int source array, this will set the data
 * of a certain length to zero.
 *
 * @param src Pointer to 8-bit int source array
 * @param length Number of elements to set
 *
 * @return Pointer to 8-bit int array
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the data in a source memory location
 *
 * Given a pointer to an 8-bit int source array, this will reverse the 
 * data of a certain length.
 *
 * @param src Pointer to 8-bit int source array
 * @param length Number of elements to reverse
 *
 * @return Pointer to 8-bit int array
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Dynamically allocates memory to a pointer
 *
 * Given the length of bytes to allocate, this will allocate the
 * memory to a pointer that points to an array of ints.
 *
 * @param length Number of bytes to allocate
 *
 * @return Pointer to 32-bit int array
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Deallocates memory to a pointer
 *
 * Given a pointer to an 32-bit int source array, this will deallocate the
 * memory of the data array.
 *
 * @param src Pointer to 8-bit int source array
 *
 * @return none
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
