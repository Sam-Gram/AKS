/*******************************************************
 * Binomial Coefficient algorithm, based off of 
 * 
 * Rick Neff's original code <neffr@byui.edu>
 * 
 * For AKS Primality Test 
 * By Sam Graham and Tyson Graham
 *******************************************************/
#include <gmp.h>

using namespace std;


// Computes C(n, k) by the dynamic programming algorithm
// with a one-dimensional table
// Input: A pair of non-negative integers n >= k >= 0
// Output: The value of C(n, k)
//
int binomial(int n, int k)
{
   int* T = new int[n + 1];
   int u;
   for (int i = 0; i <= n; i++)
   {
      if (i <= k) // if in triangular part
      {
         T[i] = 1;  // the diagonal element
         u = i - 1; // the rightmost element to be computed
      }
      else
      {
         // in the rectangular part
         u = k;
      }
      for (int j = u; j >= 1; j--)
      {
	 // overwrite the preceding row moving right to left
         T[j] += T[j - 1];
      }
   }

   int retVal = T[k];
   delete [] T;
   return retVal;
}
