
#include <iostream>
using namespace std;
struct Materia {
    string nombre;
    int uv;
};
struct Nodo {
    Materia materia;
    Nodo *next;
    Nodo (string nombre, int uv) {
        this->materia.nombre = nombre;
        this->materia.uv = uv;
        this->next = nullptr;
    }
};

Nodo *head = new Nodo("PED", 4);
Nodo *last = head;

void insertar (Nodo *nuevo);
void leer (Nodo *materia);

int main () {
    insertar(new Nodo("Fisica 1", 5));
    insertar(new Nodo("Fisica 2", 5));
    insertar(new Nodo("MD1", 3));
    insertar(new Nodo("MD2", 3));
    insertar(new Nodo("POO", 4));
    insertar(new Nodo("Web", 4));
    leer(head);
    return 0;
}
void insertar (Nodo *nuevo) {
    if (!head) {
        head = nuevo;
    } else {
        Nodo *it = head;
        switch (nuevo->materia.uv)
        {
        case 3:
            last->next = nuevo;
            last = nuevo;
            break;
        case 4:
            while (it->next && it->next->materia.uv > 4) {
                it = it->next;
            }
            nuevo->next = it->next;
            it->next = nuevo;
            break;
        case 5:
            nuevo->next = head;
            head = nuevo;
            break;
        default:
            break;
        }
    }
}
void leer (Nodo *materia) {
    cout << materia->materia.nombre  << " || " << materia->materia.uv << endl;
    if (!materia->next)
        return;
    else {
        leer(materia->next);
    }
}