/*stack using single link list
Last In First Out(LIFO)*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *next;
    int data;
}*head = NULL;
/*displaying stack elements*/
void display(){
    struct node *ptr;
    if(head == NULL){
        printf("\nStack is empty");
    }else{
        printf("\nStack elements are: ");
        ptr = head;
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
    }
}
/*inserting new element into stack*/
void insert(int x){
    struct node *tmp, *ptr;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = x;
    if(head == NULL){
        head = tmp;
        tmp->next = NULL;
    }else{
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = tmp;
    }
    printf("\nPUSH operation successfully completed");
    display();
}
/*deleting elements from stack or pop operation*/
void delstack(){
    struct node *tmp, *ptr;
    if(head == NULL){
        printf("\nstack is empty, deletion not possible");
    }else{
        tmp = head;
        if(tmp->next == NULL){
            head = NULL;
            printf("\nPOP element is: %d",tmp->data);
            free(tmp);
            printf("\nPOP operation successfully completed");
            display();
        }else{
            while(tmp->next!=NULL){
                ptr = tmp;
                tmp=tmp->next;
            }
            ptr->next = NULL;
            printf("\nPOP element is: %d",tmp->data);
            free(tmp);
            printf("\nPOP operation is successfully completed");
            display();
        }
    }
}
/*main function*/
int main(){
    int ch,data;
    while(1){
        printf("\n1.push();\n2.pop();\n3.display();\n4.exit(1);\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("\nEnter element: ");
            scanf("%d",&data);
            insert(data);
            break;
        case 2:
            delstack();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\nWrong choice, try again......");
            break;
        }
    }

}
