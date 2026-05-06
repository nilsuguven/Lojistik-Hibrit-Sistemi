#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "graph.h"

int main() {
    printf("========== LOJISTIK HIBRIT SISTEMI (NILSU GUVEN) ==========\n\n");

    // 1. HASH TABLOSU HAZIRLIĞI
    printf(">>> Kargo Veritabanı Yükleniyor (Tip B Hash & Zincirleme)...\n");
    HashTable* ht = createHashTable();

    // Ödevde istenen: En az 5 veri girişi
    insertPackage(ht, "TRK9821", "Laptop - Ankara");
    insertPackage(ht, "TRK3452", "Kitap - Izmir");
    insertPackage(ht, "TRK1122", "Evrak - Istanbul");
    insertPackage(ht, "TRK9988", "Telefon - Bursa");
    insertPackage(ht, "TRK5566", "Tablet - Antalya");
    insertPackage(ht, "TRK4444", "Monitor - Adana"); // Çakışma simülasyonu için ekstra

    // 2. GRAF (LOJİSTİK AĞI) HAZIRLIĞI
    printf("\n>>> Lojistik Ağı Yükleniyor...\n");
    Graph* g = createGraph(6); // 0'dan 5'e kadar 6 şehir

    // Şehirler arası mesafeler ekleniyor
    addEdge(g, 0, 1, 120);
    addEdge(g, 0, 2, 250);
    addEdge(g, 1, 3, 80);
    addEdge(g, 2, 4, 150);
    addEdge(g, 3, 5, 300);
    addEdge(g, 4, 5, 100);

    // 3. BFS ALGORİTMASINI ÇALIŞTIRMA
    BFS(g, 0);

    // 4. BELLEK İZLEME RAPORU (Ödev Dosyası İçin Çıktı Üretir)
    printf("\n\n================ ODEV EK DOSYASI ICIN BELLEK RAPORU ================\n");
    printMemoryReportHashTable(ht);
    printMemoryReportGraph(g);
    printf("====================================================================\n");

    return 0;
}