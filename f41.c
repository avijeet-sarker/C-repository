#include<stdio.h>
float calpercentage(int phy , int che , int math);
int main ()
{
    float phy=98;
    float che=97;
    float math=99;
    printf("%f", calpercentage( phy , che , math));
    return 0;
    

}
float calpercentage(int phy , int che, int math){
    float percentage= ((phy+che+math)/3);
return percentage;
}