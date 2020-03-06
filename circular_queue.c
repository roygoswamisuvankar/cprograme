/*circular queue first in first out*/
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct circularque{
    int rear, item[max];
}q;
int index;

/*displaying circular queue elements*/
void display(){
    if(q.rear == -1){
        printf("\nList is empty");
    }else{
        printf("\nThe elements are: ");
        for(index=0;index<=q.rear;index++){
            printf("%d\t",q.item[index]);
        }
    }
}

/*inserting elements*/
void ins_que(){
    int element;
    if(q.rear == (max-1)){
        printf("\nList is full");
    }else{
        printf("\nEnter element: ");
        scanf("%d",&element);
        for(index = ++q.rear; index>=0; index--){
            q.item[index] = q.item[index-1];
        }
        q.item[0] = element;
    }
    display();
}

/*deleting queue elements*/
void delqueue(){
    if(q.rear == -1){
        printf("\nQueue is empty");
    }else{
        printf("\nThe deleted queue element is: %d",q.item[0]);
        for(index=0;index<=q.rear;index++){
            q.item[index]=q.item[index+1];
        }
        q.item[q.rear--];
        display();
    }
}
/*main function*/
int main(){
    int ch;
    while(1){
        printf("\n1.insert\n2.delete\n3.display\n4.exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                ins_que();
                break;
            case 2:
                delqueue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("\nWrong choice, try again....");
                break;
        }
    }
}
