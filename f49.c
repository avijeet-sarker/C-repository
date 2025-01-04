#include <stdio.h>
int main()
{
    int marks;
    printf("enter thr number");
    scanf("%d", &marks);
    if(marks<30){
        printf("c\n");
    }
    else if (marks>=30 && marks<70){
        printf ("b\n");
    }
    else if (marks>=70 && marks<90 ){
        printf("a\n");
    }
    else {
        printf("A+");
    }
}