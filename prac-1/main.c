#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node * next;
    int data;
}treeNode;

void traverse(treeNode * head){
    treeNode * ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert_last(treeNode * head, int n){
    treeNode * ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = (treeNode *)malloc(sizeof(treeNode));
    ptr->next->data = n;
    ptr->next->next = NULL;
}

void insert_first(treeNode ** head, int n){
    treeNode * ptr = (treeNode *)malloc(sizeof(treeNode));
    ptr->data = n;
    ptr->next = *head;
    *head = ptr;
}

void remove_first(treeNode ** head){
    treeNode * ptr = *head;
    *head = (*head)->next;
    free(ptr);
}

void remove_last(treeNode * head){
    treeNode * ptr = head;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}

int main(){
    treeNode * root = (treeNode *)malloc(sizeof(treeNode));
    root->data = 1;
    root->next = NULL;
    insert_last(root, 2);
    insert_last(root, 3);
    insert_last(root, 4);
    traverse(root);
    insert_first(&root, 0);
    traverse(root);
    remove_first(&root);
    traverse(root);
    remove_last(root);
    traverse(root);

    return 0;
}
