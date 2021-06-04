#include "shell.h"

#include "gaps.h"
#include "sorting.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void shell_sort(uint32_t *A, uint32_t n) { // This logic was borrowed from the homework pdf...
    uint32_t og_length = n;
    uint64_t moves = 0;
    uint64_t compares = 0;
    for (uint32_t gap = 0; gap < 102; ++gap) {
        if (gaps[gap] < n) {
            for (uint32_t i = gaps[gap]; i < n; ++i) {
                uint32_t j = i;
                uint32_t temp = *(A + i);
                bool first_condition = false;
                //printf("J %d AND I %d AND GAP %d and TEMP %d\n", j, i, gaps[gap], temp);
                compares += 1;
                if ((j >= gaps[gap]) && (temp < *(A + (j - gaps[gap])))) {
                    first_condition = true;
                }
                while (first_condition) {
                    if ((j >= gaps[gap]) && (temp < *(A + (j - gaps[gap])))) {
                        first_condition = true;
                    } else {
                        break;
                    }
                    moves += 2;
                    *(A + j) = *(A + (j - gaps[gap]));
                    j -= gaps[gap];
                }
                *(A + j) = temp;
                moves += 2;
            }
        }
    }
    printf("%d elements, %lu moves, %lu compares\n", og_length, moves, compares);
    if (printSize > og_length) {
        for (uint32_t i = 0; i < og_length; i += 1) {
            if (i % 5 == 0 && i != 0){
            	printf("\n%d	", A[i]);
            }
            else{
            	printf("%d	", A[i]);
            }
        }
        printf("\n");
    } else {
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
