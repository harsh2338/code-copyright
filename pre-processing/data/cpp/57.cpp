#include <bits/stdc++.h>
#define M % 1000000007
using namespace std;

int nCr(int n, int r)
{
    // code here
    if (r == 0)
        return 1;
    if (r > n)
        return 0;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int i : dp)
            cout << i << " ";
        for (int j = i; j >= 1; j--)
        {
            dp[j] = (dp[j] M + dp[j - 1] M) M;
        }
        cout << "\n";
    }
    for (int i : dp)
        cout << i << " ";
    cout << "\n";

    return dp[r];
}
void printNcR(int n, int r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p = (p M * n M) M;
            k = (k M * r M) M;
            // k *= r;

            // gcd of p, k
            long long m = __gcd(p, k);

            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p = (p M / m M) M;
            k = (k M / m M) M;

            n--;
            r--;
        }

        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }

    else
        p = 1;

    // if our approach is correct p = ans and k =1
    // return p;
}
int main()
{
    // printNcR(778, 116);
    cout
        << nCr(15, 3);
}