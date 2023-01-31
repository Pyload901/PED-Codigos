/*
    _
    _
    _
    _
    _


    * * * * * *

*/

#include <iostream>
using namespace std;
struct Nodo {
    int dato;
    Nodo *next;
    Nodo (int dato) {
        this->dato = dato;
        this->next = nullptr;
    }
};

void insertar(Nodo *nuevo);
void leer();

Nodo *head = new Nodo(5);
Nodo *last = head;

int main () {
    head->next = nullptr;
    head->dato = 5;
    insertar(new Nodo(3));
    insertar(new Nodo(2));
    leer();
    leer();
    leer();
    leer();
    return 0;
}
//             []
// [] [] [] [] 
void insertar(Nodo *nuevo) {
    last->next = nuevo;
    last = nuevo;
}

void leer() {
    if (head) {
        cout << head->dato << endl;
        Nodo *aux = head;
        head = head->next;
        delete aux;
    }
    else 
        cout << "La cola esta vacia" << endl;
    
}
