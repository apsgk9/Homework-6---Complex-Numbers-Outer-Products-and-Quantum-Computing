/*
* Author: ALAIN MARKUS SANTOS-TANKIA
* File: quRegister.hpp Date: 4/20/20
* Class: CS 5201
* Instructor : CLATON PRICE
*
* Implementation file of quRegister
*/

#include "quRegister.h"

template<int N>
quRegister<N>::quRegister():quBits(matrix<double>(N*2)),collapsedState(vector<int>()),
hasCollapsed(false){}

template<int N>
quRegister<N>::quRegister(const quRegister<N>& q):
quBits(q.quBits), hasCollapsed(q.hasCollapsed),
collapsedState(q.collapsedState),RNG(q.RNG){}



template<int N>
ostream& operator << (ostream& os, const quRegister<N>& Obj)
{
  if (Obj.hasCollapsed)
  {
    throw std::invalid_argument("Register has already been collapsed.");
  }
  //weighted random choice  TODO
  collapsedState = vector<int>(N);
  for (int i = 0; i < N; i++)
  {
    os << "Probabilities: " << Obj.quBits[i*2] << " " << Obj.quBits[(i * 2) +1] <<"\n";
    double prob = 1 * ((double)rand() / (double)RAND_MAX);
    int collapse= (Obj.quBits[i * 2] < prob) ? 1 : 0;
    os << "Measured State: " << collapse;
    collapsedState[i];
  }
  os << "\n";
  for (int i = N-1; i >= 0; i--)
  {
    os << collapsedState.[i]<<" ";
    ;
  }
  Obj.hasCollapsed = true;
  return os;
}