#include <stdio.h>
int main()
{
    int day;
    printf("enter the day(1-7):");
    scanf("%d", &day);
    switch (day){
        case 1 : printf("mon");
        break;
        case 2 : printf("tue");
        break;
        case 3 : printf("wed");
        break;
        case 4 : printf("thu");
        break;
        case 5 : printf("fri");
        break;
        case 6 : printf("sat");
        break;
        case 7 : printf("sun");
        break;
        default : printf("not valid day");
}
}