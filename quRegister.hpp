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
quRegister<N>::quRegister():numSpaces(std::pow(2, N)), collapsedState(vector<int>(N)),
hasCollapsed(false),gen(rd()),dis(0.0,1.0)
{
  if (N <= 0)
  {
    throw std::invalid_argument("register cannot be non negative or zero");
  }


  complex<double> one(1.0, 0.0);
  complex<double> zero(0.0, 0.0);
  vector<matrix<complex<double>>> zero_bits(N);
  matrix<complex<double>> start(1, 1);
  start(0, 0) = complex<double>(1, 0);

  matrix<complex<double>> zeroBit= { {one},{zero} };
  for (int i = 0; i < N; i++)
  {
    zero_bits[i] = zeroBit;
  }
  quBits = vector<complex<double>>(numSpaces);
  //set bits to all 0

  auto converted = std::accumulate(zero_bits.begin(), zero_bits.end(), start, kronecker<complex<double>>);


  for (int i = 0; i < N; i++)
  {
    quBits[i] = converted(i,0);
  }
  for (int i = 0; i < N; i++)
  {
    collapsedState[i] = 0;
  }
  //cout << quBits;
}

template<int N>
quRegister<N>::quRegister(std::initializer_list<complex<double>> init_list):
 numSpaces(std::pow(2, N)), collapsedState(vector<int>(N)),hasCollapsed(false),
  gen(rd()), dis(0.0, 1.0)
{
  if (N <= 0)
  {
    throw std::invalid_argument("register cannot be non negative or zero");
  }
  if (numSpaces != (int)init_list.size())
  {
    throw std::invalid_argument("initializer list does not equal to templated range");
  }

  quBits = vector<complex<double>>(numSpaces);
  int i = 0;
  for (auto c : init_list)
  {
    quBits[i] = c;
    i++;
  }
  for (int i = 0; i < N; i++)
  {
    collapsedState[i] = 0;
  }
}

template<int N>
quRegister<N>::quRegister(const quRegister<N>& q):
quBits(q.quBits), hasCollapsed(q.hasCollapsed),
collapsedState(q.collapsedState){}

template<int N>
void quRegister<N>::apply(const gate& g)
{
  cout << "\nBefore quBits: " << quBits << std::endl;
  quBits = g(quBits);
  cout << "\nAfter quBits: " << quBits << std::endl;
}

template<int N>
void quRegister<N>::applycontrol(const int& target, const controlledgate& c_gate, const std::initializer_list<int>& c_bits)
{
  cout << "\nBefore quBits: " << quBits << std::endl;
  quBits = c_gate(target, quBits, c_bits);
  cout << "\nAfter quBits: " << quBits << std::endl;
}

template<int N>
ostream& operator << (ostream& os, quRegister<N>& Obj)
{
  if (Obj.hasCollapsed)
  {
    throw std::invalid_argument("Register has already been collapsed.");
  }
  //weighted random choice  TODO
  //matrix <complex<double>> probabilities(std::pow(2,N));
  //int numSpaces = std::pow(2, N);
  //matrix<complex<double>> start(1, 1);
  //start(0, 0) = complex<double>(1,0);
  //auto complexPreMagnitude = std::accumulate(Obj.quBits.begin(), Obj.quBits.end(),start, kronecker<complex<double>>);

  vector<double> probabilities(Obj.numSpaces);
  vector<double> probabilitiesTOsort(Obj.numSpaces);
  double sumofWeights = 0;
  int collapse;
  double diceroll;
  int n;
  cout << "\nAfter2 quBits: " << Obj.quBits << std::endl;
  for(int i=0;i< Obj.numSpaces;i++)
  {
    double test= std::pow(~(Obj.quBits[i]), 2);
    probabilities[i] = test;
    //probabilitiesTOsort[i] = test;
    sumofWeights+= probabilities[i];
  }
  //std::sort(probabilitiesTOsort.begin(), probabilitiesTOsort.end(), std::less<double>());
  //fix this random
  //diceroll = sumofWeights * ((double)rand() / (double)RAND_MAX);
  diceroll = sumofWeights * (Obj.dis(Obj.gen));
  for (int i = 0; i < Obj.numSpaces; i++)
  {
    if (diceroll < probabilities[i])
    {
      collapse = i;
      break;
    }
    diceroll -= probabilities[i];
  }

  os << "Probabilities: ";
  for (int i = 0; i < Obj.numSpaces; i++)
  {
    os << " " << probabilities[i];
  }
  //---------------------
  n = collapse;
  os << "\nMeasured State before: "<< collapse;
  for (int i = 0; n > 0; i++)
  {
    Obj.collapsedState[i] = n % 2;
    n = n / 2;
  }
  os << "\nMeasured State: ";
  for (int i = N - 1; i >= 0; i--)
  {
    os << Obj.collapsedState[i]<<" ";
  }
  os << "\n";
  Obj.hasCollapsed = true;
  return os;
}