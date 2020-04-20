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


  for (int i = 0; i < numSpaces; i++)
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
quRegister<N>::quRegister(const std::initializer_list<bool>& init_list) :numSpaces(std::pow(2, N)),
collapsedState(vector<int>(N)),hasCollapsed(false), gen(rd()), dis(0.0, 1.0)
{
  if (N <= 0)
  {
    throw std::invalid_argument("register cannot be non negative or zero");
  }


  complex<double> one(1.0, 0.0);
  complex<double> zero(0.0, 0.0);
  vector<matrix<complex<double>>> toconvert_bits(N);
  matrix<complex<double>> start(1, 1);
  start(0, 0) = complex<double>(1, 0);

  matrix<complex<double>> zeroBit = { {one},{zero} };
  matrix<complex<double>> oneBit = { {zero},{one} };
  int index = 0;
  for (bool element : init_list)
  {
    if (element)//true 1
    {
      toconvert_bits[index] = oneBit;
    }
    else
    {
      toconvert_bits[index] = zeroBit;
    }
    index++;
  }
  quBits = vector<complex<double>>(numSpaces);

  auto converted = std::accumulate(toconvert_bits.begin(), toconvert_bits.end(), start, kronecker<complex<double>>); 


  for (int i = 0; i < numSpaces; i++)
  {
    quBits[i] = converted(i, 0);
  }
  for (int i = 0; i < N; i++)
  {
    collapsedState[i] = 0;
  }
  //cout << quBits;
}

template<int N>
quRegister<N>::quRegister(const std::initializer_list<complex<double>>& init_list):
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
quBits(q.quBits), probabilities(q.probabilities),numSpaces(q.numSpaces),
hasCollapsed(q.hasCollapsed),collapsedState(q.collapsedState),
hasCollapsed(q.hasCollapsed),rd(q.rd),gen(q.gen),dis(q.dis){}

template<int N>
void quRegister<N>::apply(const gate& g)
{
  //cout << "\nBefore quBits: " << quBits << std::endl;
  if (!hasCollapsed)
  {
    quBits = g(quBits);
  }
  else
  {
    throw std::invalid_argument("Register has already collapse. No application.");
  }
  
  //cout << "\nAfter quBits: " << quBits << std::endl;
}

template<int N>
void quRegister<N>::applycontrol(const int& target, const controlledgate& c_gate, const std::initializer_list<int>& c_bits)
{
  //if(target<0 || target>N-1)
  //cout << "\nBefore quBits: " << quBits << std::endl;
  if (!hasCollapsed)
  {
    //cout << "\nBefore: " << quBits << std::endl;
    quBits = c_gate(target, quBits, c_bits);
    //cout << "\nAfter: " << quBits << std::endl;
  }
  else
  {
    throw std::invalid_argument("Register has already collapse. No application.");
  }
  
  //cout << "\nAfter quBits: " << quBits << std::endl;
}

template<int N>
ostream& operator << (ostream& os, quRegister<N>& Obj)
{

  
  double sumofWeights = 0;
  int collapse;
  double diceroll;
  int n;
  if (Obj.hasCollapsed == false)
  {
    Obj.probabilities = vector<double> (Obj.numSpaces);
    for (int i = 0; i < Obj.numSpaces; i++)
    {
      Obj.probabilities[i] = std::pow(~(Obj.quBits[i]), 2);
      //probabilitiesTOsort[i] = test;
      sumofWeights += Obj.probabilities[i];
    }
    diceroll = sumofWeights * (Obj.dis(Obj.gen));
    for (int i = 0; i < Obj.numSpaces; i++)
    {
      if (diceroll < Obj.probabilities[i])
      {
        collapse = i;
        break;
      }
      diceroll -= Obj.probabilities[i];
    }
    n = collapse;
    for (int i = 0; n > 0; i++)
    {
      Obj.collapsedState[i] = n % 2;
      n = n / 2;
    }
    Obj.hasCollapsed = true;
  }

  os << "Probabilities: ";
  for (int i = 0; i < Obj.numSpaces; i++)
  {
    os << " " << Obj.probabilities[i];
  }
  os << "\nMeasured State: ";
  for (int i = N - 1; i >= 0; i--)
  {
    os << Obj.collapsedState[i]<<" ";
  }
  os << "\n";
  return os;
}