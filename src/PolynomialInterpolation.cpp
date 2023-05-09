#include "PolynomialInterpolation.hpp"
#include <sstream>
#include <iostream>
using namespace std;

/*
Function to calculate divided differences.
x: vector of x values
table: Table used to store the divided differences, table[*][0] must be initialized with the y values 
n: number of pairs (x, y)
*/
void DividedDifferenceTable(double *x, double **table, int n) {
  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n - j; i++) {
      table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
    }
  }
}

string NewtonInterpolation(double *x, double **table, int n) {
    stringstream formula;
    DividedDifferenceTable(x, table, n);
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
    return formula.str();
}


string newtonIforY(double *y, double **table, int n, string fxy1, string fxy2) {
    stringstream formula;
    formula << "((" << y[1] << "-y)*(" << fxy1 << ") + " << "(" << "y-" << y[0] <<")*(" << fxy2 << "))";
    formula << "/" << y[1]-y[0] << endl;
    return formula.str();
}

string bilinearInterpolation(double* x, double* y, double** table) {
    double* xAux = new double[2];
    xAux[0] = x[0]; xAux[1] = x[2];

    double** tableAux = new double*[2];
    tableAux[0] = new double[2];
    tableAux[1] = new double[2];
    tableAux[0][0] = table[0][0];
    tableAux[1][0] = table[2][0];
    string FXY1 = NewtonInterpolation(xAux, tableAux, 2);

    xAux[0] = x[1]; xAux[1] = x[3];
    tableAux[0][0] = table[1][0];
    tableAux[1][0] = table[3][0];
    string FXY2 = NewtonInterpolation(xAux, tableAux, 2);

    cout << "F(X, y1) = " << FXY1 << endl;
    cout << "F(X, y2) = " << FXY2 << endl;



    xAux[0] = y[0]; xAux[1] = y[1];
    tableAux[0][0] = table[0][0];
    tableAux[1][0] = table[1][0];
    string FXY = newtonIforY(xAux, tableAux, 2, FXY1, FXY2);

    cout << "\nF(x, y) = " << FXY << endl;
    delete [] tableAux[0];
    delete [] tableAux[1];
    delete [] tableAux;
    delete [] xAux;
    return "Oi\n";
}


double calculateDeterminant(const std::vector<std::vector<double>>& matrix) {
    int size = matrix.size();
    if (size == 1) {
        return matrix[0][0];
    } else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        double determinant = 0.0;
        for (int col = 0; col < size; col++) {
            std::vector<std::vector<double>> subMatrix(size - 1, std::vector<double>(size - 1));
            for (int i = 1; i < size; i++) {
                int subCol = 0;
                for (int j = 0; j < size; j++) {
                    if (j != col) {
                        subMatrix[i - 1][subCol++] = matrix[i][j];
                    }
                }
            }
            determinant += (col % 2 == 0 ? 1 : -1) * matrix[0][col] * calculateDeterminant(subMatrix);
        }
        return determinant;
    }
}