#include<stdio.h>
float squarearea(float side);
float circlearea(float red);
float rectanglearea(float a, float b);
int main(){
    float side=5;
    printf("%f\n",squarearea(side));
    float red=3;
    printf("%f\n" ,circlearea(red));
    float a=3;
    float b=6;
   printf("%f\n", rectanglearea(a , b));
    return 0;


}
float squarearea(float side){
    return side*side;
}
float circlearea(float red){
    return 3.14*red*red;
}
float rectanglearea(float a, float b){
    return a*b;
}