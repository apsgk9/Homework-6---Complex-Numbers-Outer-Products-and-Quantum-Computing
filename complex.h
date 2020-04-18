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

  /*!
  * @brief
  * @post returns real part of complex
  */
  T real();

  /*!
  * @brief
  * @post returns imaginary part of complex
  */
  T imag();

  /*!
  * @brief prints contents complex number
  * @param[in] os ostream
  * @param[in] Obj Object called
  * @pre << T (insertion) defined
  * @post 
  * @post '\n'
  */
  template<typename U>
  friend ostream& operator << (ostream& os, const complex<U>& Obj);
    
    
  /*!
  * @
  * @pre - T (unary minus) defined
  * @post 
  */
  complex<T> operator-() const;

  complex<T> operator!() const;

  double operator~() const;

  template<typename U>
  friend complex<U> operator+(const complex<U>& lhs, const complex<U>& rhs);

  template<typename U>
  friend complex<U> operator-(const complex<U>& lhs, const complex<U>& rhs);

  template<typename U>
  friend complex<U> operator*(const complex<U>& lhs, const complex<U>& rhs);

  
  template<typename U>
  friend complex<U> operator*(const U& lhs, const complex<U>& rhs);

  template<typename U>
  friend complex<U> operator*(const complex<U>& lhs, const U& rhs);

  complex<T> operator+=(const complex<T>& rhs);

  complex<T> operator-=(const complex<T>& rhs);

  complex<T> operator*=( const complex<T>& rhs);
};

#include "complex.hpp"


#endif
