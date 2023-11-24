#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100


/*** Stack - Array Implementation ***/

// struct for stack - array implementation

typedef struct Stack_array{
    int stack[STACK_SIZE];
    int top;
}Stack;

//initialize
void initialize_stack_arr(Stack * s){
    s->top = -1;
}

//check if stack is empty
int is_empty_arr(Stack *s){
    return s->top == -1;
}

//push
void push_arr(Stack *s, int item){
    if(s->top == STACK_SIZE - 1){
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->stack[s->top] = item;
}

//pop
int pop_arr(Stack *s){
    if(is_empty_arr(s)){
        printf("Empty stack\n");
        return -1;
    }
    int item = s->stack[s->top];
    s->top--;
    return item;
}

//peek
int peek_arr(Stack *s){
    if(is_empty_arr(s)){
        printf("Empty stack\n");
        return -1;
    }
    return s->stack[s->top];
}

//traverse
int traverse_arr(Stack *s){
    if(is_empty_arr(s)){
        printf("Empty stack\n");
        return -1;
    }
    int i;
    for(i = 0; i <= s->top; i++){
        printf("%d ", s->stack[i]);
    }
    printf("\n");
    return 0;
}

/*** Stack - Linked List Implementation ***/
// struct for stack - linked list implementation
typedef struct Node{
    int data;
    struct Node * next;
}Node;

typedef struct Stack_list{
    Node * top;
}Slist;

//initialize
void initialize_stack_list(Slist * stack){
    stack->top = NULL;
}

//check if stack is empty
int is_empty_list(Slist *s){
    return s->top == NULL;
}

//push
void push_list(Slist *s, int item){
    Node * newNode = (Node *) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Failed to allocate memory for new node\n");
        return;
    }
    newNode->data = item;
    newNode->next = s->top;
    s->top = newNode;
}

//pop
int pop_list(Slist *s){
    if(is_empty_list(s)){
        printf("Empty stack\n");
        return -1;
    }
    Node * newHead;
    int item = s->top->data;
    newHead = s->top->next;
    free(s->top);
    s->top = newHead;

    return item;
}

//peek
int peek_list(Slist *s){
    if(is_empty_list(s)){
        printf("Empty stack\n");
        return -1;
    }
    return s->top->data;
}

//traverse
int traverse_list(Slist *s){
    if(is_empty_list(s)){
        printf("Empty stack\n");
        return -1;
    }
    Node * ptr = s->top;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}

//main, to test things out

int main(){

    //testing array implementation
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    initialize_stack_arr(stack);
    push_arr(stack, 1);
    push_arr(stack, 2);
    push_arr(stack, 3);
    push_arr(stack, 4);
    push_arr(stack, 5);
    traverse_arr(stack);
    printf("Popped: %d\n", pop_arr(stack));
    printf("Popped: %d\n", pop_arr(stack));
    printf("Popped: %d\n", pop_arr(stack));
    printf("Popped: %d\n", pop_arr(stack));
    printf("Popped: %d\n", pop_arr(stack));
    printf("Popped: %d\n", pop_arr(stack));
    traverse_arr(stack);
    push_arr(stack, 6);
    push_arr(stack, 7);
    push_arr(stack, 8);
    push_arr(stack, 9);
    push_arr(stack, 10);
    push_arr(stack, 11);
    traverse_arr(stack);
    printf("Peek: %d\n", peek_arr(stack));
    printf("Popped: %d\n", pop_arr(stack));
    printf("Popped: %d\n", pop_arr(stack));
    printf("Popped: %d\n", pop_arr(stack));
    printf("Popped: %d\n", pop_arr(stack));
    traverse_arr(stack);


    //testing linked list implementation
    Slist * slist = (Slist *)malloc(sizeof(Slist));
    initialize_stack_list(slist);
    push_list(slist, 1);
    push_list(slist, 2);
    push_list(slist, 3);
    push_list(slist, 4);
    push_list(slist, 5);
    traverse_list(slist);
    printf("Popped: %d\n", pop_list(slist));
    printf("Popped: %d\n", pop_list(slist));
    printf("Popped: %d\n", pop_list(slist));
    printf("Popped: %d\n", pop_list(slist));
    printf("Popped: %d\n", pop_list(slist));
    printf("Popped: %d\n", pop_list(slist));
    traverse_list(slist);
    push_list(slist, 6);
    push_list(slist, 7);
    push_list(slist, 8);
    push_list(slist, 9);
    push_list(slist, 10);
    push_list(slist, 11);
    traverse_list(slist);
    printf("Peek: %d\n", peek_list(slist));
    printf("Popped: %d\n", pop_list(slist));
    printf("Popped: %d\n", pop_list(slist));
    printf("Popped: %d\n", pop_list(slist));
    printf("Popped: %d\n", pop_list(slist));
    traverse_list(slist);
    


    return 0;
}