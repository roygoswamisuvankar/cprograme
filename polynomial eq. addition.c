#include<stdio.h>
#include<stdlib.h>
struct node{
    int coff, pow;
    struct node *next;
};
struct node *tmp1=NULL,*tmp2=NULL, *tmp3=NULL, *tmp4=NULL;

void createpoly(int x, int y, struct node *head){
    struct node *tmp, *ptr;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->coff = x;
    tmp->pow = y;
    tmp->next = NULL;
    if(head == NULL){
        head = tmp;
    }else{
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = tmp;
    }
}

void display(struct node *head){
    while(head!=NULL){
        printf("%dX^%d+",head->coff, head->pow);
        head = head->next;
        /*if(head != NULL){
            printf("+");
        }*/
    }
}

void add(){
    while(tmp1!=NULL && tmp2!=NULL){
        if(tmp1->pow > tmp2->pow){
            tmp3->pow = tmp1->pow;
            tmp3->coff = tmp1->coff;
            tmp1 = tmp1->next;
        }
        else if(tmp2->pow < tmp2->pow){
            tmp3->pow = tmp2->pow;
            tmp3->coff = tmp2->coff;
            tmp2 = tmp2->next;
        }else{
            tmp3->pow = tmp1->pow;
            //tmp3->pow = tmp2->pow;
            tmp3->coff = tmp1->coff + tmp2->coff;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        tmp3->next = (struct node*)malloc(sizeof(struct node));
        tmp3 = tmp3->next;
        tmp3->next = NULL;
    }
    while(tmp1!=NULL || tmp2!=NULL){
        if(tmp1->next){
            tmp3->pow = tmp1->pow;
            tmp3->coff = tmp1->coff;
            tmp1 = tmp1->next;
        }
        if(tmp2->next){
            tmp3->pow = tmp2->pow;
            tmp3->coff = tmp2->coff;
            tmp2 = tmp2->next;
        }
        tmp3->next = (struct node*)malloc(sizeof(struct node));
        tmp3 = tmp3->next;
        tmp3->next = NULL;

    }
}
int main(){
    int coff, pow, n,i;
    tmp1 = (struct node*)malloc(sizeof(struct node));
    tmp2 = (struct node*)malloc(sizeof(struct node));
    tmp3 = (struct node*)malloc(sizeof(struct node));
    tmp4 = tmp3;
    printf("\nEnter nodes number: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    printf("\nCreate poly: ");
    printf("\nEnter coff: ");
    scanf("%d",&coff);
    printf("\nEnter pow: ");
    scanf("%d",&pow);
    createpoly(coff, pow, tmp1);

    }
    printf("\nEnter nodes number: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    printf("\nCreate poly: ");
    printf("\nEnter coff: ");
    scanf("%d",&coff);
    printf("\nEnter pow: ");
    scanf("%d",&pow);
    createpoly(coff, pow, tmp2);

    }
    printf("\npoly1: ");
    display(tmp1);
    printf("\nPoly2: ");
    display(tmp2);
    add();
    printf("\nAddition:\n");
    display(tmp4);
}
