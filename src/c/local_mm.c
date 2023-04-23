
// Constants
#define PAGE_SIZE 4096 // Size of a page in bytes
#define MEMORY_SIZE (512 * 1024 * 1024) // Size of memory region in bytes

// Bitmap data structure
char memory_bitmap[MEMORY_SIZE / PAGE_SIZE / 8]; // One bit for each page

// Function to allocate a block of memory
void* allocate_memory(size_t size) {
    size_t num_pages = (size + PAGE_SIZE - 1) / PAGE_SIZE; // Round up to nearest page
    size_t start_page = 0;
    size_t free_pages = 0;
    for (size_t i = 0; i < MEMORY_SIZE / PAGE_SIZE; i++) {
        if (memory_bitmap[i / 8] & (1 << (i % 8))) {
            // Page is allocated, reset counters
            start_page = i + 1;
            free_pages = 0;
        } else {
            // Page is free, update counters
            if (free_pages == 0) {
                start_page = i;
            }
            free_pages++;
            if (free_pages == num_pages) {
                // Found a contiguous block of free pages, mark them as allocated
                for (size_t j = start_page; j < start_page + num_pages; j++) {
                    memory_bitmap[j / 8] |= (1 << (j % 8));
                }
                return (void*)(start_page * PAGE_SIZE);
            }
        }
    }
    // Out of memory
    return NULL;
}

// Function to deallocate a block of memory
void deallocate_memory(void* ptr, size_t size) {
    size_t num_pages = (size + PAGE_SIZE - 1) / PAGE_SIZE; // Round up to nearest page
    size_t start_page = (size_t)ptr / PAGE_SIZE;
    for (size_t i = start_page; i < start_page + num_pages; i++) {
        memory_bitmap[i / 8] &= ~(1 << (i % 8)); // Mark pages as free
    }
}

int main() {
    // Allocate a block of memory
    void* ptr = allocate_memory(1024);
    if (ptr == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    // Write some data to the allocated memory
    memset(ptr, 0x00, 1024);

    // Deallocate the block of memory
    deallocate_memory(ptr, 1024);

    return 0;
}

/*
There are several possible bugs that could be present in this code:

Memory size limitation: The code assumes a fixed memory size of 512 MB, which may not always be the case. If the actual memory size is less than this, then the code may not work correctly.

Integer overflow: The calculation for MEMORY_SIZE may overflow if the result is too large to fit in a size_t variable.

Alignment issues: The code assumes that PAGE_SIZE is a power of 2 and that memory allocation starts at a page boundary. If these assumptions are not met, the code may not work correctly.

Access outside of the memory region: The code does not perform any bounds checking on the memory region, which could lead to memory access errors if an invalid memory address is used.

Deallocating unallocated memory: The deallocate_memory function does not check if the memory block being deallocated was actually allocated previously, which could lead to freeing memory that was not actually allocated.

Multiple allocations: The code does not support multiple allocations, as it assumes that the memory region is continuous and does not keep track of previously allocated memory. If multiple allocations are made, they may overlap and corrupt each other.

Performance issues: The code performs a linear search through the memory bitmap for every allocation and deallocation, which could become slow for large memory regions or frequent allocations/deallocations.




*/
