/*single link list*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *next;
    int data;
}*head = NULL;

/*insert new node at begening*/
void ins_beg(int x){
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = x;
    if(head == NULL)
        head = tmp;
    else{
        tmp->next = head;
        head = tmp;
    }
    printf("Entered node successfully");
    display();
}

/*display list elements*/
void display(){
    struct node *ptr;
    if(head == NULL)
        printf("list is empty:");
    else{
        ptr = head;
        printf("\nThe nodes are: \n");
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
    }
}

/*insert new node at end*/
void ins_end(int x){
    struct node *tmp,*ptr;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = x;
    if(head == NULL)
        head = tmp;
    else{
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = tmp;
    }
    printf("Entered node successfully");
    display();
}

/*insert node position wise*/
void ins_pos(int pos, int x){
    int i;
    struct node *tmp,*ptr;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = x;
    if(head == NULL)
        head = tmp;
    else{
        ptr = head;
        for(i=1;i<=pos-2;i++){
            ptr=ptr->next;
        }
        tmp->next = ptr->next;
        ptr->next = tmp;
    }
    printf("Entered node successfully");
    display();
}

/*Delete 1st node:*/
void del_beg(){
    struct node *tmp;
    if(head == NULL)
        printf("list is empty");
    else{
        tmp = head;
        head = head->next;
        printf("deleted node is: %d",tmp->data);
        free(tmp);
        display();
    }
}

/*delete last node*/
void del_last(){
    struct node *tmp,*ptr;
    if(head == NULL)
        printf("list is empty");
    else{
        tmp = head;
        if(tmp->next == NULL){
            printf("Deleted node is: %d",tmp->data);
            head = NULL;
            free(tmp);
            return;
        }
        else{

            while(tmp->next != NULL){
                ptr = tmp;
                tmp = tmp->next;
            }
            printf("deleted node is: %d",tmp->data);
            ptr->next = NULL;
            free(tmp);
        }
        display();
    }
}

/*deleted position wise*/
void del_pos(int pos){
    struct node *ptr,*tmp;
    int i;
    if(head == NULL)
        printf("list is empty");
    else{
        ptr = head;
        for(i=1;i<=pos-2;i++){
            ptr=ptr->next;
        }
        tmp = ptr->next;
        ptr->next = tmp->next;
        printf("Deleted node is: %d",tmp->data);
        free(tmp);
        if(i == 1)
            head = NULL;
        display();
    }
}

int main(){
    int ch,data,pos;
    while(1){
        printf("\n1.ins_beg()\n2.display()\n3.ins_end()\n4.ins_pos()\n5.del_beg()\n6.del_last()\n7.del_pos()\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter new node: ");
            scanf("%d",&data);
            ins_beg(data);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter new node: ");
            scanf("%d",&data);
            ins_end(data);
            break;
        case 4:
            printf("Enter position: ");
            scanf("%d",&pos);
            printf("Enter new node: ");
            scanf("%d",&data);
            ins_pos(pos,data);
            break;
        case 5:
            del_beg();
            break;
        case 6:
            del_last();
            break;
        case 7:
            printf("Enter position: ");
            scanf("%d",&pos);
            del_pos(pos);
            break;
        default:
            printf("wrong choice, try again: ");
            break;
        }
    }
}

