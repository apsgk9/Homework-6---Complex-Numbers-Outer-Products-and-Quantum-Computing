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

 /*!
 * @brief KroneckerProduct
 * @param[in] lhs matrix
 * @param[in] rhs matrix
 * @pre T * T (multiplication) defined
 * @pre T = T (assingment) defined
 * @pre either matrices cannot be empty
 * @post returns a matrix of kronecker product lhs and rhs
 */
template<typename T>
matrix<T> kronecker(const matrix<T>& lhs, const matrix<T>& rhs);

#include "kronecker.hpp"

#endif
