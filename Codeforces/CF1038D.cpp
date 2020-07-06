#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,miniPos=1000000000,maxiNeg=-1000000000,k;
    ll pos=0,neg=0,zero=0;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (k==0)
            ++zero;
        else if (k>0)
        {
            miniPos=min(miniPos,k);
            pos+=k;
        }
        else
        {
            maxiNeg=max(maxiNeg,k);
            neg+=k;
        }
    }
    if (n==1)
        cout<<pos+neg;
    else if (pos==0&&zero==0)
        cout<<-neg+2*maxiNeg;
    else if (neg==0&&zero==0)
        cout<<pos-2*miniPos;
    else
        cout<<pos-neg;
    return 0;
}