Maxim Joel Carbonell-Kiamtia
mjcarbon
Spring 2021
Assignment 

---------------------
DESCRIPTION
Description: This directory is for the purposes of sorting arrays/lists. We make use of bubble sort, shell sort, and a quick sort(w/ stack/queue). 

1. Enter "make" in the terminal
2. Enter "./sorting -[INSERT COMMANDs HERE]" commands can be -b for bubble sort, -s for shell sort, -q for quick sort w/ stack, -Q for quick sort w/ queue... If user would like to specificy array size they must use -n [INSERT ARRAY SIZE], printSize use -p [INSERT PRINT SIZE], seed for random numbers -r [INSERT RANDOM NUMBERS]... 
---------------------
FILES
DESIGN.pdf
WRITEUP.pdf
Makefile
README.md
bubble.c
bubble.h
shell.c
shell.h
quick.c
quick.h
stack.c
stack.h
queue.c
queue.h
gaps.h
stats.h
sorting.c
sorting.h
-----------------------
bubble.c contains the c program to perform all of the logic needed to sort an array using a bubble sort.

shell.c contains the c program to perform all of the logic needed to sort an array using a shell sort.
 
quick.c contains the c program to perform all of the logic needed to sort an array using a quick sort w/ a queue and stack.

stack.c contaisn the c program that quick.c relies on to sort an array with a stack.

queue.c contains the c program that quick.c relies on to sort an array with a queue.

sorting.c contains the c program that allows the user to specify commands and circumstances for the sorting. 
DESIGN.pdf contains a walkthrough or behind the scenes process to create or recreate this directory. 

WRITEUP.pdf is an analysis of the results of the program. 
---------------------


