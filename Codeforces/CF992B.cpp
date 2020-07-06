#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l,r,x,y,ans=0;
    cin>>l>>r>>x>>y;
    if (y%x)
    {
        cout<<0;
        return 0;
    }
    double left=l,right=r;
    left/=x;
    right/=x;
    y/=x;
    for (int i=1;i<=sqrt(y);++i)
    {
        if (!(y%i))
        {
            if (i*i==y)
            {
                if (left<=i&&i<=right&&gcd(i,i)==1)
                {
                    ++ans;
                    //cout<<i<<" "<<i<<"\n";
                }
            }
            else
            {
                if (left<=i&&left<=y/i&&i<=right&&y/i<=right&&gcd(i,y/i)==1)
                {
                    ans+=2;
                    //cout<<i<<" "<<y/i<<"\n";
                }
            }
        }
    }
    cout<<ans;
    return 0;
}