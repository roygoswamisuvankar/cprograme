#include<stdio.h>
int main(){
    int a[3],b[3],i,ap,bp;
    for(i=0;i<3;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<3;i++){
        scanf("%d",&b[i]);
    }
    ap = ((a[0]>b[0]?1:0) + (a[1]>b[1]?1:0) + (a[2]>b[2]?1:0));
    bp = ((a[0]<b[0]?1:0) + (a[1]<b[1]?1:0) + (a[2]<b[2]?1:0));

    printf("%d %d",ap,bp);
}
