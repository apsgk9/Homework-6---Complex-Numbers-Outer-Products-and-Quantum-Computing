/*
* Author: ALAIN MARKUS SANTOS-TANKIA
* File: kronecker.h Date: 4/20/20
* Class: CS 5201
* Instructor : CLAYTON PRICE
*
* file of Kronecker
*/

/*! \file
 *
 * A Kronecker library.
 */

#ifndef KRONECKER_H
#define KRONECKER_H
#include <iostream>

#include "matrix.h"

template<typename T>
matrix<T> kronecker(const matrix<T>& lhs, const matrix<T>& rhs)
{
  int rowa = lhs.rows();
  int rowb = rhs.rows();
  int cola = lhs.cols();
  int colb = rhs.cols();
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

          // Each element of matrix A is 
          // multiplied by whole Matrix B 
          // resp and stored as Matrix C 
          new_m(k + nextrow * 2, x) = lhs(i, j) * rhs(k, l);
          x++;
        }
      }
    }
    nextrow++;
  }

  return new_m;
}


#endif
