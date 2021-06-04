/* 
Created by: Carbonell-Kiamtia, Maxim 
mjcarbon 
April 25th, 2021

Assignment 3: Sorting
CSE 13S, Computer Systems and C Programming 
UC Santa Cruz, Spring 2021

Description: This directory is for the purposes of sorting arrays/lists. We make use of bubble sort, shell sort, and a quick sort(w/ stack/queue)...    
*/
#include "sorting.h"
#include "bubble.h"
#include "queue.h"
#include "quick.h"
#include "shell.h"
#include "stack.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define OPTIONS "r:n:p:bsqQ"
int64_t printSize = 100; // Default print size should be 100 
int firstPrint = 0; 
uint32_t createArr(uint32_t *arr, uint32_t arrSize) { // function to create our array with a random seed. 
    for (uint32_t i = 0; i < arrSize; ++i) {
        arr[i] = random();
    }
    return 0;
}

int main(int argc, char **argv) {
    int opt = 0;
    uint32_t arrSize = 100; // Default array size is 100 
    int64_t seed = 13371453; // default seed 
    //THESE ARE THE DEFAULTS FOR SETTING UP AN ARRAY
    //WE CAN CANGE THESE IF SPECIFIED WITH -n and -r
    for (int i = 0; i < argc; i++) { // Handles arguments
        if (strcmp(argv[i], "-n") == 0) { // if user uses -n command then we need to change the size of the array
            arrSize = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-r") == 0) { // If user uses -r command then we need to seed the seed to specified number
            seed = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-p") == 0) { // If user uses -p command then we need to set the print size to specified number
            printSize = atoi(argv[i + 1]);
        }
    }

    srandom(seed); // INitialize random seed 
    uint32_t arr[arrSize];
    createArr(arr, arrSize); 
    uint32_t n = (sizeof(arr) / 4);
    uint32_t arrCopy[arrSize];
    for (uint32_t i = 0; i < arrSize; ++i) {
        arrCopy[i] = arr[i];
    }

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'b':
            printf("Bubble Sort\n");

            bubble_sort(arr, n);

            //RESET THE ARRAY AT THE VERY END JUST IN CASE WE DO ANOTHER SORT
            for (uint32_t i = 0; i < arrSize; ++i) {
                arr[i] = arrCopy[i];
            }
            break;
        case 's':
            printf("Shell Sort\n");
            shell_sort(arr, n);
            //RESET THE ARRAY AT THE VERY END JUST IN CASE WE DO ANOTHER SORT
            for (uint32_t i = 0; i < arrSize; ++i) {
                arr[i] = arrCopy[i];
            }

            break;
        case 'q':
            printf("Quick Sort (Stack)\n");
            quick_sort_stack(arr, n);
            //RESET THE ARRAY AT THE VERY END JUST IN CASE WE DO ANOTHER SORT
            for (uint32_t i = 0; i < arrSize; ++i) {
                arr[i] = arrCopy[i];
            }
            break;
        case 'Q':
            printf("Quick Sort (Queue)\n");
            quick_sort_queue(arr, n);
            //RESET THE ARRAY AT THE VERY END JUST IN CASE WE DO ANOTHER SORT
            for (uint32_t i = 0; i < arrSize; ++i) {
                arr[i] = arrCopy[i];
            }
            break;

        case 'i':
            //printf("THIS ADDED VALUE IS %s\n", optarg);
        default: break;
        }
    }
    return 0;
}
