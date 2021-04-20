#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<int,bool> m;
    vector<int> v;
    int n,k;
    cin>>n;
    while (n--)
    {
        cin>>k;
        m[k]=1;
    }
    cin>>n;
    while (n--)
    {
        cin>>k;
        if (m[k])
            v.push_back(k);
    }
    sort(v.begin(), v.end());
    if (v.empty())
        cout<<"Empty Set";
    else
        for (int i : v)
            cout<<i<<" ";
    return 0;
}