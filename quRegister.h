/*
* Author: ALAIN MARKUS SANTOS-TANKIA
* File: quRegister.h Date: 4/20/20
* Class: CS 5201
* Instructor : CLATON PRICE
*
* file of quRegister
*/

/*! \file
 *
 * A complex library.
 */

#ifndef QUREGISTER_H
#define QUREGISTER_H


#include <iostream>
#include <string>
#include <math.h> 
#include <random>
#include "complex.h"
#include "kronecker.h"
#include <numeric>
#include <time.h>       /* time */
#include "gate.h"
#include "controlledgate.h"

using std::string;
using std::ostream;
using std::cout;
using std::istream;

/*
* Class:  quRegister
*/
template<int N>
class quRegister
{
private:
  vector<complex<double>> quBits;
  int numSpaces;
  vector<int> collapsedState;
  bool hasCollapsed;

  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen;
  std::uniform_real_distribution<> dis;

  

public:

  /*!
  * @pre T = T must be defined
  */
  quRegister();

  quRegister(std::initializer_list<bool> init_list);
  quRegister(std::initializer_list < complex<double>> init_list);
  /*!
  * @bried copy constructor
  * @pre T = T must be defined
  */
  quRegister(const quRegister<N>& c);

  void apply(const gate&);

  void applycontrol(const int& target, const controlledgate& c_gate, const std::initializer_list<int>& c_bits);




  /*!
  * @brief prints contents from grid
  * @param[in] os ostream
  * @param[in] Obj Object called
  * @pre << T (insertion) defined
  * @post prints each element of arr
  * @post seperated by " " and '\n'
  * @post seperates the rows, last row no leading
  * @post '\n'
  */

  template<int U>
  friend ostream& operator << (ostream& os, quRegister<U>& Obj);

};

#include "quRegister.hpp"


#endif
