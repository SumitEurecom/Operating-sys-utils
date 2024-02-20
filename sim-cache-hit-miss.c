#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 4

typedef struct {
    int valid;
    int tag;
    int data;
} CacheLine;

typedef struct {
    CacheLine lines[CACHE_SIZE];
} Cache;

void initializeCache(Cache *cache) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache->lines[i].valid = 0;
    }
}

int accessMemory(Cache *cache, int address) {
    int index = address % CACHE_SIZE;
    int tag = address / CACHE_SIZE;

    if (cache->lines[index].valid && cache->lines[index].tag == tag) {
        // Cache hit
        printf("Cache hit for address %d\n", address);
        return cache->lines[index].data;
    } else {
        // Cache miss
        printf("Cache miss for address %d\n", address);

        // Simulate fetching data from memory and updating the cache
        cache->lines[index].valid = 1;
        cache->lines[index].tag = tag;
        cache->lines[index].data = rand();  // Simulating data from memory

        return cache->lines[index].data;
    }
}

int main() {
    Cache cache;
    initializeCache(&cache);

    // Simulate memory accesses
    for (int i = 0; i < 10; i++) {
        int address = rand() % 20;  // Simulating different memory addresses
        int data = accessMemory(&cache, address);
        // Use the 'data' variable as needed (for example, printing it)
        printf("Data read from memory: %d\n", data);
    }

    return 0;
}
