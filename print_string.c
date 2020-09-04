#include<stdio.h>
#include<string.h>
int main(){
    char ch,c;
    char s[100],sen[100];
    scanf("%c",&ch);
    scanf("%s",s);
    scanf("%c",&c);
    fgets(sen,100,stdin);
    printf("%c",ch);
    printf("\n%s",s);
    printf("\n%s",sen);
}

/*output
C
Language
Welcome to C!!

*/
