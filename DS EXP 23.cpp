#include <stdio.h>
#define INF 9999
#define MAX 10

// Find the vertex with minimum distance
int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

// Dijkstra's algorithm
void dijkstra(int n, int graph[MAX][MAX], int src) {
    int dist[MAX], visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
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

    int src;
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    if (src < 0 || src >= n) {
        printf("Invalid source vertex!\n");
        return 1;
    }

    dijkstra(n, graph, src);

    return 0;
}

