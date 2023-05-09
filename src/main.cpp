#include <iostream>
#include "PolynomialInterpolation.hpp"
using namespace std;



int main() {
  int N, xi, yi, zi;
  vector<vector<double>> matrix(N, vector<double>(N));
  vector<double> fi;
  
  cin >> N; 
  for(int i = 0; i< N; i++) {
    cin >> xi, yi, zi;
    
  }

   cout << "Determinant: " << calculateDeterminant(matrix) << endl;
  return 0;
}