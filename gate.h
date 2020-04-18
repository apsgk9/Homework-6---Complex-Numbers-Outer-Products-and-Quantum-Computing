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

  gate(matrix<complex<double>> input_operator) : gateData(input_operator){}

  gate(const gate& input_gate) : gateData(input_gate.get()) {}

  virtual vector<complex<double>> operator()(const vector<complex<double>>& state) const
  {
    return gateData::operator()(state);
  }

  //return matrix operator of the gate
  virtual matrix<complex<double>> get() const
  {
    return gateData::get();
  }

  virtual operator matrix<complex<double>>() const
  {
    return gateData::get();
  }
  
  static matrix<complex<double>> combine(const vector<gateInterface*>& gatesToCombine)
  {
    int size = gatesToCombine.size();
    matrix<complex<double>> start(1, 1);
    start(0, 0) = complex<double>(1, 0);
    vector<matrix<complex<double>>> OperatorestoCombine(size);
    for (int i = 0; i < size; i++)
    {
      OperatorestoCombine[i] = (gatesToCombine[i]->get());
    }
    auto combinedGates = std::accumulate(OperatorestoCombine.begin(), OperatorestoCombine.end(), start, kronecker<complex<double>>);
    //std::cout << combinedGates; 
    return combinedGates;
  }
};


#endif
