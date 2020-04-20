/*
* Author: Marky Santos-Tankia
* File: complex.h Date: 4.20.20
* Class: CS 5201
* Instructor : Clayton Price
*
* complex file
*/

/*! \file
 *
 * A complex library.
 */

#ifndef COMPLEX_H
#define COMPLEX_H


#include <iostream>
#include <string>
#include <math.h>  

using std::string;
using std::ostream;
using std::cout;
using std::istream;

/*
* Class:  complex
*/
template<typename T>
class complex
{
private:
  T m_real;
  T m_imaginary;

public:

  /*!
  * @pre T = T must be defined
  */
  complex(const T& input_real = 0,const T& input_imaginary = 0);

  /*!
  * @bried copy constructor
  * @pre T = T must be defined
  */
  complex(const complex& c);

  /*!
  * @brief assigns source to this complex (by value)
  * @param[in] source complex<T>
  * @post copies contents from source to *this complex
  */

  complex<T>& operator = (const complex<T>& source);

  //add const and non const later
  /*!
  * @post returns value of real part of complex
  */
  T real();

  /*!
  * @post returns value of imaginary part of complex
  */
  T imag();

  /*!
  * @brief prints contents complex number
  * @param[in] os ostream
  * @param[in] Obj Object called
  * @pre << T (insertion) defined
  * @post output a complex number to ostream
  * @post formats: "a + bi" or "a" or "b" or "bi"
  * @post '\n'
  */
  template<typename U>
  friend ostream& operator << (ostream& os, const complex<U>& Obj);
    
    
  /*!
  * @pre -T (unary minus) defined
  * @post returns complex conjugate
  */
  complex<T> operator-() const;

  /*!
  * @pre -T (unary minus) defined
  * @post returns additive inverse
  */
  complex<T> operator!() const;

  /*!
  * @pre T * T (multiplication) defined
  * @pre T + T (addition) defined
  * @post returns magnitude
  */
  double operator~() const;
  /*!
  * @pre T + T (addition) defined
  * @post returns result of additon of complex numbers
  */
  template<typename U>
  friend complex<U> operator+(const complex<U>& lhs, const complex<U>& rhs);

  /*!
  * @pre T - T (subtraction) defined
  * @post returns result of subtraction of complex numbers
  */
  template<typename U>
  friend complex<U> operator-(const complex<U>& lhs, const complex<U>& rhs);

  /*!
  * @pre T * T (multiplication) defined
  * @post returns result of multiplication of complex numbers
  */
  template<typename U>
  friend complex<U> operator*(const complex<U>& lhs, const complex<U>& rhs);

  /*!
  * @pre T * T (multiplication) defined
  * @post returns result of multiplication of scalar of complex number
  */
  template<typename U>
  friend complex<U> operator*(const U& lhs, const complex<U>& rhs);
  /*!
  * @pre T * T (multiplication) defined
  * @post returns result of multiplication of scalar
  * @post of this complex number
  */
  template<typename U>
  friend complex<U> operator*(const complex<U>& lhs, const U& rhs);
  /*!
  * @pre T + T (addition) defined
  * @post returns result of addition of complex number
  * @post of this complex number
  */
  complex<T> operator+=(const complex<T>& rhs);

  /*!
  * @pre T - T (substraction) defined
  * @post returns result of substraction of complex number 
  * @post  of this complex number
  */
  complex<T> operator-=(const complex<T>& rhs);

  /*!
  * @pre T * T (multiplication) defined
  * @post returns result of multiplication of scalar of this complex number
  */
  complex<T> operator*=( const complex<T>& rhs);
};

#include "complex.hpp"


#endif
