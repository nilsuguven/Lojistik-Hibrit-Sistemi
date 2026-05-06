#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for(int i = 0; i < TABLE_SIZE; i++) {
        ht->buckets[i] = NULL;
    }
    printf("[BELLEK] Hash Tablosu Ana Dizisi Olusturuldu. Adres: %p\n", (void*)ht);
    return ht;
}

// TİP B HASH FONKSİYONU: Takip numarasındaki karakterlerin ASCII toplamının modunu alır.
int hashFunctionTypeB(const char* tracking_number) {
    int sum = 0;
    for(int i = 0; tracking_number[i] != '\0'; i++) {
        sum += tracking_number[i];
    }
    return sum % TABLE_SIZE;
}

void insertPackage(HashTable* ht, const char* tracking_number, const char* info) {
    int index = hashFunctionTypeB(tracking_number);

    PackageNode* newNode = (PackageNode*)malloc(sizeof(PackageNode));
    strcpy(newNode->tracking_number, tracking_number);
    strcpy(newNode->package_info, info);

    // Zincirleme (Chaining) - Yeni elemanı listenin başına ekliyoruz
    newNode->next = ht->buckets[index];
    ht->buckets[index] = newNode;

    printf("[BELLEK] Yeni Kargo Eklendi '%s' -> Node Adresi: %p | Atanan İndeks: %d\n", tracking_number, (void*)newNode, index);
}

// BELLEK İZLEME RAPORU İÇİN (Pointer Bağlantıları Şeması)
void printMemoryReportHashTable(HashTable* ht) {
    printf("\n--- HASH TABLOSU (ZINCIRLEME) BELLEK SEMASI ---\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        printf("Index [%d]: ", i);
        PackageNode* temp = ht->buckets[i];
        if(temp == NULL) {
            printf("NULL\n");
        } else {
            while(temp) {
                printf("[%s | Adres: %p] -> ", temp->tracking_number, (void*)temp);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}