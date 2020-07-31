#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int occ[1000001];
vector<int> sieve[1000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<1000001;++i)
        for (int j=i;j<1000001;j+=i)
            sieve[j].push_back(i);
    int n,k;
    cin>>n;
    while (n--)
    {
        cin>>k;
        for (int i : sieve[k])
            ++occ[i];
    }
    for (int i=1000000;1;--i)
        if (occ[i]>1)
        {
            cout<<i;
            return 0;
        }
    return 0;
}