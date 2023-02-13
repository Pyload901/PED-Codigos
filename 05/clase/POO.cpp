#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

class Mascota {
    // Solo puede accederse en la clase
    private:
        int numero_cuenta;
        string tipo;
        string nombre;
        int edad;
        int peso;
        string color;

    // Puede accederse desde cualquier objeto
    // Setters y Getters
    public:
        Mascota(int numero_cuenta);
        void caminar();
        void sentarse();
        
        void setNombre(string nombre) {
            this->nombre = nombre;
        }
        int getNumeroCuenta() {
            return this->numero_cuenta;
        }
        string getNombre() {
            return this->nombre;
        }
};

int main () {
    // Mascota perro = Mascota(1234);
    // cout << perro.getNumeroCuenta();
    // perro.setNombre("Luna");
    // cout << perro.getNombre();
    list<int> lista;
    for (int i = 0; i <10 ; i++) {
        lista.push_back(i);
    }

    for (auto elemento : lista) {
        cout << elemento << endl;
    }
    for_each(lista.begin(), lista.end(), [](int elemento){
        cout << elemento << endl;
    });
    for (auto it = lista.begin(); it != lista.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}

Mascota::Mascota (int numero_cuenta) {
    this->numero_cuenta = numero_cuenta;
}
void Mascota::sentarse () {

}
void Mascota::caminar () {
    cout << "Estoy caminando" << endl;
}

