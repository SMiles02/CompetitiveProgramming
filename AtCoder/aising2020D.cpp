#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)
 
ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll ans[200000];
    ans[0]=0;
    for (int i=1;i<200000;++i)
        ans[i]=ans[i%(__builtin_popcount(i))]+1;
    ll b=0,n;
    string s;
    cin>>n;
    cin>>s;
    for (auto c : s)
        if (c=='1')
            ++b;
    ll bin1[n],bin2[n],sc1[n+1],sc2[n+1],c1=0,c2=0,x;
    bin1[0]=1%(max(b-1,1));
    bin2[0]=1%(b+1);
    for (int i=1;i<n;++i)
    {
        bin1[i]=bin1[i-1]*2;
        bin1[i]%=(max(b-1,1));
        bin2[i]=bin2[i-1]*2;
        bin2[i]%=(b+1);
        //cout<<bin1[i]<<" "<<bin2[i]<<" <-\n";
    }
    sc1[n]=0;sc2[n]=0;
    for (int i=n-1;i+1;--i)
    {
        sc1[i]=sc1[i+1]+(s[i]-'0')*bin1[n-1-i];
        sc1[i]%=(max(b-1,1));
        sc2[i]=sc2[i+1]+(s[i]-'0')*bin2[n-1-i];
        sc2[i]%=(b+1);
        //cout<<sc1[i]<<" "<<sc2[i]<<"\n";
    }
    for (int i=0;i<n;++i)
    {
        //cout<<"! "<<c1<<" "<<c2<<"\n";
        if (b==1&&s[i]=='1')
            cout<<"0\n";
        else if (s[i]=='1')
        {
            x=c1*2;
            x+=(1-(s[i]-'0'));
            x%=(max(b-1,1));
            x*=bin1[n-1-i];
            x+=sc1[i+1];
            //cout<<ans[x%(b-1)]+1<<" "<<x%(b-1)<<"!\n";
            cout<<ans[x%(b-1)]+1<<"\n";
        }
        else
        {
            x=c2*2;
            x+=(1-(s[i]-'0'));
            //cout<<x<<" here\n";
            x%=(b+1);
            //cout<<x<<" here\n";
            x*=bin2[n-1-i];
            //cout<<x<<" here\n";
            x+=sc2[i+1];
            //cout<<x<<" here\n";
            //cout<<ans[x%(b+1)]+1<<" "<<x%(b+1)<<"!!\n";
            cout<<ans[x%(b+1)]+1<<"\n";
        }
        c1*=2;
        c1+=((s[i]-'0'));
        c1%=(max(b-1,1));
        c2*=2;
        c2+=((s[i]-'0'));
        c2%=(b+1);
    }
    return 0;
}