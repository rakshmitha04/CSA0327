#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Queue implementation
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = x;
    if (front == -1) front = 0;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

// BFS function
void bfs(int n, int adj[MAX][MAX], int start) {
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from node %d: ", start);

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                enqueue(v);
                visited[v] = 1;
            }
        }
    }
    printf("\n");
}

// Main function
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

    int start;
    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting node!\n");
        return 1;
    }

    bfs(n, adj, start);

    return 0;
}

