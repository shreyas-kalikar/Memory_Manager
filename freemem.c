// freemem.c
//
// Given block of used memory is returned back
// to the heap, which can be reused for a new
// purpose. Also combines free'd memory blocks
// if they are adjacent to one another, keeping
// them in sorted order.
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "mem_impl.h"

// Given block is restored back to the heap in sorted order by 
// memory address. If free'd memory blocks are adjacent 
// (touching one another) then they are combined into one block.
void freemem(void* p) {
    if (p == NULL) { // if given p is null does nothing
        return;
    }
    Block* blockInfo = p - headerSize;
    Block* current = freeList;
    // front case
    if (current != NULL && blockInfo < current) {
        blockInfo->next = current;	// links free list to end of given block
        freeList = blockInfo;	// given block is now the front of freeL
        return; // end of method
    }
    // check for current and current next, and compares current next address
    // with the given block address for sorting
    while (current != NULL && current->next != NULL && blockInfo > current->next) {
        current = current->next;
    }
    // end case, this means we went through entire list without
    // inserting block, so must be last in the list.
    if (current->next == NULL) {
        current->next = blockInfo;
        return;
    }
    blockInfo->next = current->next;
    current->next = blockInfo;
    // done with insertion, now for combing adjacent blocks
    current = freeList;
    Block* prev = freeList;	// not really needed just for assurance
    while (current != NULL && current->next != NULL) {
        if (((uintptr_t)current + (uintptr_t)current->size) + 16 == (uintptr_t)current->next) {
            current = combine(current, current->next);
            if (prev != freeList) {	// Ignores front case
                prev->next = current;
            } else {
                freeList = current;
            }
        } else {
            prev = current; // tracks one before current (as of now)
            current = current->next;
        }
    }
}

// takes in two adject block pointers and returns a combined version
//	with the size of the two blocks added
Block* combine(Block* firstBlock, Block* secondBlock) {
    Block* newBlock = firstBlock;
    newBlock->next = secondBlock->next;
    newBlock->size = firstBlock->size + secondBlock->size + headerSize;
    return newBlock;
}
