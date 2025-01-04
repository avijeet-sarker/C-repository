#include<stdio.h>
int sum(int n);
int main (){
    printf("%d", sum(5));

}

int sum (int n){
    if(n==1){
        return 1;
    }
    int sumN = sum(n-1)+n;
}