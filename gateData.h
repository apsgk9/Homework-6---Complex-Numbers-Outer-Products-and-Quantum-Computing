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

  /*!
  * @brief  contstructor
  * @param[in] input_operator gate that the matrix uses
  * @post creates gate based on input_operator
  */
  gateData(matrix<complex<double>> input_operator);
   
  /*!
  * @brief  applies gate
  * @param[in] state of the register for the gate to apply to
  * @post returns state that the gate has applied to
  */
  virtual vector<complex<double>> operator()(const vector<complex<double>>& state) const;
 
  /*!
  * @brief  get
  * @post returns gate in terms of matrix
  */
  virtual matrix<complex<double>> get() const;

  /*!
  * @brief  conversion
  * @post returns gate in terms of matrix
  */
  virtual operator matrix<complex<double>>() const;
};


#endif
