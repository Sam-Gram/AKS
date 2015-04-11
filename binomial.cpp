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

/***************************************************************
* This function casts an mpz_t to an unsigned long long. We
* need this function in order to return the mpz_t value due to 
* the difficulty of passing the value of the mpz_t function.
***************************************************************/
unsigned long long mpz_get_ull(mpz_t n)
{
   unsigned int lo, hi;
   mpz_t tmp;

   mpz_init( tmp );
   mpz_mod_2exp( tmp, n, 64 );   /* tmp = (lower 64 bits of n) */

   lo = mpz_get_ui( tmp );       /* lo = tmp & 0xffffffff */
   mpz_div_2exp( tmp, tmp, 32 ); /* tmp >>= 32 */
   hi = mpz_get_ui( tmp );       /* hi = tmp & 0xffffffff */

   mpz_clear( tmp );

   return (((unsigned long long)hi) << 32) + lo;
}

/************************************************************
* We used the GMP library's unsigned long long binomial
* coefficient function whose data will be used in the aks.cpp
* file. This is where most of the program's optimizations will
* be needed as we could use dynamic programming for this 
* portion of our program's tasks. This would greatly speed
* up our program and is really the bottleneck that makes
* our program take so long for large numbers. However, we 
* must marvel at the fact that while it takes a long time,
* our program can handle transcendentally large numbers and
* determine whether they are prime or composite in  puesdo-
* polynomial time! The dynamic programming optimization will
* have to wait for another day! But we hope to make time
* for it in the near future!
*************************************************************/
void binomial (mpz_t retVal, mpz_t topNum, mpz_t bottomNum)
{
  unsigned long long temp = mpz_get_ull(bottomNum);
  mpz_bin_ui(retVal, topNum, temp);  
}
