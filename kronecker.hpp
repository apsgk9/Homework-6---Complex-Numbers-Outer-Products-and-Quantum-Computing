/*
* Author: ALAIN MARKUS SANTOS-TANKIA
* File: kronecker.hpp Date: 4/20/20
* Class: CS 5201
* Instructor : CLAYTON PRICE
*
* implementation file of Kronecker
*/
#include "kronecker.h"

template<typename T>
matrix<T> kronecker(const matrix<T>& lhs, const matrix<T>& rhs)
{
  int rowa = lhs.rows();
  int rowb = rhs.rows();
  int cola = lhs.cols();
  int colb = rhs.cols();
  if (rowa == 0 || cola == 0 || rowb == 0 || colb == 0)
  {
    throw std::invalid_argument("Matrices cannot have 0 rows/cols");
  }
  matrix<T> new_m = matrix<T>(rowa * rowb,
    cola * colb);
  int nextrow = 0;
  for (int i = 0; i < rowa; i++)
  {
    // k loops till rowb 
    for (int k = 0; k < rowb; k++)
    {
      int x = 0;
      // j loops till cola 
      for (int j = 0; j < cola; j++)
      {
        // l loops till colb 
        for (int l = 0; l < colb; l++)
        {
          new_m(k + nextrow * 2, x) = lhs(i, j) * rhs(k, l);
          x++;
        }
      }
    }
    nextrow++;
  }
  return new_m;
}

