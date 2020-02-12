#include<stdio.h>
#define max 5
#include<stdlib.h>
struct queue{
    int item[max],rear;
}q;
int index;

/*displaying queue elements*/
void display(){
    if(q.rear == -1){
        printf("queue is empty");
    }else{
        printf("The queue elements are:\n");
        for(index = 1; index<=q.rear; index++){
            printf("%d\t",q.item[index]);
        }
    }
}

/*inserting elelemts in queue*/
void insert(){
    int element;
    if(q.rear == (max)-1){
        printf("queue is full");
    }else{
        printf("Enter elelemt: ");
        scanf("%d",&element);
        q.item[++q.rear] = element;
        display();
    }
}

/*deleting elements in queue*/
void del(){
    if(q.rear == -1){
        printf("queue is empty");
    }else{
        printf("Deleted queue element is: %d",q.item[1]);
        for(index = 1; index<=q.rear; index++){
            q.item[index] = q.item[index+1];
        }
        q.item[--q.rear];
        display();
    }
}

/*main function*/
int main(){

    int ch;
    while(1){
        printf("\n1.insert();\n2.delete();\n3.display();\n4.exit();\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Wrong choice try again");
                break;
        }
    }
}
