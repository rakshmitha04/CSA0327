#include <stdio.h>

#define MAX 10

// DFS function
void dfs(int n, int adj[MAX][MAX], int visited[MAX], int u) {
    visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(n, adj, visited, v);
        }
    }
}

int main() {
    int n;
    printf("Enter number of vertices (<= %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Number of vertices exceeds MAX limit!\n");
        return 1;
    }

    int adj[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int visited[MAX] = {0};

    int start;
    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting node!\n");
        return 1;
    }

    printf("DFS Traversal starting from node %d: ", start);
    dfs(n, adj, visited, start);
    printf("\n");

    return 0;
}

