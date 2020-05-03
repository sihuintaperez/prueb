#include <iostream>
#include <cstdlib>
#include <sys/time.h>

using namespace std;



//--------BUBBLESORT

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n,int asignacion,int comparacion)
{
    int i, j;
    for (i = 0; i < n-1; i++){
        asignacion++;
        comparacion++;
        for (j = 0; j < n-i-1; j++){
            asignacion++;
            comparacion++;
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
                asignacion+=3;
                comparacion++;
        }
    }
    cout<<"Comparaciones : "<<comparacion<<endl;
    cout<<"Asignaciones : "<<asignacion<<endl;
}

//-----INSERTION SORT
void insertionSort(int arr[], int n,int asignacion,int comparacion){

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        comparacion++;
        asignacion++;

        key = arr[i];

        asignacion++;
        j = i - 1;
        asignacion++;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            asignacion++;
            j = j - 1;
            asignacion++;
            comparacion+=2;
        }
        arr[j + 1] = key;
        asignacion++;
    }
    cout<<"Numero de asignaciones :"<<asignacion<<endl<<"Numero de comparaciones: "<<comparacion;
}

int main(){


    //------------------CREAR ARREGLO

    const int tamano = 100000, MAXIMO = 1000000;
    int arreglo[ tamano ] = { 0 };
    int i;

    srand( time( 0 ) );

    for ( i = 0; i < tamano; ++i )
        arreglo[ i ] = rand() % MAXIMO;

    //-----------------MEDIR TIEMPO

    struct timeval t, t2;

    int microsegundos;


    gettimeofday(&t, NULL);

    //insertionSort(arreglo,tamano,1,1);
    bubbleSort(arreglo,tamano,2,3);

    gettimeofday(&t2,NULL);
    microsegundos = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));

    cout<<"Microsegundos del ordenamiento :"<<microsegundos<<endl;
/*

    cout << "Los valores del arreglo son:\n";
    for ( i = 0; i < tamano; ++i )
        cout << arreglo[ i ]<<"   ";
*/

}
