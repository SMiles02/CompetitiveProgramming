#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll ans=0;

void checker(int a, int b, int l, int k)
{
    int mini=((1+k)/l);
    int maxi=((a+b+k)/l);
    if (a>b)
    {
        swap(a,b);
    }
    int x;
    //cout<<"a: "<<a<<", b: "<<b<<"\n";
    for (int i = mini+1;i<=maxi;++i)
    {
        x=i*l-k;
        if (x<a+1)
        {
            ans+=(x-1);
        }
        else if (x>1+b)
        {
            ans+=a-abs(x-b-1);
        }
        else
        {
            ans+=a;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    string s;
    cin>>s;
    n=sz(s);
    vector<int> v={-1};
    for (int i=0;i<n;++i)
    {
        if (s[i]=='1')
        {
            v.push_back(i);
        }
    }
    v.push_back(n);
    k=sz(v);
    for (int i=1;i<k-1;++i)
    {
        for (int j=1;i+j<k-1;++j)
        {
            //cout<<v[i]<<" "<<v[i+j]<<"\n";
            checker(v[i]-v[i-1],v[i+j+1]-v[i+j],j+1,v[i+j]-v[i]-1);
            //cout<<ans<<"\n";
        }
    }
    for (int i=1;i<k-1;++i)
    {
        ans+=(v[i]-v[i-1])*(v[i+1]-v[i]);
        //cout<<"+="<<(v[i]-v[i-1])*(v[i+1]-v[i])<<"\n";
    }
    cout<<ans;
    return 0;
}