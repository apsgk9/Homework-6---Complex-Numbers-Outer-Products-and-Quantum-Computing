/*
* Author: Marky Santos-Tankia
* File: gate.h Date: 4.20.20
* Class: CS 5201
* Instructor : Clayton Price
*
* gate file
*/

/*! \file
 *
 * A gate library.
 */

#ifndef GATE_H
#define GATE_H


#include "gateInterface.h"
#include "gateData.h"
#include "kronecker.h"
#include <numeric>
#include <iostream>

 /*
 * Class:  gate
 */

class gate : public virtual gateInterface, private gateData
{

public:

  gate(matrix<complex<double>> input_operator);

  gate(const gate& input_gate);
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


  /*!
  * @brief combines gates and returns a matrix for new gate
  * @post returns matrix of that the new gate should use
  */
  static matrix<complex<double>> combine(const vector<gateInterface*>& gatesToCombine);
};

#
#endif
