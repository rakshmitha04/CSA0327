#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_begin(int v) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->next = head;
    head = n;
}

void insert_end(int v) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->next = NULL;

    if (head == NULL) {
        head = n;
    } else {
        struct Node *t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
}

void delete_value(int v) {
    struct Node *t = head, *prev = NULL;

    while (t != NULL && t->data != v) {
        prev = t;
        t = t->next;
    }

    if (t == NULL) {
        printf("Value not found\n");
        return;
    }

    if (prev == NULL)
        head = t->next;
    else
        prev->next = t->next;

    free(t);
    printf("Deleted %d\n", v);
}

void display() {
    struct Node *t = head;
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, x;

    while (1) {
        printf("\n1.Insert Begin\n2.Insert End\n3.Delete\n4.Display\n5.Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            scanf("%d", &x);
            insert_begin(x);
        }
        else if (ch == 2) {
            scanf("%d", &x);
            insert_end(x);
        }
        else if (ch == 3) {
            scanf("%d", &x);
            delete_value(x);
        }
        else if (ch == 4) {
            display();
        }
        else if (ch == 5) {
            break;
        }
        else {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}

