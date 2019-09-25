#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
}*ptr;

struct node *start;
int count;

void display();
void create();
void delete();
void del_all();

void main(){
    int ch;
    count = 0;
    start = NULL;

    for(;;){
        printf("\nLinked List Generation\n0: Exit\n1: Insert one\n2: Delete one\n3: Delete by elem.\n4: Delete by pos.\n5: Display all\n6: Delete all\n7: Insert by position\n8: Insert by value (after)\n9: Insert by value (before)\n10: Elements count\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 0: exit(1);
            break;

            case 1: create();
            break;

            case 2: delete();
            break;

            case 5: display();
            break;

            case 6: del_all();
            break;

            case 10: printf("\nNo of element present in list is: %d\n",count);
            break;
        
            default: printf("\nInvalid Choice!\n");
            break;
        }
    }
}

void create(){
    int val2;
    struct node *tmp;
    tmp = start;
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
            count++;
        } 
    }
    else{
        ptr->val = val2;
        ptr->next = NULL;
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = ptr;
        printf("\nLinked List Sucessfully Generated and value stored!\n\n");
        count++;
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
        start->next = NULL;
        free(start);
        start = ptr;
        printf("\n%d Deleted Sucessfully!\n",tmp);
        count--;
    }
}

void del_all(){
    struct node *tmp;
    struct node *tmp2;
    tmp = start;
    tmp2 = start;
    if(start == NULL){
        printf("\nWarning: List is Empty!\n");
    }
    else{
        while(tmp!=NULL){
            free(tmp2);
            tmp = tmp->next;
            tmp2 = tmp;
        }
        start = NULL;
        printf("\nAll Items Deleted Sucessfully!\n");
    }
}