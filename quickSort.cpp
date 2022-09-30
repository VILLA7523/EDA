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

int Partition(int A[], int p, int r)
{
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++)
  {
    if (A[j] <= x)
    {
      i++;
      swap(&A[i], &A[j]);
    }
  }

  swap(&A[i + 1], &A[r]);
  return i + 1;
}

void quickSort(int A[], int p, int r)
{
  if (p < r)
  {
    int q = Partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

int main()
{
  int A[1000000];
  ifstream datos("datos.txt");
  ofstream salida;
  salida.open("quickSort.txt");
  // salida.open("quickSort.txt");
  int N;
  while (datos >> N)
  {
    cout << N;
    f(i, 0, N)
    {
      datos >> A[i];
    }
    salida << check(A, N) << " ";

    salida << N << " ";

    auto start2 = std::chrono::steady_clock::now();
    quickSort(A, 0, N);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
    salida << elapsed_seconds2.count() * 1000 << ' ';

    salida << check(A, N) << "\n";
  }
  datos.close();
  salida.close();
  return 0;
}
