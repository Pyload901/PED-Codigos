#include <iostream>
using namespace std;

struct Persona {
    string nombre;
    int anio;
    Persona *siguiente;

    // Persona(string _nombre, int anio) {
    //     nombre = _nombre;
    //     this->anio = anio;
    //     siguiente = nullptr;
    // }
};
void crearRegistro (string nombre, int anio);
void crearRegistro (Persona *nodo, Persona *lista);
void mostrar (Persona *lista);
Persona *inicio = new Persona;

int main () {
    // 0 <-> 1 <-> 2 <-> 3 <-> 4 -> 5 -> 6
    // |                            |
    //   - - -- - - - - -- - - -- -
    inicio->anio = 1999;
    inicio->nombre = "Jose";
    inicio->siguiente = nullptr;

    crearRegistro("David", 2003);
    crearRegistro("Matias", 1998);

    mostrar(inicio);
    return 0;
}

void crearRegistro (string nombre, int anio) {
    Persona *p2 = new Persona; // <- nodo
    p2->anio = anio;
    p2->nombre = nombre;
    p2->siguiente = nullptr;
    crearRegistro(p2, inicio);
}

void crearRegistro (Persona *nodo, Persona *lista) {
    Persona *it = lista;
    while (it->siguiente) {
        it = it->siguiente;
    }
    it->siguiente = nodo;
}

void mostrar (Persona *lista) {
    Persona *it = lista;
    do {
        cout << it->nombre << ' ' << it->anio << endl;
        it = it->siguiente;
    } while (it);
}