#include <stdio.h>

int partition(int a[], int l, int r) {
    int p = a[r], i = l - 1, t;
    for (int j = l; j < r; j++) {
        if (a[j] < p) {
            i++;
            t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    t = a[i+1]; a[i+1] = a[r]; a[r] = t;
    return i + 1;
}

void quicksort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quicksort(a, l, p-1);
        quicksort(a, p+1, r);
    }
}

int main() {
    int a[50], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    quicksort(a, 0, n-1);

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}

