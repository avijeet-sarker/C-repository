#include<stdio.h>
//void address(int n);
//int main(){
  //  int n=5;
    // printf("address=%d\n", &n);
     //address(n);
//
//}
// call by value
//void address(int n){
  //  printf("address=%d", &n);
//}
//call by reference
void address(int *n);
int main(){
    int n=5;
     printf("address=%d\n", &n);
     address(&n);

}
// call by value
void address(int *n){
    printf("address=%d", n);
}