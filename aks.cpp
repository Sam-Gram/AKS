/****************************************************************
 * AKS Prime Finder
 *
 * By Sam Graham and Tyson Graham (Possibly related)
 *
 * This uses the AKS prime finding method using the gmp
 * library
 ****************************************************************/
#include <gmp.h>
#include "binomial.h"

/**************************************************************
 * This uses the Agrawal–Kayal–Saxena test.
 * 
 * Understanding this test requires that you know how
 * Pascal's Triangle (Binomials) works in regards to the 
 * "choose" operation.
 * 
 * The basic idea is that if you take the following equation:
 * (x-1)^p - (x^p-1) and use p as the number you want to test,
 * if that number can divide all the resulting coefficients
 * evenly (meaning that it has no remainder) then that number
 * is prime.
 * 
 * As a basic example of this lets use the number 3
 * so (x-1)^3 - (x^3-1)
 * lets expand this out to:
 * x^3 - 3x^2 + 3x - 1 - x^3 + 1
 * Here you notice that the first term will always equal x^p
 * and will always cancel out, as will the ones.
 * In this case this will leave us with:
 * - 3x^2 + 3x
 * Again, for AKS we are only interesed in testing the
 * coeffeicients in our case this is:
 * [3, 3]
 * However we want to stamp out redundancy by noticing that 
 * Pascal's triangle repeats itself on each line
 * therefore, we will only need to test half of the line.
 * in our case, just one 3.
 * since 3 divides 3 (Who knew right?), it is prime.
 ***************************************************************/
bool AKSTest(mpz_t pVal)
{
  mpz_t i;
  mpz_init_set_ui(i, 1);
  mpz_t retVal;
  mpz_init_set_ui(retVal, 1);
  mpz_t two;
  mpz_init_set_ui(two, 2);
  mpz_t half;
  mpz_init(half);
  mpz_fdiv_q(half, pVal, two);
  mpz_t zero;
  mpz_init_set_ui(zero, 0);
  
  // While i is < half of pVal
  while (mpz_cmp(i,half) < 0)
  {
    // Get the coeffecient
    binomial(retVal, pVal, i);
    // Mod the Coefficient by the number in question
    mpz_mod(retVal, retVal, pVal);
    // If it is not divisible the number was not prime
    if (mpz_cmp(retVal, zero))
    {
      // Memory management
      mpz_clear(i);
      mpz_clear(retVal);
      mpz_clear(two);
      mpz_clear(half);
      mpz_clear(zero);
      return false;
    }

    // Increase the iterator
    mpz_add_ui(i, i, 1);
  }
   
  // Memory management
  mpz_clear(i);
  mpz_clear(retVal);
  mpz_clear(two);
  mpz_clear(half);
  mpz_clear(zero);

  /* If the while loop has ended, 
   * the number was prime */
  return true;
}

