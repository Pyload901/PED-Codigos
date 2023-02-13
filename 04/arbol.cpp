#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    char dato;
    Nodo *left, *right;
    Nodo () {
    }
    Nodo (char dato) {
        this->dato = dato;
        this->left = this->right = nullptr;
    }
};

Nodo *root = nullptr;

void insert(char dato);
void insert(Nodo *nuevo, Nodo *it);
void inorden(Nodo *it);
// Recibir un string y guardar sus caracteres en un arbol
// Que tal

// Q
// u
// e
int main () {
    string cad;
    cout << "Ingrese un palabra: ";
    cin >> cad;
    for (char caracter : cad) {
        insert(caracter);
    }

    inorden(root);
    return 0;
}

void insert(char dato) {
    Nodo *nuevo = new Nodo(dato);
    if (!root) {
        root = nuevo;
        return;
    }
    insert(nuevo, root);
}
void insert(Nodo *nuevo, Nodo *it) {
    if (nuevo->dato < it->dato)
        if (it->left)
            insert(nuevo, it->left);
        else
            it->left = nuevo;
    else if (nuevo->dato > it->dato)
        if (it->right)
            insert(nuevo, it->right);
        else
            it->right = nuevo;
    return;
}

void inorden(Nodo *it) {
    if (!it)
        return;

    cout << it->dato << endl;
    inorden(it->left);
    inorden(it->right);
    
}