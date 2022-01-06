#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+4, L = 20, INF = -1e9;
int n, lf, up[N][L], tin[N], tout[N], nd[N*2], t, seg[N*8][2];
bitset<N> on;
vector<int> e[N];

void passDown(int i)
{
    seg[i*2+1][1]+=seg[i][1];
    seg[i*2+2][1]+=seg[i][1];
    seg[i][1]=0;
}

int calc(int i)
{
    return seg[i][0]+seg[i][1];
}

void recalc(int i)
{
    seg[i][0]=max(calc(i*2+1),calc(i*2+2));
}

void update(int i, int l, int r, int qL, int qR, int x)
{
    if (r<qL||qR<l)
        return;
    if (qL<=l&&r<=qR)
    {
        seg[i][1]+=x;
        return;
    }
    passDown(i);
    update(i*2+1,l,l+(r-l)/2,qL,qR,x);
    update(i*2+2,l+(r-l)/2+1,r,qL,qR,x);
    recalc(i);
}

void update(int l, int r, int x)
{
    update(0,1,n*2,l,r,x);
}

int query(int i, int l, int r, int qL, int qR)
{
    if (r<qL||qR<l)
        return INF;
    if (qL<=l&&r<=qR)
        return calc(i);
    passDown(i);
    int x = max(query(i*2+1,l,l+(r-l)/2,qL,qR),query(i*2+2,l+(r-l)/2+1,r,qL,qR));
    recalc(i);
    return x;
}

void dfs(int c, int p, int x)
{
    tin[c]=++t;
    nd[t]=c;
    update(t,t,x);
    up[c][0]=p;
    int cd=0;
    for (int i=1;i<L;++i)
        up[c][i]=up[up[c][i-1]][i-1];
    for (int i : e[c])
        if (i!=p)
        {
            ++cd;
            dfs(i,c,x+1);
        }
    if (cd==0)
        ++lf;
    tout[c]=++t;
}

int findMax(int i, int l, int r)
{
    if (l==r)
        return nd[l];
    if (calc(i*2+1)<calc(i*2+2))
        return findMax(i*2+2,l+(r-l)/2+1,r);
    return findMax(i*2+1,l,l+(r-l)/2);
}

ll f(int x, int y)
{
    return 1LL*(n-x-y)*(x-y);
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,x,y,z,ct,l,r,m;
    ll finalAns=-1e18;
    cin>>n>>k;
    ct=n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
        on[i]=1;
    }
    on[n]=1;
    tin[0]=0;
    dfs(1,0,1);
    tout[0]=++t;
    vector<int> ans;
    for (int i=0;i<k;++i)
    {
        if (i<lf)
        {
            x=findMax(0,1,n*2);
            ans.push_back(x);
            y=x;
            z=0;
            for (int i=L-1;i>=0;--i)
                if (on[up[y][i]])
                {
                    y=up[y][i];
                    z+=(1<<i);
                }
            for (int i=0;i<=z;++i)
            {
                on[x]=0;
                update(tin[x],tout[x],-1);
                x=up[x][0];
                --ct;
            }
        }
        l=0;
        r=ct;
        while (l<r)
        {
            m=l+(r-l)/2+1;
            if (f(i+1,m-1)>f(i+1,m))
                l=m;
            else
                r=m-1;
        }
        finalAns=max(finalAns,f(i+1,l));
    }
    cout<<finalAns;
    return 0;
}