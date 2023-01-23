#include <iostream>
using namespace std;

// ¿Qué es el parámetro?
void printArr(int *arr) {
    // aritmética de punteros
    // int -> 0x6ab200
    // int -> 0x6ab204
    // int -> 0x6ab208

    // char -> 0x6ab200
    // char -> 0x6ab201
    // char -> 0x6ab202
    // char -> 0x6ab203

    cout << arr << endl;
    cout << arr+1 << endl;
    cout << arr[0] << endl;
    cout << arr[1] << endl;
}

struct Persona {
    string nombre;
};

void mostrar(Persona *personas, int n);
void mostrar(Persona &personas, int n);

int main () {
    // [] [] [] [] [] []
    // int arr[] = {1,2,3};

    int n;
    cin >> n;
    Persona personas[n];
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin >> personas[i].nombre;
    }

    // mostrar(personas, n);
    mostrar(personas[0], n);

    // printArr(arr);
    return 0;
}

void mostrar(Persona &personas, int n) {
    // cout << personas;
    // while(n--) {
    //     // personas; // <- 0x0012
    //     // *personas; // <- Persona -> {nombre, apellido, edad,etc..}
    // }
}

void mostrar(Persona *personas, int n) {
    while(n--) {
        // personas; // <- 0x0012
        // *personas; // <- Persona -> {nombre, apellido, edad,etc..}
        cout << personas->nombre << endl;
        personas++;
    }
}