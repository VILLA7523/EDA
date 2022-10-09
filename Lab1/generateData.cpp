#include <bits/stdc++.h>

using namespace std;

#define f(i, a, b) for (int i = a; i < b; i++)

int main()
{

  ofstream datos1("Entrada/datos1.txt");
  ofstream datos2("Entrada/datos2.txt");
  ofstream datos3("Entrada/datos3.txt");
  ofstream datos4("Entrada/datos4.txt");
  ofstream datos5("Entrada/datos5.txt");

  int tams[11] = {100,
                  200,
                  500,
                  800,
                  1000,
                  2000,
                  5000,
                  8000,
                  10000,
                  20000,
                  50000};

  int tams2[3] = {80000,
                  100000,
                  200000
                  };

  


  f(i, 0, 11)
  {
    datos1 << tams[i] << "\n";
    f(j, 0, tams[i]) datos1 << rand() << " ";
    datos1 << "\n";
  }
  datos1.close();

  f(i, 0, 3)
  {
    datos2 << tams2[i] << "\n";
    f(j, 0, tams2[i]) datos2 << rand() << " ";
    datos2 << "\n";
  }
  datos2.close();


  datos3 << 500000 << "\n";
  f(j, 0, 500000) datos3 << rand() << " ";
  datos3 << "\n";
  datos3.close();

  datos4 << 800000 << "\n";
  f(j, 0,800000) datos4 << rand() << " ";
  datos4 << "\n";
  datos4.close();

  datos5 << 1000000 << "\n";
  f(j, 0,1000000) datos5 << rand() << " ";
  datos5 << "\n";
  datos5.close();



  

  return 0;
}
