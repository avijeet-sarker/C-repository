#include<stdio.h>
int sum(int a, int b);
void printTable(int n);
int main()
{
int n ;
int a ;
int b ;
printf("enter the value n:");
scanf("%d", &n);
printf("enter the value a:");
scanf("%d", &a);
printf("enter the value b:");
scanf("%d", &b);
printTable( n);
printf ("%d", sum (a,b));
return 0;
}
int sum( int a ,int b){
    int s = ((a+b));
    return s ;
}
void printTable(int n){
for(int i=1; i<=10; i++){
    printf("%d\n", i*n);
}
}