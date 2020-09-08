#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int a[100][100],n,i,j,d1,d2,sub=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i == j){
                d1 = d1 + a[i][j];
            }
            if(i == n-j-1){
                d2 = d2 + a[i][j];
            }
        }
    }
    sub = abs(d1-d2);
    printf("%d",sub);
}
