#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n;
    vector<int> a,b;
    map<int,bool> m;
    while (n--)
    {
        cin>>k;
        if (m[k])
            b.push_back(k);
        else
            a.push_back(k);
        m[k]=1;
    }
    sort(a.begin(), a.end());
    for (int i : a)
        cout<<i<<" ";
    for (int i : b)
        cout<<i<<" ";
    cout<<"\n";
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