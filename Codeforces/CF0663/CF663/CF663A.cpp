#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,P=1,N=0,x=1,y=0;
    string t;
    ll s=0;
    vector<int> v={1},a,b;
    cin>>t;
    while (cin>>t)
    {
        if (t=="=")
            break;
        if (t=="+")
        {
            ++P;
            v.push_back(1);
        }
        else
        {
            ++N;
            v.push_back(0);
        }
        cin>>t;
    }
    cin>>n;
    if (1LL*n*P-N<n||n<-1LL*n*N+P)
    {
        cout<<"Impossible";
        return 0;
    }
    while (P>0)
    {
        --P;
        for (int i=1;i<=n;++i)
            if (-1LL*n*N+P+s+i<=n&&n<=s+i+1LL*n*P-N)
            {
                a.push_back(i);
                s+=i;
                break;
            }
    }
    while (N>0)
    {
        --N;
        for (int i=1;i<=n;++i)
            if (s-1LL*n*N-i<=n&&n<=s-N-i)
            {
                b.push_back(i);
                s-=i;
                break;
            }
    }
    cout<<"Possible\n";
    cout<<a[0]<<" ";
    for (int i=1;i<sz(v);++i)
    {
        if (v[i])
            cout<<"+ "<<a[x++]<<" ";
        else
            cout<<"- "<<b[y++]<<" ";
    }
    cout<<"= "<<n;
    return 0;
}