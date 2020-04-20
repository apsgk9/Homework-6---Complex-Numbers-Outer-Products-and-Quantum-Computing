/*
* Author: Marky Santos-Tankia
* File: gateInterface.h Date: 4.20.20
* Class: CS 5201
* Instructor : Clayton Price
*
* gate file
*/

/*! \file
 *
 * A gateInterface.
 */

#ifndef GATEINTERFACE_H
#define GATEINTERFACE_H

#include "matrix.h"
#include "complex.h"


/*
* Class:  gateInterface
*/
class gateInterface
{

public:

  /*!
  * @brief pure virtual function
  * @param[in] state of the register for the gate to apply to
  * @post returns state that the gate has applied to
  */

  virtual vector<complex<double>> operator()(const vector<complex<double>>& state) const = 0 ;
  /*!
  * @brief pure virtual function get function
  * @post should return matrix of the gate
  */
  virtual matrix<complex<double>> get() const = 0;

  /*!
  * @brief pure virtual function conversion
  * @post should return matrix of the gate
  */
  virtual operator matrix<complex<double>>() const = 0;

  //virtual gateInterface* clone() const = 0;


};


#endif
