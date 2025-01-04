#include<stdio.h>
float converttem(int celsius);
int main ()
{
    float celsius=0;
    printf("%f", converttem(celsius));
    

}
float converttem(int celsius){
    float fer= celsius*(9/5)+32;
return fer;
}