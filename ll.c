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

                                            /*Updates Coming*/

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
        ptr->next = start;
        start = ptr;
        printf("\nLinked List Sucessfully Generated and value stored!\n\n");
    }
}

void display(){
    int i;
    if(start == NULL){
        printf("\nWarning: List is Empty!\n");
    }
    else{
        i=0;
        printf("\nPrinting the stored values\n\n");
        while(ptr!=NULL){
            printf("%d: %d\n",++i,(ptr->val));
            ptr = ptr->next;
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