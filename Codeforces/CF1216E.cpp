#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> vForm(int n)
{
    vector<int> v;
    while (n)
    {
        v.push_back(n%10);
        n/=10;
    }
    reverse(v.begin(), v.end());
    return v;
}

void solve()
{
    int thisLength=0,tenPow=1,remaining,cur=0,lng=0;
    cin>>remaining;
    while (0<remaining-thisLength)
    {
        remaining-=thisLength;
        ++cur;
        if (cur==tenPow)
        {
            tenPow*=10;
            ++lng;
        }
        thisLength+=lng;
    }
    tenPow=10,lng=1;
    for (int i=1;i<=cur;++i)
    {
        if (lng>=remaining)
        {
            cout<<vForm(i)[remaining-1]<<"\n";
            return;
        }
        remaining-=lng;
        if (i+1==tenPow)
        {
            ++lng;
            tenPow*=10;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}