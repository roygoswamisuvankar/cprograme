/*stack using array*/

#include<stdio.h>
#include<stdlib.h>
#define max 5
struct stack{
    int item[max], rear;
}s;
int index;

/*insert new element on stack*/
void push(){
    int element;
    if(s.rear == (max-1))
        printf("Stack is full");
    else{
        printf("Enter new element: ");
        scanf("%d",&element);
        s.item[++s.rear] = element;
        printf("Push successfully");
        display();
    }
}

/*displaying stack elements*/
void display(){
    if(s.rear == -1){
        printf("List is empty");
    }else{
        printf("\nThe elements are: ");
        for(index = 1; index<=s.rear; index++)
            printf("%d\t",s.item[index]);
    }
}

/*pop stack elements*/
void pop(){
    if(s.rear == -1){
        printf("List is empty");
    }else{
        printf("Deleted item is: %d",s.item[s.rear--]);
    }
}

/*main function*/
int main(){
    int ch;
    while(1){
        printf("\n1.push()\n2.pop()\n3.display()\n4.exit()\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Wrong choice, try again..");
                break;
        }
    }
}
