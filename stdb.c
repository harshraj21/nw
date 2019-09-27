#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 15

struct stud{
    char name[max];
    char usn[max];
    char sem[max];
    char sec[max];
    char mob[max];
    struct stud *next;
}*ptr;

struct stud *start;
int count;

void add(void);
void display(void);
int is_empty(void);

void main(){
    count = 0;
    start = NULL;
    int ch;

    for(;;){
        printf("\nStudent Database using Linked List\n\n1: Insert\n2: Display\n3: Quit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: add();
            break;
            case 2: display();
            break;
            default: printf("\nInvalid Choice!\n");
        }
    }
}

void add(){
    char name[max];
    char usn[max];
    char sem[max];
    char sec[max];
    char mob[max];
    struct stud *tmp;
    printf("\nEnter The Name Of The Student: ");
    scanf("%s",name);
    printf("\nEnter The USN Of The Student: ");
    scanf("%s",usn);
    printf("\nEnter The Semester Of The Student: ");
    scanf("%s",sem);
    printf("\nEnter The Section Of The Student: ");
    scanf("%s",sec);
    printf("\nEnter The Mobile No Of The Student: ");
    scanf("%s",mob);

    ptr = (struct stud*)malloc(sizeof(struct stud));

    if(ptr == NULL){
        printf("Alert: Memory is Full Allocation Insucessfull!");
    }
    else{
        if(is_empty() == 1){
            ptr->name = name;
            ptr->usn = usn;
            ptr->sem = sem;
            ptr->sec = sec;
            ptr->mob = mob;
            ptr->next = NULL;
            start = ptr;
        }
        else{
            tmp = start;
            ptr->name = name;
            ptr->usn = usn;
            ptr->sem = sem;
            ptr->sec = sec;
            ptr->mob = mob;
            while(tmp->next!=NULL){
                tmp = tmp->next;
            }
            tmp->next = ptr;
            ptr->next = NULL;
        }
        printf("\nList Generated Sucessfull!\n");
    }
}

void display(){
    struct stud *tmp;
    tmp = start;
    if(is_empty() == 1){
        printf("\nAlert: Memory is Full Allocation Insucessfull!\n");
    }
    else{
        printf("\n\nPrinting Stored Data\n");
        while(tmp!=NULL){
            printf("Name: %s\n",tmp->name);
            printf("Usn: %s\n",tmp->usn);
            printf("Sem: %S\n",tmp->sem);
            printf("Sec: %s\n",tmp->sec);
            printf("Mob: %s\n\n",tmp->mob);
            tmp = tmp->next;
        }
    }
}

int is_empty(){
    if(start == NULL && count == 0){
        return(1);
    }
    else{
        return(0);
    }
}