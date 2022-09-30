#include <bits/stdc++.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

#define f(i, a, b) for (int i = a; i < b; i++)
#define f_2(i, a, b) for (int i = a; i < b; i = i * 2)
#define MIN(a, b) ((a < b) ? a : b)
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

void merge(int A[], int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1 + 1], R[n2 + 1];

  f(i, 0, n1) L[i] = A[p + i];
  f(i, 0, n2) R[i] = A[q + i + 1];

  L[n1] = INF;
  R[n2] = INF;
  int i = 0, j = 0;
  f(k, p, r + 1)
  {
    if (L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int p, int r)
{
  if (p < r)
  {
    int q = (p + r) / 2;
    mergeSort(A, p, q); // 0 2 ->
    mergeSort(A, q + 1, r);
    merge(A, p, q, r);
  }
}
int main()
{
  ifstream datos("datos.txt");
  ofstream salida;

  salida.open("mergeSort.txt");
  int N;
  while (datos >> N)
  {
    cout << N;
    int A[N];
    f(i, 0, N) datos >> A[i];

    salida << check(A, N) << " ";
    salida << N << " ";

    auto start2 = std::chrono::steady_clock::now();
    mergeSort(A, 0, N);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
    salida << elapsed_seconds2.count() * 1000 << ' ';

    salida << check(A, N) << "\n";
  }
  datos.close();
  salida.close();
  return 0;
}
