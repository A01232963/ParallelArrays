// Maestría en Inteligencia Artificial Aplicada
// Tecnológico de Monterrey
// 
// Curso: Computo en la nube
// Profesor titular: Eduardo Antonio Cendejas Castro
// Profesor asistente: Yetnalezi Quintas Ruiz
// 
// Alumno: Luis Gerardo Sánchez Salazar
// Matrícula: A01232963
//
// 26 de enero de 2025
// Tarea 1: Programación de una solución paralela



//Agregar librerias
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

int main()
{

//Desplegar si OpenMP esta activo
#ifdef _OPENMP
    std::cout << "OpenMP OK para trabajar...\n";
    std::cout << "\n";
#else
    std::cout << "OpenMP no esta listo para trabajar\n";
#endif
    
 //Definir la semilla del generador random
    std::srand(static_cast<unsigned int>(std::time(0)));

//Crear los arrays de tamaño definido por variable array_size
    const int array_size = 1000;
    std::cout << "Numero de elementos por arreglo: " << array_size << "\n";
    std::cout << "\n";
    int array_a[array_size], array_b[array_size], array_c[array_size];

//Llenar el array a y b con numeros random, y array c con la suma de a y b
//Se desplegara el valor agregado a cada array, esto permitirá observar el 
//funcionamiento del for paralelo (Se imprimen en desorden)
#pragma omp parallel for
    for (int i = 0; i < array_size; i++) {
        array_a[i] = std::rand() & 100 + 1;
        array_b[i] = std::rand() & 100 + 1;
        array_c[i] = array_a[i] + array_b[i];
        std::cout << "A:" << array_a[i] << "\n";
        std::cout << "B:" << array_b[i] << "\n";
        std::cout << "C:" << array_c[i] << "\n";
    }
 

//Desplegar los primeros 10 valores de los arrays en forma de lista
    std::cout << "Primeros 10 digitos de los 3 arreglos (A, B y C): \n";
    std::cout << "\n";
//Desplegar array a
    std::cout << "Array A: [";
    for (int i = 0; i < 10; i++) {
        std::cout << array_a[i];
        if (i < 9) {
            std::cout << ", ";
        }
    }
    std::cout << ",...]\n";
 //Desplegar array b
    std::cout << "Array B: [";
    for (int i = 0; i < 10; i++) {
        std::cout << array_b[i];
        if (i < 9) {
            std::cout << ", ";
        }
    }
    std::cout << ",...]\n";
//Desplegar array c
    std::cout << "Array C: [";
    for (int i = 0; i < 10; i++) {
        std::cout << array_c[i];
        if (i < 9) {
            std::cout << ", ";
        }
    }
    std::cout << ",...]\n";
    std::cout << "\n";

//Desplegar todos los valores de los arrays en forma de columna
    std::cout << "Valores de los arrays: \n";
    std::cout << "\n";
    for (int i = 0; i < array_size; i++) {
        std::cout << i+1 << ") A: " << array_a[i] << " + B: " << array_b[i] << " = C: " << array_c[i];
        std::cout << "\n";
    }

}
