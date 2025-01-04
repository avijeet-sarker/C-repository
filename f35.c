#include<stdio.h>
void calculateprice(float value);
int main(){
    float value =100.00;
    calculateprice(value);
   // printf("value is : %f",value);
    return 0;
}
void calculateprice(float value){
    value= value+(0.18*value);
    printf("final price : %f", value);
}