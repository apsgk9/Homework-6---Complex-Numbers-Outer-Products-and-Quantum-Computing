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
  vector<double> quBits;
  vector<int> collapsedState;
  bool hasCollapsed;
  std::default_random_engine RNG;

  

public:

  /*!
  * @pre T = T must be defined
  */
  quRegister();

  /*!
  * @bried copy constructor
  * @pre T = T must be defined
  */
  quRegister(const quRegister<N>& c);


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
  friend ostream& operator << (ostream& os, const quRegister<U>& Obj);

};

#include "quRegister.hpp"


#endif
