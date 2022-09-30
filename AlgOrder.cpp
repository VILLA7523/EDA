#include <bits/stdc++.h>

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

void bubbleSort(int A[], int tam)
{
  f(i, 0, tam - 1)
      f(j, 0, tam - i - 1) if (A[j] > A[j + 1]) swap(&A[j], &A[j + 1]);
}

// heapSort

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

// Insertion sort
void insertionSort(int A[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int key = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > key)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
  }
}

// Selection sort
void selectionSort(int A[], int tam)
{
  int min, ind;
  f(i, 0, tam)
  {
    min = 1e9;
    f(j, i, tam)
    {
      if (A[j] < min)
      {
        min = A[j];
        ind = j;
      }
    }
    swap(&A[i], &A[ind]);
  }
}

// Shell sort
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

void print(int A[], int tam)
{
  cout << "\n";
  f(i, 0, tam)
  {
    cout << A[i] << " ";
  }
  cout << "\n";
}

// Merge sort
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
  if (p == r)
    return;
  int q = (p + r) / 2;
  mergeSort(A, p, q);
  mergeSort(A, q + 1, r);
  merge(A, p, q, r);
}

// Quick sort

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
  int N = 1000000;
  int arr[N];
  f(i, 0, 11) arr[i] = rand();

  // print(arr, N);

  // bubbleSort(arr, N);
  // shellSort(arr, N);
  // selectionSort(arr, N);
  // insertionSort(arr, N);
  // mergeSort(arr, 0, N);
  // quickSort(arr, 0, N);
  heapSort(arr, N);

  cout
      << "\n"
      << check(arr, N);
  return 0;
}
