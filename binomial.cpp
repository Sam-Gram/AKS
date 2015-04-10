#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

// Computes C(n, k) by the dynamic programming algorithm
// with a one-dimensional table
// Input: A pair of nonnegative integers n >= k >= 0
// Output: The value of C(n, k)
//
int binomial1(int n, int k)
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
         u = k; // in the rectangular part
      }
      for (int j = u; j >= 1; j--)
      {
         T[j] += T[j - 1]; // overwrite the preceding row moving right to left
#ifdef SHOW
         cout << "T[" << j << "] = " << T[j] << endl;
#endif
      }
   }

   return T[k];
}

int main(int argc, char* argv[])
{
   if (argc < 3)
   {
      cout << "Usage: " << argv[0] << " n k\n";
      return 1;
   }
   else
   {
      int n = atoi(argv[1]);
      int k = atoi(argv[2]);

      cout << binomial1(n, k) << endl;

      return 0;
   }
}
