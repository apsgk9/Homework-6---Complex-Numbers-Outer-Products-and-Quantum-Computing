/*
* Author: Marky Santos-Tankia
* File: gateData.h Date: 4.20.20
* Class: CS 5201
* Instructor : Clayton Price
*
* gateData file
*/

/*! \file
 *
 * A gateData library.
 */

#ifndef GATEDATA_H
#define GATEDATA_H


#include"gateInterface.h"

/*
* Class:  gateData
*/

class gateData : public virtual gateInterface
{
  matrix<complex<double>> m_operator;

public:

  gateData(matrix<complex<double>> input_operator) :m_operator(input_operator){}
   
  //applies gate
  virtual vector<complex<double>> operator()(const vector<complex<double>>& state) const
  {
    return (m_operator* state);
  }
  //gets gate
  virtual matrix<complex<double>> get() const
  {
    return m_operator;
  }
  virtual operator matrix<complex<double>>() const
  {
    return m_operator;
  }

  
  virtual gateInterface* clone() const
  {
    return new gateData(*this);
  }

};


#endif
