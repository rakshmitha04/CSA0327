#include <stdio.h>
int main() {
    int a[100], n, choice, pos, val, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: 
            printf("Enter position and value: ");
            scanf("%d %d", &pos, &val);
            for (i = n; i >= pos; i--)
                a[i] = a[i - 1];
            a[pos - 1] = val;
            n++;
            printf("Inserted.\n");
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            for (i = pos - 1; i < n - 1; i++)
                a[i] = a[i + 1];
            n--;
            printf("Deleted.\n");
            break;
        case 3: 
            printf("Array elements: ");
            for (i = 0; i < n; i++)
                printf("%d ", a[i]);
            printf("\n");
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}

