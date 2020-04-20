/*
* Author: Marky Santos-Tankia
* File: gate.cpp Date: 4.20.20
* Class: CS 5201
* Instructor : Clayton Price
*
* gate file
*/

/*! \file
 *
 * A gate library.
 */

#include "gate.h"

gate::gate(matrix<complex<double>> input_operator) : gateData(input_operator) {}

gate::gate(const gate& input_gate) : gateData(input_gate.get()) {}

vector<complex<double>> gate::operator()(const vector<complex<double>>& state) const
{
  return gateData::operator()(state);
}

//return matrix operator of the gate
matrix<complex<double>> gate::get() const
{
  return gateData::get();
}

gate::operator matrix<complex<double>>() const
{
  return gateData::get();
}

matrix<complex<double>> gate::combine(const vector<gateInterface*>& gatesToCombine)
{
  int size = gatesToCombine.size();
  matrix<complex<double>> start(1, 1);
  start(0, 0) = complex<double>(1, 0);
  vector<matrix<complex<double>>> OperatorestoCombine(size);
  for (int i = 0; i < size; i++)
  {
    OperatorestoCombine[i] = (gatesToCombine[i]->get());
  }
  auto combinedGateMatrix = std::accumulate(OperatorestoCombine.begin(), OperatorestoCombine.end(), start, kronecker<complex<double>>);
  return combinedGateMatrix;
}