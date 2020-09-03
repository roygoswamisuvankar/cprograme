/*You have to complete the function void update(int *a,int *b), which reads two integers as argument, and sets  with the sum of them, and  with the absolute difference of them.

Input Format

The input will contain two integers, a and b, separated by a newline.

Output Format

You have to print the updated value of a and b, on two different lines.

Note: Input/ouput will be automatically handled. You only have to complete the function described in the 'task' section.

*/

#include<stdio.h>
void update(int *a, int *b){
    int sum,sub;
    sum = *a + *b;
    sub = *a - *b;
    if(sub<0){
        sub *= (-1);
    }
    printf("%d %d",sum,sub);
}
int main(){
    int a,b;
    int *pa, *pb;
    scanf("%d %d",&a,&b);
    pa = &a;
    pb = &b;
    update(pa,pb);
}
