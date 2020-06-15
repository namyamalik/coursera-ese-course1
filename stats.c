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
 * @brief Find statistics of an array, print array, sort array
 * @author Namya Malik
 * @date June 2020
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

	// sample array for testing
	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  	// call some functions on array 
	print_array(test, SIZE);
  	print_statistics(test, SIZE);
  	sort_array(test, SIZE);

  	return 0;
}

// print out statistics of array: min, max, mean, median
void print_statistics(unsigned char* data_array, unsigned int array_size) {
	int min = find_minimum(data_array, array_size);
  	int max = find_maximum(data_array, array_size);
  	int mean = find_mean(data_array, array_size);
  	int median = find_median(data_array, array_size);
  	printf("\nPrinting statistics: ");
  	printf("Min: %d; Max: %d; Mean: %d; Median: %d\n", min, max, mean, median);
}

// print out array elements
void print_array(unsigned char* data_array, unsigned int array_size) {
  	printf("\nPrinting array: [ ");
  	for (int i = 0; i < array_size; i++) {
    	printf("%d ", data_array[i]);
  	}
  	printf("]\n");
}

// return median value of array elements
int find_median(unsigned char* data_array, unsigned int array_size) {
  	if (array_size % 2 == 0) {
    	int left = data_array[array_size / 2];
    	int right = data_array[(array_size / 2) - 1];
    	int median = (left + right) / 2;
    	return median;
  	}
  	else {
    	int median = data_array[(array_size / 2) - 1];
    	return median;
  	}
}

// return mean value of array elements
int find_mean(unsigned char* data_array, unsigned int array_size) {
	int sum = 0;
  	for (int i = 0; i < array_size; i++) {
  		sum = sum + data_array[i]; 
  	}
  	int mean = sum / array_size;
  	return mean;
}

// return maximum value of array elements
int find_maximum(unsigned char* data_array, unsigned int array_size) {
	int max = data_array[0];
  	for (int i = 0; i < array_size; i++) {
  		if (data_array[i] > max) {
			max = data_array[i];
		}
  	}
  	return max;
}

// return minimum value of array elements
int find_minimum(unsigned char* data_array, unsigned int array_size) {
	int min = data_array[0];
  	for (int i = 0; i < array_size; i++) {
		if (data_array[i] < min) {
			min = data_array[i];
        }
  	}
  	return min;
}

// sort array in decreasing order and print the sorted array
void sort_array(unsigned char* data_array, unsigned int array_size) {
  	printf("\nSorting array in decreasing order...\n");
	for (int i = 0; i < array_size; i++) {
		for (int j = i + 1; j < array_size; j++) {	
			if (data_array[j] > data_array[i]) {
				int temp = data_array[i];
				data_array[i] = data_array[j];    
				data_array[j] = temp;
			}
  		}
	}
	print_array(data_array, array_size);
}
