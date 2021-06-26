#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k,atm;
int segTree[1800010];
int arr[100000];

void update(int cur, int curL, int curR, int l, int r, int n)
{
    if (r<curL||curR<l) return;
    if (l<=curL&&curR<=r)
    {
        segTree[cur]+=n;
        return;
    }
    if (curL==curR) return;
    update(cur*2+1,curL,curL+(curR-curL)/2,l,r,n);
    update(cur*2+2,curL+(curR-curL)/2+1,curR,l,r,n);
}

void getNum(int cur, int l, int r, int x)
{
    if (r<x||x<l)
    {
        return;
    }
    atm+=segTree[cur];
    if (l==x&&r==x) return;
    getNum(cur*2+1,l,l+(r-l)/2,x);
    getNum(cur*2+2,l+(r-l)/2+1,r,x);
}

void operation(int x, int y)
{
    int a=min(x,y)+1,b=max(x,y)+k;
    update(0,1,2*k+1,1,a-1,2);
    update(0,1,2*k+1,a,b,1);
    update(0,1,2*k+1,b+1,2*k+1,2);
    update(0,1,2*k+1,x+y,x+y,-1);
}

void clearSegTree()
{
    for (int i=0;i<=6+9*k;++i)
    {
        segTree[i]=0;
    }
}

void solve()
{
    int x;
    cin>>n>>k;
    clearSegTree();
    if (k==1)
    {
        for (int i=0;i<n;++i) cin>>x;
        cout<<"0\n";
        return;
    }
    for (int i=0;i<n/2;++i) cin>>arr[i];
    for (int i=0;i<n/2;++i)
    {
        cin>>x;
        operation(arr[n/2-i-1],x);
    }
    int ans=n;
    for (int i=2;i<=2*k;++i)
    {
        atm=0;
        getNum(0,1,2*k+1,i);
        ans=min(ans,atm);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--) solve();
    return 0;
}