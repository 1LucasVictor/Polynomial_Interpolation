#include <iostream>
#include "PolynomialInterpolation.hpp"
using namespace std;


int main() {
  int N;
  cin >> N;


  double* X = new double[N];
  double* Y = new double[N];
  double** table;
  table = new double *[N];
  for (int i = 0; i < N; i++) {
    table[i] = new double[N];
  }

  for(int i = 0; i < N; i++) {
    cin >> X[i];
    cin >> Y[i];
    cin >> table[i][0];
  }
  
  bilinearInterpolation(X, Y, table);


  delete [] X;
  for (int i = 0; i < N; i++) {
    delete[] table[i];
  }
  delete[] table;
  return 0;
}