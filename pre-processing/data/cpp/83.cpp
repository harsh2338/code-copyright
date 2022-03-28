#include <bits/stdc++.h>
using namespace std;
string mult1(string a, char b)
{
    if (b == '0')
        return "0";
    int n = a.size();
    int car = 0, num = 0;
    int m = b - '0';
    string ans = "";
    for (int i = n - 1; i >= 0; i--)
    {
        num = (a[i] - '0') * m + car;
        car = num / 10;
        num = num % 10;
        ans = to_string(num) + ans;
    }
    if (car != 0)
        ans = to_string(car) + ans;
    return ans;
}
string add(string a, string b)
{
    int na = a.length(), nb = b.length();

    int car = 0, num = 0;
    string ans = "";
    int n = min(na, nb);
    if (na == n)
    {
        while (a.length() != b.length())
            a = "0" + a;
    }
    else
    {
        while (a.length() != b.length())
            b = "0" + b;
    }
    int i;
    for (i = a.length() - 1; i >= 0; i--)
    {
        num = car + (a[i] - '0' + b[i] - '0');
        car = num / 10;
        num = num % 10;
        ans = to_string(num) + ans;
    }
    if (car != 0)
        ans = to_string(car) + ans;
    return ans;
}
string multiply(string a, string b)
{
    if (a.length() < b.length())
        return multiply(b, a);
    string ans = "0", cur = "";
    for (int i = b.length() - 1; i >= 0; i--)
    {
        cur = mult1(a, b[i]);
        for (int j = 0; j < b.length() - 1 - i; j++)
            cur = cur + "0";
        ans = add(ans, cur);
    }
    return ans;
}
vector<int> factorial(int N)
{
    // code here
    int prev = N;
    string ans = to_string(N), cur = "";
    for (int i = N - 1; i > 0; i--)
    {
        ans = multiply(ans, to_string(i));
    }
    vector<int> sol;
    for (int i = 0; i < ans.length(); i++)
        sol.push_back(ans[i] - '0');
    return sol;
}
int main()
{
    auto a = factorial(10);
    for (int i : a)
    {
        // for (int j : i)
        cout << i;
        // cout << "\n";
    }
}