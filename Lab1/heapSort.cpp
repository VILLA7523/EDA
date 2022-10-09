#include <bits/stdc++.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

#define f(i, a, b) for (int i = a; i < b; i++)
#define INF std::numeric_limits<int>::max();

bool check(int A[], int tam)
{
  f(i, 1, tam) if (A[i] < A[i - 1]) return 0;

  return 1;
}

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}
int LEFT(int i)
{
  return (i << 1);
}

int RIGHT(int i)
{
  return (i << 1) + 1;
}

void MaxHeapify(int A[], int tam, int i)
{
  int l = LEFT(i);
  int r = RIGHT(i);

  int largest;
  if (l < tam && (A[l] > A[i]))
    largest = l;
  else
    largest = i;

  if (r < tam && (A[r] > A[largest]))
    largest = r;

  if (largest != i)
  {
    swap(&A[i], &A[largest]);
    MaxHeapify(A, tam, largest);
  }
}

void BuildMaxHeap(int A[], int tam)
{
  for (int i = tam / 2 - 1; i >= 0; i--)
  {
    MaxHeapify(A, tam, i);
  }
}

void heapSort(int A[], int tam)
{
  BuildMaxHeap(A, tam);
  for (int i = tam - 1; i >= 0; i--)
  {
    swap(&A[0], &A[i]);
    MaxHeapify(A, i, 0);
  }
}

int main()
{
  cout << "o";
  ifstream datos("Entrada/datos5.txt");
  ofstream salida;

  salida.open("Salida/heapSort.txt");

  int N;
   while (datos >> N)
  {
    int A[N];
    f(i, 0, N) datos >> A[i];

    salida << check(A, N) << " ";
    cout << check(A, N) << " ";
    salida << N << " ";
    cout << N << " ";

    auto start2 = std::chrono::steady_clock::now();
    heapSort(A, N);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
    salida << elapsed_seconds2.count() * 1000 << ' ';
    cout << elapsed_seconds2.count() * 1000 << " ";

    salida
        << check(A, N) << "\n";
        
    cout
        << check(A, N) << "\n";
  }
  datos.close();
  salida.close();
  return 0;
}
