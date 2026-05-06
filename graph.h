#ifndef GRAPH_H
#define GRAPH_H

// Komşu şehir düğümü
typedef struct CityNode {
    int city_id;
    int distance;
    struct CityNode* next;
} CityNode;

// Lojistik Grafı
typedef struct Graph {
    int num_vertices;
    CityNode** adj_lists;
} Graph;

Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest, int distance);
void BFS(Graph* graph, int start_vertex);
void printMemoryReportGraph(Graph* graph);

#endif