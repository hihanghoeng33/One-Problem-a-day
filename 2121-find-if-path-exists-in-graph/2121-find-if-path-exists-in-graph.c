#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* parent;
    int* rank;
} UnionFind;

UnionFind* createUnionFind(int n) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->parent = (int*)malloc(n * sizeof(int));
    uf->rank = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 1;
    }
    return uf;
}

int find(UnionFind* uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]); 
    }
    return uf->parent[x];
}

void unionSets(UnionFind* uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);
    
    if (rootX != rootY) {
        if (uf->rank[rootX] > uf->rank[rootY]) {
            uf->parent[rootY] = rootX;
        } else if (uf->rank[rootX] < uf->rank[rootY]) {
            uf->parent[rootX] = rootY;
        } else {
            uf->parent[rootY] = rootX;
            uf->rank[rootX]++;
        }
    }
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    if (source == destination) {
        return true;
    }
    
    UnionFind* uf = createUnionFind(n);
    

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        unionSets(uf, u, v);
    }
    
    bool result = (find(uf, source) == find(uf, destination));
    
    free(uf->parent);
    free(uf->rank);
    free(uf);
    
    return result;
}
