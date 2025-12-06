#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key, height;
    struct Node *l, *r;
};
int max(int a,int b){ return (a>b)?a:b; }
int height(struct Node* n){ return n? n->height : 0; }

struct Node* newNode(int key){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->key = key; n->l = n->r = NULL; n->height = 1;
    return n;
}
struct Node* rightRotate(struct Node* y){
    struct Node* x = y->l;
    struct Node* T2 = x->r;
    x->r = y; y->l = T2;
    y->height = max(height(y->l),height(y->r))+1;
    x->height = max(height(x->l),height(x->r))+1;
    return x;
}
struct Node* leftRotate(struct Node* x){
    struct Node* y = x->r;
    struct Node* T2 = y->l;
    y->l = x; x->r = T2;
    x->height = max(height(x->l),height(x->r))+1;
    y->height = max(height(y->l),height(y->r))+1;
    return y;
}
int getBalance(struct Node* n){ return n? height(n->l)-height(n->r) : 0; }
struct Node* insert(struct Node* node, int key){
    if(!node) return newNode(key);
    if(key<node->key) node->l = insert(node->l,key);
    else if(key>node->key) node->r = insert(node->r,key);
    else return node; 
    node->height = 1 + max(height(node->l), height(node->r));
    int balance = getBalance(node);
    if(balance>1 && key<node->l->key) return rightRotate(node); 
    if(balance<-1 && key>node->r->key) return leftRotate(node); 
    if(balance>1 && key>node->l->key){ node->l=leftRotate(node->l); return rightRotate(node); } 
    if(balance<-1 && key<node->r->key){ node->r=rightRotate(node->r); return leftRotate(node); } 

    return node;
}
struct Node* minValueNode(struct Node* node){
    struct Node* current = node;
    while(current->l) current = current->l;
    return current;
}
struct Node* deleteNode(struct Node* root, int key){
    if(!root) return root;
    if(key<root->key) root->l = deleteNode(root->l,key);
    else if(key>root->key) root->r = deleteNode(root->r,key);
    else {
        if(!root->l || !root->r){
            struct Node* temp = root->l?root->l:root->r;
            if(!temp){ free(root); return NULL; }
            else { *root = *temp; free(temp); }
        } else {
            struct Node* temp = minValueNode(root->r);
            root->key = temp->key;
            root->r = deleteNode(root->r,temp->key);
        }
    }
    root->height = 1 + max(height(root->l), height(root->r));
    int balance = getBalance(root);
    if(balance>1 && getBalance(root->l)>=0) return rightRotate(root);
    if(balance>1 && getBalance(root->l)<0){ root->l=leftRotate(root->l); return rightRotate(root); }
    if(balance<-1 && getBalance(root->r)<=0) return leftRotate(root);
    if(balance<-1 && getBalance(root->r)>0){ root->r=rightRotate(root->r); return leftRotate(root); }
    return root;
}
struct Node* search(struct Node* root, int key){
    if(!root || root->key==key) return root;
    if(key<root->key) return search(root->l,key);
    return search(root->r,key);
}
void inorder(struct Node* root){
    if(root){ inorder(root->l); printf("%d ",root->key); inorder(root->r); }
}
int main(){
    struct Node* root = NULL;
    int ch, x;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Exit\n");
        scanf("%d",&ch);
        if(ch==1){ scanf("%d",&x); root=insert(root,x); }
        else if(ch==2){ scanf("%d",&x); root=deleteNode(root,x); }
        else if(ch==3){ scanf("%d",&x); search(root,x)? printf("Found\n") : printf("Not Found\n"); }
        else if(ch==4) { inorder(root); printf("\n"); }
        else break;
    }
    return 0;
}

