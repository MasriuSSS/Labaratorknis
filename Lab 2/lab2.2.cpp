#include <iostream>
#include <cstring>  // Pentru utilizarea funcției memset

// Definirea unei structuri cu două câmpuri de tip întreg
struct DouaIntregi
{
    int primul;
    int alDoilea;
};

// Definirea unei structuri care conține un array și un pointer
struct StructCuArray
{
    int array[4];
    int* unNumar;
};

int main()
{
    // Crearea și inițializarea unei structuri cu două câmpuri de tip întreg
    DouaIntregi i2 = { };
    i2.primul = 5;
    i2.alDoilea = 7;

    // Afișarea valorilor celor două câmpuri ale structurii
    std::cout << i2.primul << std::endl;
    std::cout << i2.alDoilea << std::endl;

    // Crearea și inițializarea unei structuri cu un array, setând primul element
    StructCuArray s = { };
    s.array[0] = 10;

    // Crearea altei instanțieri și inițializarea primului element
    StructCuArray s1 = { };
    s1.array[0] = 15;

    // Crearea unui pointer care indică structura s
    StructCuArray* sPointer = &s;
    sPointer->array[0] = 20;

    // Afișarea valorii primului element din array s prin pointer 
    std::cout << s.array[0] << std::endl;

    // Schimbarea valorii primului element din array s 
    s.array[0] = 25;
    std::cout << s.array[0] << std::endl;

    // Schimbarea valorii primului element din array s prin sPointer 
    std::cout << s.array[0] << std::endl;

    // Schimbarea pointerului să indice structura s1
    sPointer = &s1;

    // Schimbarea valorii primului element din array s1 cu 35 prin sPointer
    sPointer->array[0] = 35;

    // Afișarea valorii primului element din array s 
    std::cout << s.array[0] << std::endl;

    // Afișarea valorii primului element din array s1 
    std::cout << s1.array[0] << std::endl;

    // Crearea unui array structArray de tip StructCuArray cu 2 elemente și inițializarea lor
    StructCuArray structArray[2] = { };
    structArray[0].array[3] = 77;
    structArray[1].unNumar = &structArray[0].array[3];

    // Schimbarea pointerului să indice structura s
    sPointer = &s;

    // Crearea unui pointer  care indică al patrulea element din array s
    int* pointer = &sPointer->array[3];

    // Schimbarea valorii al patrulea element din array s în 72
    s.array[3] = 72;

    // Afișarea valorii la care indică pointerul 
    std::cout << *pointer;

    // Crearea unei structuri numită memory și inițializarea memoriei sale cu 0
    StructCuArray memory;
    std::memset(&memory, 0, sizeof(StructCuArray));

    return 0;
}