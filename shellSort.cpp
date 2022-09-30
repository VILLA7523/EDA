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

void shellSort(int A[], int tam)
{
  for (int gap = tam / 2; gap > 0; gap /= 2)
  {
    for (int i = 0, m; i < tam - gap; i++)
    {
      m = i;
      while (m >= 0 && A[m + gap] < A[m])
      {
        swap(&A[m], &A[m + gap]);
        m = m - gap;
      }
    }
  }
}

int main()
{
  cout << "o";
  ifstream datos("datos.txt");
  ofstream salida;

  salida.open("shellSort.txt");
  int N;
  while (datos >> N)
  {
    cout << N;
    int A[N];
    f(i, 0, N)
    {
      datos >> A[i];
    }
    salida << check(A, N) << " ";
    salida << N << " ";

    auto start2 = std::chrono::steady_clock::now();
    shellSort(A, N);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
    salida << elapsed_seconds2.count() * 1000 << ' ';

    salida << check(A, N) << "\n";
  }
  datos.close();
  salida.close();
  return 0;
}
