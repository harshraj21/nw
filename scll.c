#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
}*ptr;

struct node *start;
int count;
int top;

void push(void);
void pop(void);
void display(void);
void el_top(void);
void elem(void);
int is_empty(void);

void main(){
    int ch;
    start = NULL;
    count = top = 0;

    for(;;){
        printf("\nStacks using circular linked list\n1: Push\n2: Pop\n3: Display\n4: Top\n5: Element\n6: Exit\n Enter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: el_top();
            break;
            case 5: elem();
            break;
            case 6: exit(1);
            break;
            default: printf("\nInvalid Option please try again!\n");
            break;
        }
    }
}

void push(){
    struct node *temp;
    int val2;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value to push: \n");
    scanf("%d",&val2);

    if(ptr == NULL){
        printf("\nWarning: Memory Allocation Failed! Insufficient Memory\n");
    }
    else{
        if(start == NULL){
            ptr->val = val2;
            start = ptr;
            ptr->next = start;
            printf("\n%d Pushed Sucessfully!\n");
        }
        else{
            ptr->val = val2;
            ptr->next = start;
            start = ptr;
            printf("\n%D Pushed Sucessfully!\n");
        }
    }
}

void display(){

}

int is_empty(){
    if(start == NULL && count == 0){
        return(1);
    }
    else{
        return(0);
    }
}

 







/*
* Toppic: Stacks Using Circular Linked List
* Coded By: Harsh Raj
* College: NMIT
* Year: 2nd
* Sem: 3rd
* Adm. No: 20915
* USN: 1NT18IS066
*/