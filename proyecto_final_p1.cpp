#include <iostream>
using namespace std;

// Limpia el buffer de entrada después de una lectura fallida
void limpiarBuffer() {
    cin.clear();
    // Limpiar hasta encontrar un salto de línea
    while(cin.get() != '\n') {
        continue;
    }
}

// Lee un entero validando la entrada
bool leerEntero(int &numero) {
    if (cin >> numero) {
        limpiarBuffer();  // Limpia cualquier carácter adicional
        return true;
    }
    limpiarBuffer();
    return false;
}

// Invierte el orden de los elementos del arreglo
void invertirArreglo(int arr[], int tam, int arrInvertido[]) {
    for (int i = 0; i < tam; i++) {
        arrInvertido[i] = arr[tam - 1 - i];
    }
}

// Calcula la suma de elementos divisibles por un número dado
int sumaDivisibles(int arr[], int tam, int divisor) {
    int suma = 0;
    
    if (divisor == 0) {
        return -1;  // Código de error para división por cero
    }
    
    for (int i = 0; i < tam; i++) {
        if (arr[i] % divisor == 0) {
            suma += arr[i];
        }
    }
    return suma;
}

// Compara si la suma de posiciones impares es mayor que la de posiciones pares
bool compararPosiciones(int arr[], int tam) {
    int sumaImpares = 0;
    int sumaPares = 0;
    
    for (int i = 0; i < tam; i++) {
        if (i % 2 == 0) {
            sumaPares += arr[i];
        } else {
            sumaImpares += arr[i];
        }
    }
    
    return sumaImpares > sumaPares;
}

int main() {
    int tam;
    
    cout << "=== SISTEMA DE GESTION DE ARREGLOS NUMERICOS ===" << endl << endl;
    
    // Solicitar y validar tamaño del arreglo
    do {
        cout << "Ingrese la cantidad de elementos: ";
        if (leerEntero(tam) && tam > 0) {
            break;
        }
        cout << "Entrada invalida. Debe ingresar un numero entero positivo." << endl;
    } while (true);
    
    int arreglo[tam];
    
    // Ingreso de elementos del arreglo
    cout << "\nIngrese los valores del arreglo:" << endl;
    for (int i = 0; i < tam; i++) {
        do {
            cout << "Elemento [" << i + 1 << "]: ";
            if (leerEntero(arreglo[i])) {
                break;
            }
            cout << "Valor invalido. Ingrese un numero entero." << endl;
        } while (true);
    }
    
    int opcion;
    
    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Invertir secuencia del arreglo" << endl;
        cout << "2. Calcular suma de elementos divisibles" << endl;
        cout << "3. Comparar sumas por indice" << endl;
        cout << "4. Finalizar ejecucion" << endl;
        cout << "Opcion seleccionada: ";
        
        if (!leerEntero(opcion)) {
            cout << "Seleccion no reconocida. Intente nuevamente." << endl;
            continue;
        }
        
        switch (opcion) {
            case 1: {
                int arrInvertido[tam];
                invertirArreglo(arreglo, tam, arrInvertido);
                
                cout << "\nResultado de inversion:" << endl;
                cout << "Arreglo invertido: ";
                for (int i = 0; i < tam; i++) {
                    cout << arrInvertido[i] << " ";
                }
                cout << endl;
                break;
            }
            case 2: {
                int divisor;
                do {
                    cout << "\nIngrese el valor divisor: ";
                    if (leerEntero(divisor)) {
                        break;
                    }
                    cout << "Valor no valido. Ingrese un numero entero." << endl;
                } while (true);
                
                int resultado = sumaDivisibles(arreglo, tam, divisor);
                if (resultado == -1) {
                    cout << "Operacion cancelada: No se permite division por cero." << endl;
                } else {
                    cout << "Suma total de elementos divisibles por " << divisor << ": " << resultado << endl;
                }
                break;
            }
            case 3: {
                bool imparesMayor = compararPosiciones(arreglo, tam);
                
                cout << "\nResultado de comparacion:" << endl;
                if (imparesMayor) {
                    cout << "La suma en posiciones impares supera a la de posiciones pares." << endl;
                } else {
                    cout << "La suma en posiciones pares es mayor o igual a la de posiciones impares." << endl;
                }
                break;
            }
            case 4:
                cout << "\nFinalizando sistema. Gracias por utilizar nuestro software." << endl;
                break;
            default:
                cout << "\nOpcion fuera de rango. Consulte el menu de opciones disponibles." << endl;
        }
        
    } while (opcion != 4);
    
    return 0;
}
