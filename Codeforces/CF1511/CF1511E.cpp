#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, N = 3e5+4;

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int sub(int a, int b)
{
    return add(a,mod-b);
}

int mul(int a, int b)
{
    return (1LL*a*b)%mod;
}

int a[N],tp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,ans=0,w=0,x;
    cin>>n>>m;
    vector<string> s(n);
    a[0]=0;tp[0]=1;
    a[1]=0;tp[1]=2;
    a[2]=1;tp[2]=4;
    a[3]=3;tp[3]=8;
    for (int i=4;i<N;++i)
    {
        a[i]=sub(mul(3,a[i-1]),mul(4,a[i-3]));
        tp[i]=add(tp[i-1],tp[i-1]);
    }
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
        for (auto j : s[i])
            if (j=='o')
                ++w;
    }
    for (int i=0;i<n;++i)
    {
        x=-1;
        for (int j=0;j<m;j=x+1)
        {
            x=j;
            if (s[i][j]=='*')
                continue;
            for (int k=j+1;k<m;++k,++x)
                if (s[i][k]=='*')
                    break;
            ans=add(ans,mul(a[x-j+1],tp[w-x+j-1]));
        }
    } 
    for (int j=0;j<m;++j)
    {
        x=-1;
        for (int i=0;i<n;i=x+1)
        {
            x=i;
            if (s[i][j]=='*')
                continue;
            for (int k=i+1;k<n;++k,++x)
                if (s[k][j]=='*')
                    break;
            ans=add(ans,mul(a[x-i+1],tp[w-x+i-1]));
        }
    }      
    cout<<ans;
    return 0;
}