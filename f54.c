#include<stdio.h>
int dowork(int a, int b, int *sum ,int *prod, int *avg);
int main(){
    int a=5, b=7;
    int sum,prod,avg;
    dowork( a,  b,  &sum, &prod,  &avg);
    printf("sum=%d,prod=%d,avg=%d", sum,prod,avg);

}
int dowork(int a, int b, int *sum, int *prod, int *avg){
    *sum= a+b;
    *prod= a*b;
    *avg= (a+b)/2;
}