#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 17;
    int ans = 0;
    int d;
    for (int i = 0; i < 30; i++)
    {
        d = 1 << (i + 1);
        ans += ((n + 1) / d) * (d >> 1) + max(0, (n + 1) % d - d / 2);
    }
    cout << ans;
}