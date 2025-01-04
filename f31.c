#include<stdio.h>
void printHello();//declaration/prototype
void printgoodbye();
int main(){
    printHello(); //function call
    printgoodbye();
    printHello();
    return 0;
}
// function definition
void printHello(){
    printf("Hello!\n");
}
void printgoodbye(){
    printf("goodbye\n");
}

