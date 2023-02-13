/*
    control de prestamos
    realizar un programa que pueda ingresar varias cuentas de prestamos y controlar el pago de estas, el programa debe implementar como mínimo una estructura dinámica y se puntuará que sea óptima

    Si la persona tiene un salario de menos de 1000, agregar un interes de 5%, si no, agregar 10%
*/

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct Pago {
    float cant;
    // ...
    Pago(float cant) {
        this->cant = cant;
    }
};

class Datos {
    private:
        int numero_cuenta;

    public:
        string nombre;
        float prestamo, salario, intereses, total_a_devolver;
        list<Pago> ListaPagos;
        Datos (){}
        Datos (int numero_cuenta, string nombre, float salario, float prestamo);
        int getNumeroCuenta();
};

struct Cuenta {
    Datos datos;
    Cuenta *left, *right;
    Cuenta (Datos datos) {
        this->datos = datos;
        this->left = this->right = nullptr;
    }
};
/*  
            []
        []       []
    []              []
*/

class ArbolCuentas {
    private:
        Cuenta *root;
    public:
        ArbolCuentas();
        void insert(Cuenta *cuenta);
        void mostrar();
        void mostrar(Cuenta *it);
        void hacerPago(int numero_cuenta, Pago pago);
};

int main () {
    ArbolCuentas arbol = ArbolCuentas();
    int numero_cuenta;
    string nombre;
    float salario;
    float prestamo;

    // cout << "Ingrese el numero de cuenta ", cin >> numero_cuenta;
    // cout << "Ingrese el nombre ", cin >> nombre;
    // cout << "Ingrese el salario ", cin >> salario;
    // cout << "Ingrese el prestamo ", cin >> prestamo;

    arbol.insert(new Cuenta(Datos(600, "David", 1000, 1000)));
    arbol.insert(new Cuenta(Datos(114, "Jose", 800, 2000)));
    arbol.insert(new Cuenta(Datos(843, "Jose", 1500, 500)));
    
    arbol.hacerPago(600, Pago(100));
    arbol.hacerPago(600, Pago(100));

    arbol.mostrar();
    return 0;
}

ArbolCuentas::ArbolCuentas() {
    root = nullptr;
}
void ArbolCuentas::insert(Cuenta *nuevaCuenta) {
    if(!this->root)
        root = nuevaCuenta;
    else {
        Cuenta *it = root;
        /*
        [6]

            [5]
        []           []
    []      []          []
        */
        while (it) {
            if (nuevaCuenta->datos.getNumeroCuenta() < it->datos.getNumeroCuenta())
                if (it->left)
                    it = it->left;
                else
                    it->left = nuevaCuenta;
            else if (nuevaCuenta->datos.getNumeroCuenta() > it->datos.getNumeroCuenta())
                if (it->right)
                    it = it->right;
                else
                    it->right = nuevaCuenta;
            else
                break;
        }
    }
}
void ArbolCuentas::mostrar() {
    mostrar(root);
}

void ArbolCuentas::mostrar(Cuenta *it) {
    if (!it)
        return;
    mostrar(it->left);
    cout << it->datos.nombre << endl;
    if (!it->datos.ListaPagos.empty())
        cout << " -- Lista de pagos -- " << endl;
    for (auto pago : it->datos.ListaPagos) {
        cout << pago.cant << endl;
    }
    cout << endl;
    mostrar(it->right);
}

void ArbolCuentas::hacerPago(int numero_cuenta, Pago pago){
    Cuenta *it = root;
    while (it) {
        if (it->datos.getNumeroCuenta() == numero_cuenta)
            break;
        else
            if (numero_cuenta < it->datos.getNumeroCuenta())
                it = it->left;
            else
                it = it->right;
    }
    if (!it) {
        cout << "No se ha encontrado la cuenta: " << numero_cuenta;
        return;
    }
    it->datos.ListaPagos.push_front(pago);
}

Datos::Datos (int numero_cuenta, string nombre, float salario, float prestamo) {
    this->numero_cuenta = numero_cuenta;
    this->nombre = nombre;
    this->prestamo = prestamo;
    this->salario = salario;

    this->intereses = (this->salario > 1000) ? 0.1 : 0.05;

    this->total_a_devolver = this->prestamo * (1+this->intereses);

}
int Datos::getNumeroCuenta() {
    return this->numero_cuenta;
}

