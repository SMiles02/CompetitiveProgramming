#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n;
    vector<int> v = {1};
    cout<<"1\n";
    cin>>k;
    for (int i=1;i<n;++i)
    {
        cin>>k;
        if (k==1)
            v.push_back(1);
        else
        {
            while (v.back()!=k-1)
                v.pop_back();
            ++v.back();
        }
        cout<<v[0];
        for (int j=1;j<(int)v.size();++j)
            cout<<"."<<v[j];
        cout<<"\n";
    }
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