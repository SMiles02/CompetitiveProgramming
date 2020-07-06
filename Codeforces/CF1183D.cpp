#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k,carriedForward;
ll ans;
map<int,int> frequencies;
map<int,int> frequencyOfFrequencies;

void solve()
{
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        ++frequencies[k];
    }
    for (int i=1;i<=n;++i)
    {
        ++frequencyOfFrequencies[frequencies[i]];
    }
    ans=0;
    carriedForward=0;
    for (int i=n;i>0;--i)
    {
        if (frequencyOfFrequencies[i])
        {
            ans+=i;
            carriedForward+=frequencyOfFrequencies[i]-1;
        }
        else if (carriedForward)
        {
            ans+=i;
            --carriedForward;
        }
    }
    cout<<ans<<"\n";
    frequencies.clear();
    frequencyOfFrequencies.clear();
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        solve();
    }
    return 0;
}