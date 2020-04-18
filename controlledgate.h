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

  controlledgate(gate input_gate) : gate(input_gate){}
  
  //asumes state is power of 2
  virtual vector<complex<double>> operator()(const int& target,
    const vector<complex<double>>& state,const std::initializer_list<int>& control_bits) const
  {
    /*
    vector<complex<double>> reverseState(state.size());
    int r_index = state.size() - 1;
    for (auto i : state)
    {
      reverseState[r_index] = i;
      r_index--;
    }*/
    int numBits = 0;
    int size = state.size();
    while (size >= 2)
    {
      size = size / 2;
      numBits++;
    }

    matrix<complex<double>> start(1, 1);
    start(0, 0) = complex<double>(1, 0);

    //throw if not the same

    std::set<int> control_bitstoTrack= control_bits;

    vector<matrix<complex<double>>> u_zero(numBits);
    vector<matrix<complex<double>>> u_one(numBits);

    for (int i = 0; i < numBits; i++)
    {
      u_zero[i] = m_identity;
      u_one[i] = m_identity;
    }

    for (int i : control_bits)
    {
      u_zero[numBits-i-1] = m_zerocondition;
      u_one[numBits-i-1] = m_onecondition;
    }

    u_one[numBits-target-1] = gate::get();

    /*

    for (int i = 0; i < numBits; i++)
    {
      if (control_bitstoTrack.contains(i))
      {
        u_zero[i] = m_zerocondition;
      }
      else
      {
        u_zero[i] = m_identity;
      }
    }*/

    /*
    for (int i = 0; i < numBits; i++)
    {
      if (control_bitstoTrack.contains(i))
      {
        u_one[i] = m_onecondition;

      }
      else if (i == target)
      {
        u_one[i] = gate::get();
      }
      else
      {
        u_one[i] = m_identity;
      }
    }
    */

    //cout << u_one<<std::endl;
    //cout << u_zero;

    auto u_first = std::accumulate(u_zero.begin(), u_zero.end(), start, kronecker<complex<double>>);
    auto u_second = std::accumulate(u_one.begin(), u_one.end(), start, kronecker<complex<double>>);
    //cout << "\nu_first\n" << u_first << std::endl << std::endl;
    //cout << "\nu_second\n" << u_second << std::endl << std::endl;
    auto final_u = u_first + u_second;

    //cout << "\nstate: " <<state << std::endl << std::endl;
    //cout << final_u<<std::endl << std::endl;
    //cout << "\nstate: " << (final_u * state) << std::endl << std::endl;

    return (final_u * state);
  }


  virtual matrix<complex<double>> get() const
  {
    return gate::get();
  }
  virtual operator matrix<complex<double>>() const
  {
    return gate::get();
  }


};
const complex<double> controlledgate::c_zero = complex<double>(0.0, 0.0);
const complex<double> controlledgate::c_one = complex<double>(1.0, 0.0);

const matrix<complex<double>> controlledgate::m_identity = 
{ {c_one,c_zero},{c_zero,c_one} };
const matrix<complex<double>> controlledgate::m_zerocondition =
{ {c_one,c_zero},{c_zero,c_zero} };
const matrix<complex<double>> controlledgate::m_onecondition =
{ {c_zero,c_zero},{c_zero,c_one} };
#endif
