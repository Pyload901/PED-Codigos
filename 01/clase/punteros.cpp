#include <iostream>
using namespace std;

int main () {
    // Punteros
    // ¿Qué es un puntero?
    // [] [ 2 ] [ 5 ] [] []
    //      ^
    //

    // int num1 = 2; 
    // int num2 = 5;

    // int *p = nullptr;
    // p = &num1;
    // cout << *p << endl;


    // ¿Qué mostrará el siguiente código?
    // int *num1 = nullptr;
    // int num2 = 1999;
    // cout << num1 << endl;
    // num1 = &num2;
    // cout << num1 << endl;
    // cout << *num1 << endl;

    // ¿Y si le hacemos esta modificación?
    int *num1 = nullptr; // <- new
    int num2 = 1999;
    int num3 = 1999;

    *num1 = num2;
    cout << &num2 << endl;
    cout << &num3 << endl;
    cout << num1 << endl;
    cout << *num1 << endl;
    delete num1;


    // Puntero doble
    // [] [] [ 10 ] [ 5 ] [] []
    //         ^
    //         ^
    // int * p1 = nullptr;
    // int * *p2 = nullptr;
    // // int ***p3 = nullptr;
    // int num = 1;
    // cout << num << endl;
    
    // p1 = &num;
    // p2 = &p1;
    // // p3 = &p2;

    // *p1 = 10;
    // // cout << *p1 << endl;

    // cout << p1 << endl;
    // cout << &p1;
    // cout << endl;
    
    // cout << &p2 << endl;
    // cout << p2 << endl;
    // cout << endl;
    // cout << *p2 << endl;

    // cout << &num << endl;

    // cout << endl; // Qué contiene la direción de memoria de p1??
    // cout << **p2 << endl;
    return 0;
}