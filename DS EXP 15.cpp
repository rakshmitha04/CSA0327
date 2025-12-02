#include <stdio.h>

#define SIZE 10
int h[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        h[i] = -1;
}

void insert(int v) {
    int i = v % SIZE;
    int start = i;

    while (h[i] != -1) {
        i = (i + 1) % SIZE;
        if (i == start) return;   // table full
    }
    h[i] = v;
}

void search(int v) {
    int i = v % SIZE;
    int start = i;

    while (h[i] != -1) {
        if (h[i] == v) {
            printf("Found at index %d\n", i);
            return;
        }
        i = (i + 1) % SIZE;
        if (i == start) break;
    }
    printf("Not found\n");
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, h[i]);
}

int main() {
    int ch, x;
    init();

    while (1) {
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &x); insert(x); }
        else if (ch == 2) { scanf("%d", &x); search(x); }
        else if (ch == 3) display();
        else break;
    }
    return 0;
}

