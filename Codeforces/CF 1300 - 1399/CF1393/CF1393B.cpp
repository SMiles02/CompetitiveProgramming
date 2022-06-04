#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int freq[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,twos=0,fours=0,q;
    cin>>n;
    string s;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        ++freq[k];
    }
    for (int i=1;i<100001;++i)
    {
        twos+=freq[i]/2;
        fours+=freq[i]/4;
    }
    cin>>q;
    while (q--)
    {
        cin>>s;
        cin>>k;
        if (s=="+")
        {
            ++freq[k];
            if (freq[k]%2==0)
                ++twos;
            if (freq[k]%4==0)
                ++fours;
        }
        else
        {
            --freq[k];
            if (freq[k]%2==1)
                --twos;
            if (freq[k]%4==3)
                --fours;
        }
        if (fours>0&&twos-2>1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}