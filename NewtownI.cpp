#include <iostream>
#include <sstream>
using namespace std;


void printMatrix(double **M, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << " | " << M[i][j] << " | ";
    }
    cout << endl;
  }
}

/*
Function to calculate divided differences.
x: vector of x values
table: Table used to store the divided differences, table[*][0] must be
initialized with the y values n: number of pairs (x, y)
*/
void DividedDifferenceTable(double *x, double **table, int n) {
  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n - j; i++) {
      table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
    }
  }
}

void printFormula(double *x, double **table, int n) {
    stringstream formula;
    formula << "F(x) = ";
    for(int i = 0; i < n; i ++) {
        if(!table[0][i]) 
            continue;
        if(i && table[0][i] > 0) 
            formula << "+";
        formula << table[0][i];
        for(int j = 0; j < i; j++) {
            formula << "*(x";
            (x[j] >= 0) ? formula << "-" << x[j] : formula << "+" << -x[j];
            formula << ")";
        }
    }
    cout << formula.str();
    cout << endl;
}

int main() {
  int N;
  cin >> N;


  double* X = new double[N];
  double** table;
  table = new double *[N];
  for (int i = 0; i < N; i++) {
    table[i] = new double[N];
  }

  for(int i = 0; i < N; i++) {
    cin >> X[i];
    cin >> table[i][0];
  }

  cout << endl;
  DividedDifferenceTable(X, table, N);
  cout << "DIVIDED TABLE\n";
  printMatrix(table, N, N);
  cout << endl;
  printFormula(X, table, N);


  
  delete [] X;
  for (int i = 0; i < N; i++) {
    delete[] table[i];
  }
  delete[] table;
  return 0;
}