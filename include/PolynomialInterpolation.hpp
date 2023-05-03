#include<string>



//Calculates an interpolation for single-variable functions.
std::string NewtonInterpolation(double* x, double** table, int n);

/*
Calculates an interpolation for two-variable functions.
To do it we need FOUR points F(x,y) = Z using only two different X and Y.
The fist column of the table must be initilized with the related Z values;
Example:
X     Y    TABLE[*][0]
X1    Y1        Z1
X1    Y2        Z2
X2    Y1        Z3
X2    Y2        Z4
*/
std::string bilinearInterpolation(double* x, double* y, double** table);