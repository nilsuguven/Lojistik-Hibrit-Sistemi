#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = vertices;
    graph->adj_lists = (CityNode**)malloc(vertices * sizeof(CityNode*));

    for(int i = 0; i < vertices; i++) {
        graph->adj_lists[i] = NULL;
    }
    printf("[BELLEK] Graf Olusturuldu. Adres: %p\n", (void*)graph);
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int distance) {
    CityNode* newNode = (CityNode*)malloc(sizeof(CityNode));
    newNode->city_id = dest;
    newNode->distance = distance;

    newNode->next = graph->adj_lists[src];
    graph->adj_lists[src] = newNode;

    printf("[BELLEK] Rota Eklendi (Sehir %d -> Sehir %d). Node Adresi: %p\n", src, dest, (void*)newNode);
}

// BFS - SIĞ ÖNCELİKLİ ARAMA ALGORİTMASI
void BFS(Graph* graph, int start_vertex) {
    int visited[100] = {0}; // Maksimum 100 şehir varsayımıyla
    int queue[100];
    int front = 0, rear = 0;

    visited[start_vertex] = 1;
    queue[rear++] = start_vertex;

    printf("\n--- GRAF BFS ROTA GEZINMESI (Baslangic: Sehir %d) ---\nRota: ", start_vertex);

    while(front < rear) {
        int current_city = queue[front++];
        printf("%d ", current_city);

        CityNode* temp = graph->adj_lists[current_city];
        while(temp) {
            int adj_city = temp->city_id;
            if(visited[adj_city] == 0) {
                visited[adj_city] = 1;
                queue[rear++] = adj_city;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// BELLEK İZLEME RAPORU İÇİN (Graf Adjacency List Şeması)
void printMemoryReportGraph(Graph* graph) {
    printf("\n--- GRAF (LOJISTIK AGI) BELLEK SEMASI ---\n");
    for(int i = 0; i < graph->num_vertices; i++) {
        printf("Sehir %d -> ", i);
        CityNode* temp = graph->adj_lists[i];
        if(temp == NULL) {
            printf("NULL\n");
        } else {
            while(temp) {
                printf("[Hedef: %d, Mesafe: %d | Adres: %p] -> ", temp->city_id, temp->distance, (void*)temp);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}