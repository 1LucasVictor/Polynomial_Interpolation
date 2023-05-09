#include <iostream>
#include "PolynomialInterpolation.hpp"
using namespace std;



void fillRow(long x, long y, vector<double>& M) {
    M[0] = 1;
    M[1] = x;
    M[2] = y;
    M[3] = x*y;
    M[4] = x*x;
    M[5] = y*y;
    M[6] = x*y*y;
    M[7] = x*x*y;
    M[8] = x*x*y*y;
}

int main() {
  int N;
  long xi, yi, zi;

  // F(x,y) = a0 + a1x + a2y + a3xy + a4x² + a5y² + a6xy² + a7x²y + a8x²y²
  vector<vector<double>> matrix(9, vector<double>(9));
  vector<double> fi(9);
  
  cin >> N; 
  for(int i = 0; i< N; i++) {
    cin >> xi >> yi >> zi;
    fi[i] = zi;
    fillRow(xi, yi, matrix[i]);
  }
  // Determinant of original matrix
  double det = calculateDeterminant(matrix, N);
  
  /*
  M = Number of Interpolations
  (x, y) = pairs to interpolate
  z = F(x,y)
  */
  int M;
  long x, y, z;
  long xaux, yaux;
  double detj;

  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> x >> y;
    z = 0;
    for(int j = 0; j < N; j++) {
      xaux = matrix[j][1]; yaux = matrix[j][2];
      fillRow(x, y, matrix[j]);
      detj = calculateDeterminant(matrix, N);
      z += detj * fi[j] / det;
      fillRow(xaux, yaux, matrix[j]);
    }
    cout << "F(" << x << "," << y << ") = " << z << '\n';
  }
 
  cout << "Finished\n";
  return 0;
}