#include <bits/stdc++.h>
using namespace std;

int getMaxAreaOfHistogram(vector<int> A)
{
    int n = A.size();
    stack<int> st;
    int ans = 0, i = 0;
    while (i < n)
    {
        if (st.empty() || A[i] >= A[st.top()])
        {
            st.push(i);
            i++;
        }
        else
        {
            int topi = st.top();
            st.pop();
            ans = max(ans, A[topi] * (st.empty() ? i : i - st.top() - 1));
        }
    }
    while (!st.empty())
    {
        int topi = st.top();
        st.pop();
        ans = max(ans, A[topi] * (st.empty() ? i : i - st.top() - 1));
    }
    return ans;
}
int getMaxAreaOfRectangleOf1(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    vector<int> dp(m);
    for (int i = 0; i < m; i++)
        dp[i] = A[0][i];

    int ans = 0;
    ans = max(ans, getMaxAreaOfHistogram(dp));
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (A[i][j] == 1)
                dp[j] += A[i][j];
            else
                dp[j] = 0;
        ans = max(ans, getMaxAreaOfHistogram(dp));
    }
    return ans;
}
int main()
{
    vector<vector<int>> A = {{0, 1, 1, 0},
                             {1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {1, 1, 0, 0}};
    cout << getMaxAreaOfRectangleOf1(A);
}