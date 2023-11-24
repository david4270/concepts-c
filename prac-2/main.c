#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node * left;
    struct Node * right;
    int data;
}BSTNode;

typedef struct tree{
    BSTNode * root;
}BSTree;

void insertNode(BSTree * tree, int n){
    BSTNode * ptr = tree->root;
    printf("%d\n", n);
    while(ptr != NULL){
        if(n < ptr->data){
            ptr = ptr->left;
        }else{
            ptr = ptr->right;
        }
    }
    ptr = (BSTNode *)malloc(sizeof(BSTNode));
    ptr->data = n;
    ptr->left = NULL;
    ptr->right = NULL;

}

int main(){
    BSTree * tree = (BSTree *)malloc(sizeof(BSTree));
    tree->root = NULL;
    insertNode(tree, 4);
    insertNode(tree, 2);
    insertNode(tree, 6);
    return 0;
}