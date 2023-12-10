#include <iostream>

int main()
{
    int i;
    i = 69; 

    int number = 72; 

    i = i + number; 

    int array[3] = { }; 

    int* ipointer = &i; 

    int number = *ipointer; 

    *ipointer = 15; 

    ipointer = &array[0];

    ipointer = ipointer + 2;

    array[0] = 5;

    *ipointer = 6;

}