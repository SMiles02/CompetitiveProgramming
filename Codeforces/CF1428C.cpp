#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string t;
    cin>>t;
    stack<char> s;
    for (auto i : t)
    {
        if (!s.empty()&&i=='B')
            s.pop();
        else
            s.push(i);
    }
    cout<<s.size()<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}