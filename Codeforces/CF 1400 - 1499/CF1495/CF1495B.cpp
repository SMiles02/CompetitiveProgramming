#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

struct BIT {
    int n,rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n+1,0) {}
    void update(int x, int d) {
        for (int i=x;i<=n;i+=i&-i)
            bit[i]+=d;
    }
    int query(int x) {
        rtn=0;
        for (int i=x;i;i-=i&-i)
            rtn+=bit[i];
        return rtn;
    }
    int query(int a, int b) {
        return query(b) - query(a-1);
    }
};

const int mn = 1e5+69;
int a[mn];

bool isMax(int k)
{
    if (a[k]>a[k-1]&&a[k]>a[k+1])
        return 1;
    return 0;
}

bool isMin(int k)
{
    if (a[k]<a[k-1]&&a[k]<a[k+1])
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,c,ans=0,tp;
    cin>>n;
    int l[n+2],r[n+2],lEnd[n+1],rEnd[n+1];
    BIT bit(n);
    for (int i=1;i<=n;++i)
        cin>>a[i];
    a[0]=a[n+1]=n+1;
    l[0]=r[n+1]=0;
    for (int i=1;i<=n;++i)
    {
        if (a[i]>a[i-1])
            l[i]=l[i-1]+1;
        else
            l[i]=0;
        lEnd[i-l[i]]=l[i];
        if (l[i]>0)
            bit.update(l[i],1);
        //cout<<l[i]<<"\n";
    }
    for (int i=n;i;--i)
    {
        if (a[i]>a[i+1])
            r[i]=r[i+1]+1;
        else
            r[i]=0;
        rEnd[i+r[i]]=r[i];
        if (r[i]>0)
            bit.update(r[i],1);
        //cout<<r[i]<<"\n";
    }
    for (int i=1;i<=n;++i)
    {
        if (isMin(i))
            continue;
        tp=0;
        if (l[i]>r[i])
        {
            c=bit.query(l[i],n)-1;
            if (rEnd[i-l[i]]>=l[i])
                --c;
            if (c<=0&&(l[i]&1)==0)
                tp=1;
        }
        else if (l[i]<r[i])
        {
            c=bit.query(r[i],n)-1;
            if (lEnd[i+r[i]]>=r[i])
                --c;
            if (c<=0&&(r[i]&1)==0)
                tp=1;
        }
        else
        {
            c=bit.query(r[i],n)-2;
            if (rEnd[i-l[i]]>=l[i])
                --c;
            if (lEnd[i+r[i]]>=r[i])
                --c;
            if (c<=0)
                tp=1;
        }
        ans+=tp;
    }
    cout<<ans;
    return 0;
}