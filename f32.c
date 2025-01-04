#include<stdio.h>
void namaste();//declaration/prototype
void bonjour();
int main(){
    printf("enter f for franch & i for indian:");
    char ch;
    scanf("%c", &ch);
    if(ch=='i'){
        namaste();
   }
    else {
       bonjour();}
    // namaste();


    return 0;
}
// function definition
void namaste(){
    printf("namaste\n");
  // bonjour();
}
void bonjour(){
    printf("bonjour\n");
}

