#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_SLOT -1

// Structure for the hash table
typedef struct {
    int* table;
    int capacity;
    int size;
} HashTableLinearProbing;

// Hash function to calculate index
int hashFunction(int key, int capacity) {
    return key % capacity;
}

// Function to create and initialize the hash table
HashTableLinearProbing* createHashTable(int capacity) {
    HashTableLinearProbing* ht = (HashTableLinearProbing*)malloc(sizeof(HashTableLinearProbing));
    ht->capacity = capacity;
    ht->size = 0;
    ht->table = (int*)malloc(capacity * sizeof(int));
    for (int i = 0; i < capacity; i++)
        ht->table[i] = EMPTY_SLOT; // EMPTY_SLOT indicates an empty slot
    return ht;
}

// Function to insert a key using linear probing
void insert(HashTableLinearProbing* ht, int key) {
    if (ht->size == ht->capacity) {
        printf("Hash table is full!\n");
        return;
    }
    int index = hashFunction(key, ht->capacity);
    while (ht->table[index] != EMPTY_SLOT) {
        index = (index + 1) % ht->capacity; // Linear probing
    }
    ht->table[index] = key;
    ht->size++;
    printf("Inserted %d at index %d\n", key, index);
}

// Function to search for a key
bool search(HashTableLinearProbing* ht, int key) {
    int index = hashFunction(key, ht->capacity);
    for (int i = 0; i < ht->capacity; i++) {
        int probeIndex = (index + i) % ht->capacity;
        if (ht->table[probeIndex] == key)
            return true;
        if (ht->table[probeIndex] == EMPTY_SLOT)
            return false;
    }
    return false;
}

// Function to display the hash table
void display(HashTableLinearProbing* ht) {
    for (int i = 0; i < ht->capacity; i++) {
        if (ht->table[i] != EMPTY_SLOT)
            printf("Index %d: %d\n", i, ht->table[i]);
        else
            printf("Index %d: NULL\n", i);
    }
}

// Main function
int main() {
    HashTableLinearProbing* ht = createHashTable(7); // Initialize hash table with size 7
    insert(ht, 10);
    insert(ht, 20);
    insert(ht, 15);
    insert(ht, 7);
    insert(ht, 8);

    printf("\nHash Table with Linear Probing:\n");
    display(ht);

    printf("\nSearching for 15: %s\n", search(ht, 15) ? "Found" : "Not Found");

    // Free allocated memory
    free(ht->table);
    free(ht);
    return 0;
}