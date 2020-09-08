/*print nth term of a series using recursion hacker rank*/
#include < stdio. h >
#include < stdlib.h >
int func(int n);
int main()
{
int n, i, a, b, c, h, k;
printf("Enter the value of n,a,b,c\n");
scanf("%d%d%d%d", &n, &a, &b, &c);
h = func(n);
printf("%d", h);
}
int func(int n)
{
if (n < 1)
exit(1);
if (n > 3)
{
return func(n - 1) + func(n - 2) + func(n - 3);
}
return 0;
}
