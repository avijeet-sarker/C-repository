#include<stdio.h>
float converttem(int celsius);
int main ()
{
    float celsius=0;
converttem(celsius);
    

}
float converttem(int celsius){
    float fer= celsius*(9/5)+32;
    printf("%f", fer);
return fer;
}