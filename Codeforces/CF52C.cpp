#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn = 2e5+7;
const ll INF = 1e18;
ll segTree[4*maxn],lazy[4*maxn],ans;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

int left(int i)
{
    return (i<<1) + 1;
}

int right(int i)
{
    return (i<<1) + 2;
}

ll calc(int i)
{
    return segTree[i] + lazy[i];
}

void passDown(int i, ll x)
{
    lazy[i] += x;
}

void recalc(int i)
{
    segTree[i] = min(calc(left(i)),calc(right(i)));
}

void sendDown(int i)
{
    passDown(left(i), lazy[i]);
    passDown(right(i), lazy[i]);
    lazy[i]=0;
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>segTree[i];
        return;
    }
    int m = l + ((r-l)>>1);
    build(left(i), l, m);
    build(right(i), m+1, r);
    recalc(i);
}

void update(int i, int cL, int cR, int l, int r, int x)
{
    if (cR<l||r<cL)
        return;
    if (l<=cL&&cR<=r)
    {
        lazy[i]+=x;
        return;
    }
    sendDown(i);
    int m = cL + ((cR-cL)>>1);
    update(left(i),cL,m,l,r,x);
    update(right(i),m+1,cR,l,r,x);
    recalc(i);
}

void query(int i, int cL, int cR, int l, int r)
{
    if (cR<l||r<cL)
        return;
    if (l<=cL&&cR<=r)
    {
        ans=min(ans,calc(i));
        return;
    }
    sendDown(i);
    int m = cL + ((cR-cL)>>1);
    query(left(i),cL,m,l,r);
    query(right(i),m+1,cR,l,r);
    recalc(i);
}

void check()
{
    for (int i=0;i<7;++i)
        cout<<i<<": "<<segTree[i]<<" "<<lazy[i]<<"\n";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,l,r,v;
    string s;
    cin>>n;
    build(0,0,n-1);
    cin>>q;
    getline(cin,s);
    while (q--)
    {
        getline(cin,s);
        istringstream in(s);
        if (count(s.begin(),s.end(),' ')==1)
        {
            in>>l>>r;
            ans=INF;
            if (l<=r)
                query(0,0,n-1,l,r);
            else
            {
                query(0,0,n-1,l,n-1);
                query(0,0,n-1,0,r);
            }
            cout<<ans<<"\n";
        }
        else
        {
            in>>l>>r>>v;
            if (l<=r)
                update(0,0,n-1,l,r,v);
            else
            {
                update(0,0,n-1,l,n-1,v);
                update(0,0,n-1,0,r,v);
            }
        }
    }
    return 0;
}