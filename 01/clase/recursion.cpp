#include <iostream>
using namespace std;

// ¿Qué es recursión?
/*
    Un problema que pueda definirse en función de su tamaño, sea este N, puede dividirse en instancias más pequeñas (< N) del mismo problema y se conocerá la solución explícita a las instancias más simples, lo que se conoce como casos base, y se puede aplicar inducción sobre las llamadas más pequeñas y suponer que estas quedan resueltas
*/


// bucles a recusión

// factorial recursivo

void forRecursivo (int num) {
    if (num == 10) {
        cout << num << endl;
        return;
    } else {
        forRecursivo(num + 1);
        cout << num << endl;
        return;
    }
}

int main () {
    // for (int i = 0; i < 10; i++) {
    //     cout << i << endl;
    // }

    forRecursivo(1);

    // cout << fib(10);
    // int hola[] = {1,2,3};
    return 0;
}








// Fibonacci es una sucesión de números que consiste en la suma de los dos anteriores
// int fib (int n);
int fib (int n) {
    if (n<2)
        return n;
    else
        return fib(n-1) + fib(n-2);
}