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

int SendVal (mpz_t half, mpz_t topNum, mpz_t bottomNum)
{
   mpz_t *q = new mpz_t[bottomNum + 1];
   mpz_t u;
   for (mpz_init_set_ui(i,1); i <= topNum; i++)
   {
      if (i <= bottomNum)
      {
         q[i] = 1;
         u = i -1;
      }
      else
      {
         u = bottomNum;
      }
      for (mpz_t j = u; j >= 1; j--)
      {
         q[j] += q[j-1];
      }
   }
   mpz_t retVal = q[bottomNum];
   delete [] q;
   return mpz_get_ull(retVal);
}
