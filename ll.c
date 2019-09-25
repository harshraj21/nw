#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
}*ptr;

struct node *start;

void display();
void create();
void delete();

void main(){
    int ch;

    start = NULL;

    for(;;){
        printf("\nLinked List Generation\n1: Create\n2: Delete\n3: Display\n4: Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: create();
            break;

            case 2: delete();
            break;

            case 3: display();
            break;

            case 4: exit(1);
            break;
        
            default: printf("\nInvalid Choice!\n");
            break;
        }
    }
}

void create(){
    int val2;
    struct node *temp;
    printf("\nEnter The Value To Store: ");
    scanf("%d",&val2);
    ptr = (struct node*)malloc(sizeof(struct node));
    if(start == NULL){
        if(ptr == NULL){
            printf("\nWarning: Computer Memory Full!\n");
            return;
        }
        else{
            ptr->val = val2;
            ptr->next = NULL;
            start = ptr;
            printf("\nInitial List Sucessfully Generated and value stored!\n\n");
        } 
    }
    else{
        ptr->val = val2;
        ptr->next = NULL;
        temp = start;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        //start = ptr;
        printf("\nLinked List Sucessfully Generated and value stored!\n\n");
    }
}

void display(){
    int i;
    struct node *tmp;
    tmp = start;
    if(start == NULL){
        printf("\nWarning: List is Empty!\n");
    }
    else{
        i=0;
        printf("\nPrinting the stored values\n\n");
        while(tmp!=NULL){
            printf("%d: %d\n",++i,(tmp->val));
            tmp = tmp->next;
        }
    }
}

void delete(){
    int tmp;
    if(start == NULL){
        printf("\nWarning: List is Empty!\n");
    }
    else{
        ptr = start;
        ptr = ptr->next;
        tmp = start->val;
        free(start);
        start = ptr;
        printf("\n%d Deleted Sucessfully!\n",tmp);
    }
}