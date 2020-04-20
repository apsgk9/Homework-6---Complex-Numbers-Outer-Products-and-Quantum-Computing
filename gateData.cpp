/*
* Author: Marky Santos-Tankia
* File: gateData.cpp Date: 4.20.20
* Class: CS 5201
* Instructor : Clayton Price
*
* gateData implementation file
*/

#include "gateData.h"

gateData::gateData(matrix<complex<double>> input_operator) :m_operator(input_operator) {}

vector<complex<double>> gateData::operator()(const vector<complex<double>>& state) const
{
  return (m_operator * state);
}

matrix<complex<double>> gateData::get() const
{
  return m_operator;
}

gateData::operator matrix<complex<double>>() const
{
  return m_operator;
}