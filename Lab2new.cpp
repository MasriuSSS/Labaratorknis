#include<iostream>

main(){
int i = 69;
int number = 72;
int a[3] = {};
int* iPointer = &i;

i=i+number;
std::cout<<i<<"\n";

number = *iPointer;
std::cout<<number<<"\n";

*iPointer = 15;
std::cout<<i<<"\n";

iPointer = &a[0];
std::cout<<iPointer<<"\n";

iPointer = iPointer+2;

a[0] = 5;
*iPointer = 6;
for(int j=0; j<3;j++){
std::cout<<a[j]<<" ";
}
}
