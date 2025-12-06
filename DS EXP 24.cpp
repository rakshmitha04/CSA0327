#include <stdio.h>
#define MAX 10
#define INF 9999

// Function to find the vertex with minimum key value
int minKey(int key[], int mstSet[], int n) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

// Prim's MST algorithm
void primMST(int n, int graph[MAX][MAX]) {
    int parent[MAX], key[MAX], mstSet[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        if (u == -1) break; // Safety check
        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int n;
    printf("Enter number of vertices (<= %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Number of vertices exceeds MAX limit!\n");
        return 1;
    }

    int graph[MAX][MAX];
    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(n, graph);

    return 0;
}

