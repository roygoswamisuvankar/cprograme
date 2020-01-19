/*final single link list*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *next;
    int data;
}*head = NULL;

/*node insert at begening*/
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
    printf("Node inserted successfully");
    display();
}

/*displaying nodes of the list*/
void display(){
    struct node *tmp,*ptr;
    if(head == NULL)
        printf("List is empty");
    else
    {
        ptr = head;
        printf("The nodes are:\n");
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
}

/*insert node at end*/
void ins_last(int x){
    struct node *tmp,*ptr;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = x;
    if(head == NULL)
        head = tmp;
    else{
        ptr = head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next = tmp;
    }
    printf("inserted node successfully");
    display();
}

/*insert at any postion*/
void ins_pos(int pos, int x){
    struct node *tmp,*ptr;
    int i;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = x;
    if(head == NULL)
        head = tmp;
    else{
        ptr = head;
        for(i=1;i<=pos-2;i++){
            ptr = ptr->next;
        }
        tmp->next = ptr->next;
        ptr->next = tmp;
    }
    printf("Inserted node successfully: ");
    display();
}

/*delete node at begening*/
void del_beg(){
    struct node *tmp;
    if(head == NULL){
        printf("list is empty");
    }
    else{
        tmp = head;
        head = head->next;
        printf("deleted node is: %d",tmp->data);
        free(tmp);
        display();
    }
}

/*delete node at end*/
void del_last(){
    struct node *tmp,*ptr;
    if(head == NULL)
        printf("list is empty");
    else{
        tmp = head;
        if(tmp->next == NULL){
            printf("deleted node is: %d",tmp->data);
            head = NULL;
            free(tmp);
            return;
        }else{

            while(tmp->next != NULL){
                ptr = tmp;
                tmp = tmp->next;
            }
            ptr->next = NULL;
            printf("Deleted node is: %d",tmp->data);
            free(tmp);
        }
        display();
    }
}

/*delete node position wise*/
void del_pos(int pos){
    struct node *tmp,*ptr;
    int i;
    if(head == NULL)
        printf("list is empty");
    else{
        ptr = head;
        for(i=1;i<=pos-2;i++){
            ptr = ptr->next;
        }
        tmp = ptr->next;
        ptr->next = tmp->next;
        printf("Deleted node is: %d",tmp->data);
        free(tmp);
        display();
    }
}

/*main function*/
int main(){
    int ch,data,pos;
    while(1){
        printf("\n1.ins_beg()\n2.display()\n3.ins_lst()\n4.ins_pos()\n5.del_beg()\n6.del_last()\n7.del_pos()\n8.exit()\nEnter your choice: ");
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
                ins_last(data);
                break;
            case 4:
                printf("Enter postion: ");
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
            case 8:
                exit(1);
                break;
            default:
                printf("Wrong input try again: ");
                break;
        }
    }
}

