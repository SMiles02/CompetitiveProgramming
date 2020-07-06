#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int n,k,x,mod=1e9+7;
vector<ll> pos;
vector<ll> zero;
vector<ll> neg;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        if (x>0)
            pos.push_back(x);
        else if (x<0)
            neg.push_back(x);
        else
            zero.push_back(x);
    }
    bool ok=0;
    for (int i=k;i>=0;i-=2)
    {
        if (sz(pos)>=i)
            if (sz(neg)>=k-i)
                ok=1;
    }
    ll ans=1;
    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());
    if (ok)
    {
        while (k>0)
        {
            if (k==1)
            {
                ans*=pos.back();
                pos.pop_back();
                ans%=mod;
                --k;
            }
            else if (sz(pos)>1&&sz(neg)>1&&k>1)
            {
                if (pos.back()*pos[sz(pos)-2]>neg.back()*neg[sz(neg)-2])
                {
                    ans*=pos.back();
                    pos.pop_back();
                    ans%=mod;
                    ans*=pos.back();
                    pos.pop_back();
                    ans%=mod;
                }
                else
                {
                    ans*=neg.back();
                    neg.pop_back();
                    ans%=mod;
                    ans*=neg.back();
                    neg.pop_back();
                    ans%=mod;
                }
                k-=2;
            }
            else if (sz(neg)>1)
            {
                ans*=neg.back();
                neg.pop_back();
                ans%=mod;
                ans*=neg.back();
                neg.pop_back();
                ans%=mod;
                k-=2;
            }
            else
            {
                ans*=pos.back();
                pos.pop_back();
                ans%=mod;
                --k;
            }
        }
        cout<<ans<<"\n";
        return 0;
    }
    if (sz(zero))
    {
        cout<<0<<"\n";
        return 0;
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());
    while (k>0)
    {
        if (sz(pos)&&sz(neg))
        {
            if (pos.back()<abs(neg.back()))
            {
                ans*=pos.back();
                pos.pop_back();
            }
            else
            {
                ans*=neg.back();
                neg.pop_back();
            }
        }
        else if (sz(pos))
        {
            ans*=pos.back();
            pos.pop_back();
        }
        else
        {
            ans*=neg.back();
            neg.pop_back();
        }
        ans%=mod;
        --k;
    }
    while (ans<0)
        ans+=mod;
    cout<<ans;
    return 0;
}