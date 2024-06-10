#include <stdio.h>

// Fonction pour échanger deux éléments
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Fonction de tri par sélection
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Parcourir tous les éléments du tableau
    for (i = 0; i < n-1; i++) {
        // Trouver le minimum dans le tableau non trié
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Échanger le minimum trouvé avec le premier élément
        swap(&arr[min_idx], &arr[i]);
    }
}

// Fonction pour afficher le tableau
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Programme principal pour tester la fonction de tri par sélection
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Tableau original: \n");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Tableau trié: \n");
    printArray(arr, n);
    
    return 0;
}