#include <iostream>
using namespace std;
//esto crea los asistentes, lo dejaré aqui hasta que el hash esté hecho para sacar los asistentes de ahi
struct Asistente {
	int id;//este es el que se debe cambiar basicamente cuando el hash esté hecho, porq ahi nos pide insertar un id(dni o qr)
	int prioridad;
	char nombre[30];
};

class maxHeap {
private:
	Asistente* heap;
	int tam;
	int ultimaPosicion;
//este copia el nombre ingresado a otro char para que el heap pueda imprimirlo
	void copiarNombre(char* destino, const char* fuente) {
		int i = 0;
		while (fuente[i] != '\0' && i < 29) {
			destino[i] = fuente[i];
			i++;
		}
		destino[i] = '\0';
	}

public:
	maxHeap(int n) {
		heap = new Asistente[n];
		tam = n;
		ultimaPosicion = 0;
	}

	void insertar(int id, const char* nombre, int prioridad) {
		if (ultimaPosicion + 1 >= tam) {
			cout << "El heap esta lleno." << endl;
			return;
		}

		ultimaPosicion++;
		heap[ultimaPosicion].id = id;
		heap[ultimaPosicion].prioridad = prioridad;
		copiarNombre(heap[ultimaPosicion].nombre, nombre);
//el while reordena los elementos, si la prioridad de X elemento es superior a la de su padre, se intercambian para que el heap mantenga la propiedad de max-heap
		int i = ultimaPosicion;
		while (i > 1 && heap[i].prioridad > heap[i/2].prioridad) {
			swap(heap[i], heap[i/2]);
			i = i / 2;
		}
	}

void imprimirOrdenado() {
    int contador = 0;
    imprimirOrdenadoR(5, contador); // empieza desde la prioridad máxima
}

void imprimirOrdenadoR(int prioridad, int& contador) {
    if (prioridad == 0 || contador >= 5) return;

    for (int i = 1; i <= ultimaPosicion && contador < 5; i++) {
        if (heap[i].prioridad == prioridad) {
            cout << heap[i].nombre << " (P: " << heap[i].prioridad << ")\n";
            contador++;
        }
    }

    imprimirOrdenadoR(prioridad - 1, contador);
}


};

int main() {
	maxHeap cola(20);
	
	cola.insertar(6, "Pedro", 3);
	cola.insertar(8, "Juan", 5);
	cola.insertar(6, "Jose", 3);
	cola.insertar(4, "Ramón", 2);
	cola.insertar(3, "Timoteo", 1);
	cola.insertar(9, "Pancracio", 4);

	cout << "Asistentes en orden de prioridad:\n";
	cola.imprimirOrdenado();

	return 0;
}