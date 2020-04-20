#pragma once

#include "complex.h"

template<typename T>
complex<T>::complex(const T& input_real,const T& input_imaginary)
{
  m_real = input_real;
  m_imaginary = input_imaginary;
}

template<typename T>
complex<T>::complex(const complex& c)
{
  m_real = c.m_real;
  m_imaginary = c.m_imaginary;
}

template<typename T>
complex<T>& complex<T>::operator = (const complex<T>& source)
{
  if (this != &source)
  {
    m_real = source.m_real;
    m_imaginary = source.m_imaginary;
  }
  return *this;
}

template<typename T>
T complex<T>::real()
{
  return m_real;
}

template<typename T>
T complex<T>::imag()
{
  return m_imaginary;
}



template<typename T>
ostream& operator << (ostream& os, const complex<T>& Obj)
{
  cout.precision(8); // as requested
  if (Obj.m_real != 0 && Obj.m_imaginary != 0)
  {
    if (Obj.m_imaginary > 0)
    {
      os << Obj.m_real << " + " << Obj.m_imaginary << "i";
    }
    else
    {
      os << Obj.m_real << " " << Obj.m_imaginary << "i";
    }

  }
  else if (Obj.m_real == 0 && Obj.m_imaginary != 0)
  {
    os << Obj.m_imaginary << "i";    
  }
  else
  {
    os << Obj.m_real;
  }
  return os;
}



template<typename T>
complex<T> complex<T>::operator-() const
{  
  return complex<T> (-m_real, m_imaginary);
}
template<typename T>
complex<T> complex<T>::operator!() const
{
  return complex<T>(m_real,-m_imaginary);
}
template<typename T>
double complex<T>::operator~() const
{
  return (std::sqrt((m_real* m_real) +(m_imaginary* m_imaginary)));
}

template<typename T>
complex<T> operator+(const complex<T>& lhs, const complex<T>& rhs)
{
  return complex<T>(lhs.m_real+rhs.m_real,lhs.m_imaginary+rhs.m_imaginary);
}

template<typename T>
complex<T> operator-(const complex<T>& lhs, const complex<T>& rhs)
{
  return complex<T>(lhs.m_real - rhs.m_real, lhs.m_imaginary - rhs.m_imaginary);
}

template<typename T>
complex<T> operator*(const complex<T>& lhs, const complex<T>& rhs)
{
  return complex<T>((lhs.m_real * rhs.m_real) - (lhs.m_imaginary * rhs.m_imaginary),
    (lhs.m_real * rhs.m_imaginary) + (lhs.m_imaginary * rhs.m_real));
}

template<typename T>
inline complex<T> operator*(const T& lhs, const complex<T>& rhs)
{
  return complex<T>((lhs * rhs.m_real),(lhs * rhs.m_imaginary));
}

template<typename T>
complex<T> operator*(const complex<T>& lhs, const T& rhs)
{
  return complex<T>((lhs.m_real * rhs), (lhs.m_imaginary * rhs));
}


template<typename T>
complex<T> complex<T>::operator+=(const complex<T>& rhs)
{
  *this = complex<T>(this->m_real + rhs.m_real, this->m_imaginary + rhs.m_imaginary);
  return (*this);
}

template<typename T>
complex<T> complex<T>::operator-=(const complex<T>& rhs)
{
  *this = complex<T>(this->m_real - rhs.m_real, this->m_imaginary - rhs.m_imaginary);
  return (*this);
}

template<typename T>
complex<T> complex<T>::operator*=(const complex<T>& rhs)
{
  *this = complex<T>((this->m_real * rhs.m_real) - (this->m_imaginary * rhs.m_imaginary),
    (this->m_real * rhs.m_imaginary) + (this->m_imaginary * rhs.m_real));
  return (*this);
}

/*
Appropriate constructors and destructors
copy assignment
real and imag functions to return the real and imaginary parts of the complex number, respectively
stream operator (<<) to output a complex number - should be of the format a + bi, unless a or b is zero, in which case only bi or a should be displayed, respectively
overloaded unary - operator to return the additive inverse (of the real part, the imaginary part should be unchanged)
overloaded unary ! operator to return the complex conjugate
overloaded unary ~ operator to return the magnitude (recall that complex numbers are isomorphic to vectors in R2)
operators +, -, *, and their assignment counterparts
*/