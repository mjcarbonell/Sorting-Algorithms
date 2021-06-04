#include "bubble.h"
#include "sorting.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void bubble_sort(uint32_t *A, uint32_t n) { // This logic was borrowed from the homework pdf...
    uint32_t og_length = n;
    uint64_t moves = 0; //Variables to track the moves and compares
    uint64_t compares = 0;
    bool swapped = true;

    while (swapped == true) {
        swapped = false;
        for (uint32_t i = 1; i < n; i += 1) {
            compares += 1; // We are comparing a pair of elements here... 
            if (*(A + i) < *(A + (i - 1))) {
                uint32_t temp_first = *(A + i);
                uint32_t temp_second = *(A + (i - 1));
                *(A + i) = temp_second;
                *(A + (i - 1)) = temp_first;
                swapped = true;
                moves += 3; // WE are moving elements into temporary variables and back in for a total of 3 moves 
            }
        }
        n -= 1;
    }

    printf("%d elements, %lu moves, %lu compares\n", og_length, moves, compares);

    if (printSize > og_length) { // If our length of elements is less than the printSize then we just need to print the amount we have 
        for (uint32_t i = 0; i < og_length; i += 1) {
            if (i % 5 == 0 && i != 0){
            	printf("\n%d	", A[i]);
            }
            else{
            	printf("%d	", A[i]);
            }
        }
        printf("\n");
    } else { // If the length is greater than the specified print size then we limit our printing to the print size 
        for (uint32_t i = 0; i < printSize; i += 1) {
            if (i % 5 == 0 && i != 0){
            	printf("\n%d	", A[i]);
            }
            else{
            	printf("%d	", A[i]);
            }
        }
        printf("\n");
    }
    return;
}





















