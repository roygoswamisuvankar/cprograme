/*double link list*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *next, *prev;
    int data;
}*head = NULL;

/*displaying nodes*/
void display(){
    struct node *ptr;
    if(head == NULL){
        printf("\nList is empty");
    }else{
        printf("\nThe nodes are: ");
        ptr = head;
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
    }
}

/*inserting new elements at begining*/
void ins_beg(int x){
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = x;
    tmp->prev = NULL;
    if(head == NULL){
        tmp->next = NULL;
    }else{
        tmp->next = head;
        head->prev = tmp;
    }
    head = tmp;
    printf("\nInserted new node at begining successfully");
    display();
}

/*inserting new node at end*/
void ins_end(int x){
    struct node *tmp, *ptr;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = x;
    tmp->prev = NULL;
    if(head == NULL){
        tmp->next = NULL;
        head = tmp;
    }else{
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = tmp;
        tmp->prev = ptr;
    }
    printf("\nInserted node at end successfully");
    display();
}

/*insert new node at any position*/
void ins_any(int x, int pos){
    struct node *tmp,*ptr, *q;
    int i;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = x;
    tmp->prev = NULL;
    if(head == NULL){
        tmp->next = NULL;
        head = tmp;
    }else{
        ptr = head;
        for(i=1; i<=pos-2; i++){
            ptr = ptr->next;
        }
        q = ptr->next;
        tmp->next = q;
        ptr->next = tmp;
        q = ptr->prev;
        tmp->prev = ptr;
        ptr->prev = tmp;
    }
    printf("\nInserted node at %d position successfully",pos);
    display();
}

/*deleted node at begining*/
void del_beg(){
    struct node *tmp;
    if(head == NULL){
        printf("\nList is empty");
    }else{
        tmp = head;
        head = head->next;
        printf("\nDeleted node at begeing successfully");
        printf("\nDeleted node is: %d",tmp->data);
        free(tmp);
        display();
    }
}

/*delted node at end*/
void del_end(){
    struct node *tmp, *ptr;
    if(head == NULL){
        printf("\nList is empty");
    }else{
        tmp = head;
        if(tmp->next == NULL){
            printf("\nDeleted node at end successfully");
            printf("\nDeleted node is: %d",tmp->data);
            head = NULL;
            free(tmp);
            display();
        }else{
            while(tmp->next != NULL){
                ptr = tmp;
                tmp = tmp->next;
            }
            ptr->next = NULL;
            printf("\nDeleted node at end successfully");
            printf("\nDeleted node is: %d",tmp->data);
            free(tmp);
            display();
        }
    }
}
/*deleted node at position wise*/
void del_any(int pos){
    struct node *ptr, *tmp, *q;
    int i;
    if(head == NULL){
        printf("\nList is empty");
    }else{
        if(pos == 1){
            tmp = head;
            head = head->next;
            printf("\nDeleted node is: %d",tmp->data);
            printf("\nDeleted node at %d position successfully", pos);
            free(tmp);
            display();
        }
        else{
            ptr = head;
            for(i=1;i<=pos-2;i++){
                ptr = ptr->next;
            }
            tmp = ptr->next;
            q = tmp->next;
            ptr->next = q;
            q->prev = ptr;
            printf("\nDeleted node is: %d", tmp->data);
            printf("\nDeleted node at %d position successfully",pos);
            free(tmp);
            display();
        }
    }
}
/*main function*/
int main(){
    int ch,data,pos;
    while(ch){
        printf("\n1.ins_beg();\n2.display();\n3.exit();\n4.ins_end();\n5.ins_any();\n6.del_beg();\n7.del_end();\n8.del_any();\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter new node: ");
                scanf("%d",&data);
                ins_beg(data);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(1);
                break;
            case 4:
                printf("\nEnter new node: ");
                scanf("%d",&data);
                ins_end(data);
                break;
            case 5:
                printf("\nEnter new node: ");
                scanf("%d",&data);
                printf("\nEnter position: ");
                scanf("%d",&pos);
                ins_any(data, pos);
                break;
            case 6:
                del_beg();
                break;
            case 7:
                del_end();
                break;
            case 8:
                printf("\nEnter position: ");
                scanf("%d",&pos);
                del_any(pos);
                break;
            default:
                printf("\nWrong choice, try again...");
                break;
        }
    }
}
