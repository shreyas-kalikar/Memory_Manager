# Memory-Management-System

README

Run the run_N_Times.sh script followed by N number of times you want to run it.

example:

``` ./run_N_Times.sh 10 ```

Memory Manager:

* This program calls getmem and freemem random times and the corresponding stats are printed. 

getmem mimics malloc
freemem mimics free

Reponsibilities:

Description of the freeList:

* We created a struct Block to act as our linked list nodes. Every Block in the freeList represents a free block of memory. Everytime a malloc call is made in getmem.c, that block is inserted into the freeList in sorted order by address. Then it is divided up for getmem to return a pointer to the memory. In freemem.c, we take the pointer to the memory passed in and subtract it by the header size to get to the address of the front of the block. We use this so that we can find the size of the block that was passed in. We insert the block in the freeList in sorted order depending on address, least to most. Then we loop through the entire list and combine all adjacent nodes.

NOTE: In our print_heap.c we interpreted length to mean length of the block, including header size. We used the block size + headerSize to compute this value.

Summary of Bench program:

* We ran our bench several times and through observing all the reports given, our code works very efficiently. Using different number of NTRIALS and other passed variables for testing, our code would run an average of 1000th of a second. Carefully viewing our average bytes per free block with the amount of free blocks it is consistently aquedate with the total size malloc'd. These results in our memory management show that it is making good use of memory.

Resources:

* [1] http://www.ravenbrook.com/project/mps/master/manual/html/guide/malloc.html

* [2] http://www.tutorialspoint.com/cprogramming/c_memory_management.htm

* [3] http://stackoverflow.com/questions/8800482/when-and-why-to-use-malloc
