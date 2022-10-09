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

void selectionSort(int A[], int tam)
{
  int ind;
  f(i, 0, tam - 1)
  {
    ind = i;
    f(j, i + 1, tam)
    {
      if (A[j] < A[ind])
      {
        ind = j;
      }
    }

    if (ind != i)
      swap(&A[i], &A[ind]);
  }
}

int main()
{
  ifstream datos("Entrada/datos4.txt");
  ofstream salida;

  salida.open("Salida/selectionSort.txt");
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
    selectionSort(A, N);
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