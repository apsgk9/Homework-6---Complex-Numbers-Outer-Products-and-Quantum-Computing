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
#include "quRegister.h"
#include <numeric>
#include "gate.h"
#include "controlledgate.h"

using std::cout;
using std::cin;
using std::endl;

void matrixTest();
void complextest();
void quRegisterTest();
template<typename T>
void print(complex<T> c, string name);
void driver();
void TestGATES();
int main()
{
  
  try
  {
    
    //matrixTest();
    //complextest();
    //modelTest();
    //matrixInitializerTest();
    //quRegisterTest();
    driver();
    //TestGATES();
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

  catch (const std::range_error & re) {
    std::cerr << "Range error: " << re.what() << '\n';
  }
  catch (...)
  {
    std::cerr << "An unknown error has occured." << '\n';
  }

  return 0;
}

void TestGATES()
{


  quRegister<3> grover_register;
  complex<double> i(0.0, 1.0);
  complex<double> one(1.0, 0.0);
  complex<double> negative_one(-1.0, 0.0);
  complex<double> zero(0.0, 0.0);
  matrix< complex<double>> NotMatrix = { {zero,one, },
                                        {one,zero} };
  matrix< complex<double>> ZMatrix = { { one ,zero, },
                                       { zero,negative_one} };
  matrix< complex<double>> SMatrix = { { one ,zero,},
                                       { zero,i} };

  matrix<complex<double>> h_m = { {one,one},
                                  {one,negative_one} };
  complex<double> multiplyBy = complex<double>((1 / std::sqrt(2)), 0);
  h_m = multiplyBy * h_m;
  gate H(h_m);
  gate X(NotMatrix);
  gate Z(ZMatrix);
  gate S(SMatrix);
  vector<gateInterface*> x2tocombine = { &X,&X };
  vector<gateInterface*> H2tocombine = { &H,&H };
  vector<gateInterface*> h3tocombine = { &H,&H,&H };
  vector<gateInterface*> x3tocombine = { &X,&X,&X };
  controlledgate controlNOT(X);

  gate doubleX(gate::combine(x2tocombine));
  gate doubleH(gate::combine(H2tocombine));
  gate tripleH(gate::combine(h3tocombine));
  gate tripleX(gate::combine(x3tocombine));
  //Ensure that applying a Hadamard gate to a single-bit register results in the state presented in lecture,
  //and a measurement with equal probability of 0 and 1

  quRegister<2> register_1;
  register_1.apply(doubleH);
  std::cout << "\nregister_1: "<< register_1 <<std::endl;

  //Ensure that applying a NOT gate to a single-bit register inverts the state
  //vector< complex<double>> state = { zero,zero,zero,zero,zero,zero,zero,one };
  quRegister<3> register_2 = { zero,zero,one,zero,zero,zero,zero,zero };
  register_2.apply(tripleX);
  std::cout << "\nregister_2: " << register_2 << std::endl;

  //Try to create a controlled NOT gate, and ensure that the 4×4 linear operator that is generated matches what was presented in lecture
  //quRegister<2> register_3 = { one,zero,zero,zero}; //00
  //quRegister<2> register_3 = { zero,one,zero,zero };//01 -- > 11 (0,1,0,0)-->(0,0,0,1)
  //quRegister<2> register_3 = { zero,zero,one,zero };//10 -- > 10 (0,0,1,0)-->(0,0,1,0)
  quRegister<2> register_3 = { zero,zero,zero,one };//11 -- > 01 (0,0,0,1)-->(0,1,0,0)
  register_3.applycontrol(1,controlNOT, {0});
  std::cout << "\nregister_3: " << register_3 << std::endl;
}


void driver()
{
  complex<double> i(0.0, 1.0);
  complex<double> one(1.0, 0.0);
  complex<double> negative_one(-1.0, 0.0);
  complex<double> zero(0.0, 0.0);
  complex<double> pifour((std::exp(3.14159265358979323846 / 4)), (std::exp(3.14159265358979323846 / 4)));
  matrix< complex<double>> NotMatrix = {{zero,one},
                                        {one,zero} };
  matrix< complex<double>> ZMatrix = { { one ,zero},
                                       { zero,negative_one} };
  matrix< complex<double>> SMatrix = { { one ,zero,},
                                       { zero,i} };
  matrix< complex<double>> IdentityMatrix = { { one ,zero},
                                              { zero,one} };
  matrix< complex<double>> TMatrix = {  {one ,zero},
                                       {zero,pifour} };

  matrix<complex<double>> h_m = { {one,one},
                                  {one,negative_one} };
  complex<double> multiplyBy = complex<double>((1 / std::sqrt(2)), 0);
  h_m = multiplyBy * h_m;
  gate H(h_m);
  gate X(NotMatrix);
  gate Z(ZMatrix);
  gate S(SMatrix);
  gate I(IdentityMatrix);
  gate T(TMatrix);
  //controlledgate controlX(X);

  //vector< complex<double>> state = { zero,zero,zero,zero,zero,zero,zero,one };
  //vector< complex<double>> state = { zero,one,zero,zero }; //00 //01 //10 //11
  //controlX(0, state, { 1 });

  //vector< complex<double>> state2 = { zero,zero,one,zero,zero,zero,zero,zero };
  //state2 =controlX(0, state2, { 1 }); //000 //001 //010 //011 //100 //101 // 110//111 

  //controlX(0, state2, { 2 }); //000 //001 //010 //011 //100 //101 // 110//111 
  //110 //111
  //----------------------------------------
  
  vector<gateInterface*> htocombine = { &H,&H,&H };
  vector<gateInterface*> xtocombine = { &X,&X,&X };

  gate tripleH(gate::combine(htocombine));
  gate tripleX(gate::combine(xtocombine));
  controlledgate controlZ(Z);



  //vector< complex<double>> state = { zero,zero,zero,zero,one,zero,zero,zero };
  
  quRegister<3> grover_register = { false,false,false };

  grover_register.apply(tripleH);
  grover_register.applycontrol(0, controlZ, { 2 });
  grover_register.applycontrol(0, controlZ, { 1 });
  grover_register.apply(tripleH);
  grover_register.apply(tripleX);
  grover_register.applycontrol(0, controlZ, { 1,2 });
  grover_register.apply(tripleX);
  grover_register.apply(tripleH);
  std::cout << grover_register;

  //-----------------------------------------
  vector<gateInterface*> hmiddletocombine = { &I,&H,&I };
  vector<gateInterface*> htopcombine = { &I,&I,&H }; //ADD with MSB on the left

  gate hMiddle(gate::combine(hmiddletocombine));
  gate hTop(gate::combine(htopcombine));
  controlledgate controlS(S);
  controlledgate controlT(T);

  quRegister<3> shor_register = { false,false,false };
  shor_register.apply(tripleH);
  shor_register.apply(hMiddle);
  shor_register.applycontrol(0, controlS, { 1 });
  shor_register.apply(hTop);
  shor_register.applycontrol(2, controlS, { 1 });
  shor_register.applycontrol(2, controlS, { 0 });
  std::cout << shor_register;
}
void quRegisterTest()
{
  complex<double> o(1.0, 0.0);
  complex<double> z(0.0, 0.0);
  matrix< complex<double>> NotMatrix = { { z,o, },
                                         { o,z} };
  gate notGate(NotMatrix);
  controlledgate controlnotGate(notGate);
  vector< complex<double>> state = { z,z,z,z,z,o,z,z};
  cout << "\nBefore: " << state << std::endl;
  
  state = controlnotGate(2, state, { 0 });
  cout << "\nAfter: " << state << std::endl;
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
  print((c*5.0), "c*5");
}
template<typename T>
void print(complex<T> c, string name)
{
  cout << name << ": " << c << endl;
}
void matrixTest()
{
  matrix<int> A = { { 1, 2 }, { 3, 4 }, { 1, 0 } };
  matrix<int> B = { { 0, 5, 2 }, { 6, 7, 3 } };
  vector<matrix<int>> AandB = { A,B };
  cout << "A:\n" << A<<endl<<endl;
  cout << "B:\n" << B << endl << endl;
  matrix<int> start = { {1} };

  cout << "KRONECKER:\n" << kronecker(A, B);
  cout << "\nAccumalate:\n" << std::accumulate(AandB.begin(), AandB.end(),start, kronecker<int>);

  matrix<int> C = { { 0, 5, 2 }, { 6, 7, 3 } };
  matrix<int> C3 = { { 0, 5, 2  } };
  vector<int> C2 = { 0,2,0 };
  cout << "\nVectorMult:\n" << C*C2;
  cout << "\nVectorMult:\n" << C2* C3;
  matrix<int> CTEST = { { 0, 5, 2,5 }, { 6, 7, 3 } };  
}