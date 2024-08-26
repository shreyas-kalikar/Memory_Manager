
// mem.h
 
#ifndef MEM_H
#define MEM_H

void* getmem(uintptr_t size);
void freemem(void* p);
void get_mem_stats(uintptr_t* total_size, uintptr_t* total_free, uintptr_t* n_free_blocks);
void print_heap(FILE * f);

#endif
