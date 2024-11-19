

#include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define structure for hash table
typedef struct HashTable {
    int capacity;
    Node** table;
} HashTable;

// Function to create a new linked list node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new hash table
HashTable* createHashTable(int capacity) {
    HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
    hashTable->capacity = capacity;
    hashTable->table = (Node**) malloc(capacity * sizeof(Node*));
    for (int i = 0; i < capacity; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Hash function to map values to key
int hashFunction(int key, int capacity) {
    return key % capacity;
}

// Function to insert a key into the hash table
void insert(HashTable* hashTable, int key) {
    int index = hashFunction(key, hashTable->capacity);
    Node* newNode = createNode(key);
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        Node* temp = hashTable->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at index %d\n", key, index);
}

// Function to remove a key from the hash table
void removeKey(HashTable* hashTable, int key) {
    int index = hashFunction(key, hashTable->capacity);
    Node* temp = hashTable->table[index];
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL) {
                hashTable->table[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Removed %d from index %d\n", key, index);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found\n", key);
}

// Function to search for a key in the hash table
int search(HashTable* hashTable, int key) {
    int index = hashFunction(key, hashTable->capacity);
    Node* temp = hashTable->table[index];
    while (temp != NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to display the hash table
void display(HashTable* hashTable) {
    for (int i = 0; i < hashTable->capacity; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable->table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int capacity = 7;
    HashTable* hashTable = createHashTable(capacity);

    insert(hashTable, 10);
    insert(hashTable, 20);
    insert(hashTable, 15);
    insert(hashTable, 7);
    insert(hashTable, 8);

    printf("\nHash Table with Chaining:\n");
    display(hashTable);

    printf("\nSearching for 15: %s\n", search(hashTable, 15) ? "Found" : "Not Found");

    removeKey(hashTable, 15);

    printf("Searching for 15: %s\n", search(hashTable, 15) ? "Found" : "Not Found");

    return 0;
}
