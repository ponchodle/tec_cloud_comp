// SolucionSumaArreglosParalela_Alfonso_deLucas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <omp.h>

// Cambia el arreglo al tamaño "size" y lo llena con números aleatorios
void generarArregloAleatorio(std::vector<int>& arreglo, int size)
{
    arreglo.resize(size);
    for (int i = 0; i < size; ++i)
    {
        arreglo[i] = rand() % 100; // Números aleatorios entre 0 y 99
    }
}

// Imprime los primeros 20 elementos de un arreglo
void imprimirPrimerosElementos(const std::vector<int>& arreglo, const char* nombre)
{
    std::cout << nombre << ": ";
    for (int i = 0; i < 20; ++i)
    {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}

// Suma ambos arreglos en paralelo usando OpenMP
void sumarArreglosParalelo(const std::vector<int>& arregloA, const std::vector<int>& arregloB, std::vector<int>& arregloC)
{
#pragma omp parallel for
    for (int i = 0; i < static_cast<int>(arregloA.size()); ++i)
    {
        arregloC[i] = arregloA[i] + arregloB[i];
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int n;

    // Se solicita que el usuario ingrese el tamaño de los arreglos
    std::cout << "Ingrese el tamano de los arreglos: ";
    std::cin >> n;

    // Se crean los vectores (Arreglos)
    std::vector<int> arregloA;
    std::vector<int> arregloB;
    std::vector<int> arregloC;

    // Se llenan los arreglos aleatorios con n elementos
    generarArregloAleatorio(arregloA, n);
    generarArregloAleatorio(arregloB, n);

    // Se imprimen los primeros 20 elementos de los arreglos generados
    imprimirPrimerosElementos(arregloA, "Arreglo A");
    imprimirPrimerosElementos(arregloB, "Arreglo B");

    // Se cambia el tamaño del Arreglo C a n, para que coincida
    arregloC.resize(n);

    // Se suman los arreglos en paralelo y se almacena el resultado en arregloC
    sumarArreglosParalelo(arregloA, arregloB, arregloC);

    // Se imprimen los primeros 20 elementos del Arreglo C (resultado)
    imprimirPrimerosElementos(arregloC, "Arreglo C");

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
