/*
* Author: Marky Santos-Tankia
* File: main.cpp Date: 3/13/20
* Class: CS 5201
* Instructor : Clayton Price
*
* main file
*/
#include <iostream>
#include <sstream>
#include <string>
#include "matrix.h"
#include <algorithm>    // std::max
#include "global.h"
#include <array>
#include "complex.h"
#include "kronecker.h"
#include <numeric>

using std::cout;
using std::cin;
using std::endl;

void driver();
void complextest();
template<typename T>
void print(complex<T> c, string name);
int main()
{
  
  try
  {
    driver();
    //complextest();
    //modelTest();
    //matrixInitializerTest();
  }
  catch (const std::out_of_range & oor) {
    std::cerr << "\nOut of Range error: " << oor.what() << '\n';
  }
  catch (const std::invalid_argument & ia) {
    std::cerr << "Invalid argument: " << ia.what() << '\n';
  }
  catch (const std::length_error & le) {
    std::cerr << "Length error: " << le.what() << '\n';
  }
  catch (const std::domain_error & de) {
    std::cerr << "Domain error: " << de.what() << '\n';
  }
  catch (...)
  {
    std::cerr << "An uknown error has occured." << '\n';
  }

  return 0;
}

void complextest()
{
  complex<double> c(1, 1);
  complex<double> c2(3,4);
  complex<double> c3(2, 5);
  complex<double> c4(0,0);
  print(c, "normal");
  cout << "magnitude: " << ": " << ~c << endl;
  print(-c, "-");
  print(!c, "!");
  print((c2*c3), "c2*c3");
  print((c2 + c3), "c2*c3");
  c4 += c;
  print((c4), "c4 += c");
  c4 -= c2;
  print((c4), "c4 -= c");
  c2 *= c3;
  print((c2), "c2 *= c3");

}
template<typename T>
void print(complex<T> c, string name)
{
  cout << name << ": " << c << endl;
}
void driver()
{
  matrix<int> A = { { 1, 2 }, { 3, 4 }, { 1, 0 } };
  matrix<int> B = { { 0, 5, 2 }, { 6, 7, 3 } };
  vector<matrix<int>> AandB = { A,B };
  cout << "A:\n" << A<<endl<<endl;
  cout << "B:\n" << B << endl << endl;
  matrix<int> start = { {1} };

  cout << "KRONECKER:\n" << kronecker(A, B);
  cout << "\nAccumalate:\n" << std::accumulate(AandB.begin(), AandB.end(),start, kronecker<int>);

  matrix<int> Check = { { 1, 2 }, { 3, 4, 0 }, { 1, 0 } };
  
}