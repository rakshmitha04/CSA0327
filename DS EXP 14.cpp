#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *l;
    struct Node *r;
};

/* Create a new node (casts malloc for older compilers like Dev-C++) */
struct Node* create(int v) {
    struct Node *n = (struct Node*) malloc(sizeof(struct Node));
    if (!n) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    n->data = v;
    n->l = n->r = NULL;
    return n;
}

void preorder(struct Node *t) {
    if (!t) return;
    printf("%d ", t->data);
    preorder(t->l);
    preorder(t->r);
}

void inorder(struct Node *t) {
    if (!t) return;
    inorder(t->l);
    printf("%d ", t->data);
    inorder(t->r);
}

void postorder(struct Node *t) {
    if (!t) return;
    postorder(t->l);
    postorder(t->r);
    printf("%d ", t->data);
}

/* Optional: free nodes to avoid memory leak (good practice) */
void free_tree(struct Node *t) {
    if (!t) return;
    free_tree(t->l);
    free_tree(t->r);
    free(t);
}

int main(void) {
    /* Build sample tree:
            1
           / \
          2   3
         / \
        4   5
    */
    struct Node *root = create(1);
    root->l = create(2);
    root->r = create(3);
    root->l->l = create(4);
    root->l->r = create(5);

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    free_tree(root);
    return 0;
}

