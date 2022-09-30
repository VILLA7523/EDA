#include <bits/stdc++.h>

using namespace std;

#define f(i, a, b) for (int i = a; i < b; i++)

int main()
{

  ofstream datos("datos.txt");
  int tams[9] = {100,
                 500,
                 1000,
                 5000,
                 10000,
                 50000,
                 100000,
                 500000,
                 1000000};

  f(i, 0, 9)
  {
    datos << tams[i] << "\n";
    f(j, 0, tams[i])
    {
      datos << rand() << " ";
    }
    datos << "\n";
  }

  datos.close();
  return 0;
}
