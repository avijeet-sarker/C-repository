#include<stdio.h>
int sum(int a, int b);
void printTable(int n);
int main()
{
int n ;
printf("enter the value n:");
scanf("%d", &n);
printTable( n);
return 0;
}
int sum( int a ,int b){
    return a+b ;
}
void printTable(int n){
for(int i=1; i<=10; i++){
    printf("%d\n", i*n);
}
}