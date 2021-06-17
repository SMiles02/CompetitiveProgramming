#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 5e5+7;
int a[N], s[N<<4];

void build(int i, int l, int r)
{
    if (l==r)
    {
        s[i]=a[l];
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    s[i]=max(s[i*2+1],s[i*2+2]);
}

int query(int i, int l, int r, int qL, int qR)
{
    if (qR<l||r<qL)
        return 0;
    if (qL<=l&&r<=qR)
        return s[i];
    return max(query(i*2+1,l,l+(r-l)/2,qL,qR),query(i*2+2,l+(r-l)/2+1,r,qL,qR));
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,l,r,ans;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    build(0,1,n);
    cin>>q;
    while (q--)
    {
        cin>>l>>r;
        ans=0;
        for (int i=l;i<=r;++i)
            for (int j=i+1;j*2-i<=r;++j)
                ans=max(ans,a[i]+a[j]+query(0,1,n,j*2-i,r));
        cout<<ans<<"\n";
    }
    return 0;
}