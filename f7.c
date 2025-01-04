#include<stdio.h>
int main()
{
printf("%d\n",5>4 && 5<9);
printf("%d\n",4>5 && 5>3);
printf("%d\n",5>4 || 5<9);
printf("%d\n",4>5 || 5>3);
printf("%d\n", 2>3||6>9);
printf("%d\n",!(5>4 && 5<9));
printf("%d\n",!(4>5 && 5>3));


return 0;
}