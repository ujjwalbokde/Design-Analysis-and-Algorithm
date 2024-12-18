#include <stdio.h>
#include <stdlib.h>

int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return parent[i] = find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int compareEdges(const void *a, const void *b) {
    return ((int *)a)[2] - ((int *)b)[2];
}

void kruskalMST(int edges[][3], int V, int E) {
    int parent[V];
    int rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }

    qsort(edges, E, sizeof(edges[0]), compareEdges);

    printf("Edges in the Minimum Spanning Tree (MST):\n");

    int mstWeight = 0;

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        if (find(parent, u) != find(parent, v)) {
            printf("%d -- %d == %d\n", u, v, weight);
            mstWeight += weight;

            unionSet(parent, rank, u, v);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int V = 4;
    int E = 5;

    int edges[5][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, V, E);

    return 0;
}
