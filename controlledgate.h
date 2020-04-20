/*
* Author: Marky Santos-Tankia
* File: controlledgate.h Date: 4.20.20
* Class: CS 5201
* Instructor : Clayton Price
*
* gate file
*/

/*! \file
 *
 * A gate library.
 */

#ifndef CONTROLLEDGATE_H
#define CONTROLLEDGATE_H


#include "gate.h"
#include <set>

 /*
 * Class:  controlledgate
 */

class controlledgate : public gate
{
private:
  const static matrix<complex<double>> m_identity;
  const static matrix<complex<double>> m_zerocondition;
  const static matrix<complex<double>> m_onecondition;
  const static complex<double> c_zero;
  const static complex<double> c_one;
  const static matrix<complex<double>> m_start;

public:
  /*!
  * @brief pure virtual function
  * @param[in] state of the register for the gate to apply to
  * @post creates control gate given input gate
  */
  controlledgate(gate input_gate) : gate(input_gate){}
  

  /*!
  * @brief pure virtual function
  * @param[in] target bit to change if control_bits are true
  * @param[in] state of the register for the gate to apply to
  * @param[in] control_bits if true target bit will be applied to
  * @pre asumes state is a power of 2
  * @pre target and control_bits must be within bounds
  * @post returns state that the gate has applied
  * @post with control and target bits
  * @throw invalid_argument target bit is out of bounds
  * @throw invalid_argument a control bit is out of bounds
  */
  virtual vector<complex<double>> operator()(const int& target,
    const vector<complex<double>>& state, const std::initializer_list<int>& control_bits) const;


  virtual matrix<complex<double>> get() const;

  virtual operator matrix<complex<double>>() const;
};

#endif
