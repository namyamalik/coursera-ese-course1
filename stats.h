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
 * @file stats.c 
 * @brief Header file for finding statistics of an array, printing array, sorting array
 * @author Namya Malik
 * @date June 2020
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array including minimum, maximum, mean, and median
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return N/A
 */
void print_statistics(unsigned char* data_array, unsigned int array_size);


/**
 * @brief given an array of data and a length, prints the array to the screen
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 * 
 * @return N/A
 */
void print_array(unsigned char* data_array, unsigned int array_size);


/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return An unsigned int result from the function
 */
int find_median(unsigned char* data_array, unsigned int array_size);


/**
 * @brief Given an array of data and a length, returns the mean value
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return An unsigned int result from the function
 */
int find_mean(unsigned char* data_array, unsigned int array_size);


/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return An unsigned int result from the function
 */
int find_maximum(unsigned char* data_array, unsigned int array_size);


/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return An unsigned int result from the function
 */
int find_minimum(unsigned char* data_array, unsigned int array_size);


/**
 * @brief <given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value)>
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return N/A
 */
void sort_array(unsigned char* data_array, unsigned int array_size);

#endif /* __STATS_H__ */
