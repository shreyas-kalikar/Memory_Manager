
// mem_impl.h

#define mallocSize 10016 // Default malloc size
#define headerSize 16 // Header Size
#define thresh 64 // Threshold value

// Our struct that is used as blocks in the freeList.
struct block {
	uintptr_t size;
	struct block* next;
};
 
typedef struct block Block;

Block* freeList; // free list
int totalMalloced; // total amount of bytes malloced

Block* combine (Block* firstBlock, Block* secondBlock);
Block* divide (Block* blocky, uintptr_t size);