
// get_mem_stats.c
//
// This method calculates all of the statistics used for the memory manager.

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "mem_impl.h"

// Passes in a total_size, total_free, and n_free_blocks
// Calculates the values passed in.
void get_mem_stats(uintptr_t* total_size, uintptr_t* total_free, uintptr_t* n_free_blocks) {
    *total_size = totalMalloced;
    *total_free = 0;
    *n_free_blocks = 0;
    Block * current = freeList;
    while (current != NULL) {
        *total_free += current->size;
        *n_free_blocks += 1;
        current = current->next;
    }
}
