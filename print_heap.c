
// print_heap.c
//
// This method prints out the heap.

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "mem_impl.h"

// Passes in a file.
// Prints out to the file the address of every free block, and the the length of the block.
// NOTE: In the spec it said to print address of every free block and the length. We interpreted
// 		 this "length" to be our block size + our header size.
void print_heap(FILE* f) {
    Block* cur = freeList;
    int count = 0;
    while (cur != NULL) {
        count++;
        fprintf(f, "%p %p This is free block %d address and length\n", cur, (void*)cur->size + headerSize, count);
        cur = cur->next;
    }
}
