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
* This function casts an mpz_t to an unsigned long long. We will
* possibly need this function in order to return the mpz_t value
* as we don't know how to pass the value of the mpz_t function.
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
* There is a binomial function for other data types. However,
* there doesn't seem to be a binomial function for mpz_t values.
* For this reason, we are trying to adapt Brother Neff's 
* int binomial function and replace it with an unsigned
* long long so that we can get the value for larger numbers.
*************************************************************/
void binomial (mpz_t retVal, mpz_t topNum, mpz_t bottomNum)
{
  unsigned long long temp = mpz_get_ull(bottomNum);
  mpz_bin_ui(retVal, topNum, temp);  
}
