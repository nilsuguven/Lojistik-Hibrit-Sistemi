#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 10 // Hash tablosu boyutu

// Kargo paketi düğümü (Zincirleme için 'next' pointer'ı içerir)
typedef struct PackageNode {
    char tracking_number[20];
    char package_info[50];
    struct PackageNode* next;
} PackageNode;

// Hash Tablosu
typedef struct HashTable {
    PackageNode* buckets[TABLE_SIZE];
} HashTable;

HashTable* createHashTable();
int hashFunctionTypeB(const char* tracking_number);
void insertPackage(HashTable* ht, const char* tracking_number, const char* info);
void printMemoryReportHashTable(HashTable* ht);

#endif