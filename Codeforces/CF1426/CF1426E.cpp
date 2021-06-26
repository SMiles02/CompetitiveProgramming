#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int win(vector<int> a, vector<int> b)
{
    return min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0]);
}

int notwin(vector<int> a, vector<int> b, int x)
{
    int k;
    if (x&1)
    {
        k=min(b[0],a[0]);
        a[0]-=k;
        b[0]-=k;
        k=min(b[2],a[0]);
        a[0]-=k;
        b[2]-=k;
    }
    else
    {
        k=min(b[2],a[0]);
        a[0]-=k;
        b[2]-=k;
        k=min(b[0],a[0]);
        a[0]-=k;
        b[0]-=k;
    }
    if (x&2)
    {
        k=min(b[1],a[1]);
        a[1]-=k;
        b[1]-=k;
        k=min(b[0],a[1]);
        a[1]-=k;
        b[0]-=k;
    }
    else
    {
        k=min(b[0],a[1]);
        a[1]-=k;
        b[0]-=k;
        k=min(b[1],a[1]);
        a[1]-=k;
        b[1]-=k;
    }
    if (x&4)
    {
        k=min(b[2],a[2]);
        a[2]-=k;
        b[2]-=k;
        k=min(b[1],a[2]);
        a[2]-=k;
        b[1]-=k;
    }
    else
    {
        k=min(b[1],a[2]);
        a[2]-=k;
        b[1]-=k;
        k=min(b[2],a[2]);
        a[2]-=k;
        b[2]-=k;
    }
    return a[0]+a[1]+a[2];
}

vector<int> reorder(vector<int> v, int a, int b, int c)
{
    return {v[a],v[b],v[c]};
}

int calc(vector<int> v, vector<int> w, int x)
{
    int ans=1000000000;
    ans=min(ans,notwin(reorder(v,0,1,2),reorder(w,0,1,2),x));
    ans=min(ans,notwin(reorder(v,2,0,1),reorder(w,2,0,1),x));
    ans=min(ans,notwin(reorder(v,1,2,0),reorder(w,1,2,0),x));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,nw;
    cin>>n;
    nw=n;
    vector<int> a(3), b(3);
    for (int i=0;i<3;++i)
        cin>>a[i];
    for (int i=0;i<3;++i)
        cin>>b[i];
    for (int i=0;i<8;++i)
        nw=min(nw,calc(a,b,i));
    cout<<nw<<" "<<win(a,b);
    return 0;
}