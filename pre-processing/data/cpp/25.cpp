#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 4;
    int ans = solve(n / 2);

    if (n & 1)
    {
        return (ans << 2) + ((n / 2) << 2) + 1;
    }
    else
        return ans << 2;
}
int main()
{
    int ans = solve(9);
    cout << ans;
}