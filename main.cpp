/*************************************************************
 * Main driver for the AKS class 
 *
 * For:
 * AKS Primality Test
 *
 * By Sam Graham and Tyson Graham
 * At BYU-Idaho
 * 04/09/2015
 ************************************************************/
#include <iostream>
#include <gmp.h>
#include "aks.h"

using namespace std;

/***********************************************************
 * This is the main class
 ***********************************************************/
int main(int argc, char** argv)
{
  if (argc < 1)
  {
    cout << "executable numbertotest" << endl;
    return 0;
  }  
  
  mpz_t arg;
  mpz_init_set_str(arg, argv[1], 10);

  if (AKSTest(arg))
  {
    cout << "That was a Prime!" << endl;
  }
  else
  {
    cout << "That was a Composite" << endl;
  }

  // Memory Management
  mpz_clear(arg);

  return 0;
}
