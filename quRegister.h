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
#include "matrix.h"
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
  vector<double> probabilities;
  int numSpaces;
  vector<int> collapsedState;
  bool hasCollapsed;

  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen;
  std::uniform_real_distribution<> dis;

  

public:

  /*!
  * @brief initialization Constructor
  * @pre T = T must be defined
  * @post creates a register set to zero
  * @throw invalid_argument register cannot be non negative or zero
  */
  quRegister();

  /*!
  * @brief  Constructor
  * @pre T = T must be defined
  * @pre values are left MSB ordered
  * @post creates a register based on init_list 1/0:True/False values
  * @throw invalid_argument register cannot be non negative or zero
  */
  quRegister(const std::initializer_list<bool>& init_list);

  /*!
  * @brief Creates register based on probabilities given
  * @param[in] init_list probability for each bit result 
  * @pre N must be non negative or non zero
  * @pre intializer list must be in templated size
  * @post creates a register set based on probabilities given
  * @throw invalid_argument register cannot be non negative or zero
  * @throw invalid_argument initializer list does not equal to templated range
  */
  quRegister(const std::initializer_list <complex<double>>& init_list);
  /*!
  * @brief copy constructor
  * @pre T = T must be defined
  */
  quRegister(const quRegister<N>& c);
  /*!
  * @brief applies gate to register
  * @pre gate size has to be compatible with 2^N size
  * @post creates a register set to zero
  */
  void apply(const gate& g);

  /*!
  * @brief applies gate to register
  * @param[in] target bit to change depending on control
  * @param[in] c_bits bit/s to change if true
  * @pre gate size has to be compatible with 2^N size
  * @post applies control gate to state
  */
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
