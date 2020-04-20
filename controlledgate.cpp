/*
* Author: Marky Santos-Tankia
* File: controlledgate.cpp Date: 4.20.20
* Class: CS 5201
* Instructor : Clayton Price
*
* gate file
*/

/*! \file
 *
 * Gate implementation.
 */
#include "controlledgate.h"
vector<complex<double>> controlledgate::operator()(const int &target,
const vector<complex<double>> &state, const std::initializer_list<int> &control_bits) const
{
  int numBits = 0;
  int size = state.size();
  if (state.size() % 2 != 0)
  {
    throw std::invalid_argument("state size must be a power of 2");
  }
  while (size >= 2)
  {
    size = size / 2;
    numBits++;
  }
  if (target<0 || target>=numBits)
  {
    throw std::invalid_argument("target bit is out of bounds");
  }
  else
  {
    for (int i : control_bits)
    {

      if (i < 0 || i >= numBits)
      {
        throw std::invalid_argument("a control bit is out of bounds");
      }
    }
  }

  matrix<complex<double>> start(1, 1);
  start(0, 0) = complex<double>(1, 0);

  //throw if not the same

  std::set<int> control_bitstoTrack = control_bits;

  vector<matrix<complex<double>>> u_zero(numBits);
  vector<matrix<complex<double>>> u_one(numBits);

  for (int i = 0; i < numBits; i++)
  {
    u_zero[i] = m_identity;
    u_one[i] = m_identity;
  }

  for (int i : control_bits)
  {
    u_zero[numBits - i - 1] = m_zerocondition;
    u_one[numBits - i - 1] = m_onecondition;
  }

  u_one[numBits - target - 1] = gate::get();

  // auto u_first = std::accumulate(u_zero.begin(), u_zero.end(), start, kronecker<complex<double>>);
  // auto u_second = std::accumulate(u_one.begin(), u_one.end(), start, kronecker<complex<double>>);

  matrix<complex<double>> final_u = std::accumulate(u_zero.begin(), u_zero.end(), start, kronecker<complex<double>>) + std::accumulate(u_one.begin(), u_one.end(), start, kronecker<complex<double>>);
  //cout << std::endl<<final_u << std::endl;

  return (final_u * state);
}

matrix<complex<double>> controlledgate::get() const
{
  return gate::get();
}
controlledgate::operator matrix<complex<double>>() const
{
  return gate::get();
}
const complex<double> controlledgate::c_zero = complex<double>(0.0, 0.0);
const complex<double> controlledgate::c_one = complex<double>(1.0, 0.0);

const matrix<complex<double>> controlledgate::m_identity =
    {{c_one, c_zero}, {c_zero, c_one}};
const matrix<complex<double>> controlledgate::m_zerocondition =
    {{c_one, c_zero}, {c_zero, c_zero}};
const matrix<complex<double>> controlledgate::m_onecondition =
    {{c_zero, c_zero}, {c_zero, c_one}};