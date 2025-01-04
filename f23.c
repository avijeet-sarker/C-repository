#include<stdio.h>
int main()
{
    int n;
    printf("enter the number:");
    scanf("%d", &n);
    int sum=0;
   // for(int i=1; i<=n; i++){
    //    sum= sum+i;
    //}
   // printf("sum is %d\n", sum);
    for (int i=1,j=n;i<=n && j>=1; i++,j--){
        sum= sum+i;
        printf("%d\n", j);
    }
    printf("sum is %d\n", sum);
    return 0 ;
}