#include <stdio.h>
#define N 5

int q[N], f = 0, r = -1;

void enq(int x){ if (r < N-1) q[++r] = x; }
void deq(){ if (f <= r) printf("Dequeued: %d\n", q[f++]); }
void disp(){ for (int i=f; i<=r; i++) printf("%d ", q[i]); printf("\n"); }

int main() {
    int c, x;
    while (1) {
        scanf("%d", &c);
        if (c == 1) { scanf("%d", &x); enq(x); }
        else if (c == 2) deq();
        else if (c == 3) disp();
        else break;
    }
}

