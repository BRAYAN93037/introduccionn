#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid; // Elemento encontrado
        if (arr[mid] < target) left = mid + 1; // Buscamos en la mitad derecha
        else right = mid - 1; // Buscamos en la mitad izquierda
    }
    return -1; // Elemento no encontrado
}
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) return -1; // Elemento no encontrado

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid; // Elemento encontrado
    if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, right, target); // Buscamos en la mitad derecha
    return binarySearchRecursive(arr, left, mid - 1, target); // Buscamos en la mitad izquierda
}
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // Debe estar ordenado
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    // Búsqueda Binaria Iterativa
    int resultIter = binarySearchIterative(arr, arr_size, target);
    cout << "Iterativa: Elemento encontrado en índice: " << resultIter << endl;

    // Búsqueda Binaria Recursiva
    int resultRec = binarySearchRecursive(arr, 0, arr_size - 1, target);
    cout << "Recursiva: Elemento encontrado en índice: " << resultRec << endl;

    return 0;
}

