#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<ll,ll> minTree[1000000];
ll sumTree[1000000],ans;
int lenOf[1000000];

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

ll calcMin(int i)
{
    return minTree[i].first+minTree[i].second;
}

void minUpdate(int i)
{
    minTree[i].first=min(calcMin((i<<1)+1),calcMin((i<<1)+2));
}

ll calcSum(int i)
{
    return sumTree[i]+minTree[i].second*lenOf[i];
}

void sumUpdate(int i)
{
    sumTree[i]=calcSum((i<<1)+1)+calcSum((i<<1)+2);
}

void passDown(int i)
{
    minTree[(i<<1)+1].second+=minTree[i].second;
    minTree[(i<<1)+2].second+=minTree[i].second;
    minTree[i].second=0;
}

void build(int i, int l , int r)
{
    lenOf[i]=r-l+1;
    if (l==r)
    {
        cin>>sumTree[i];
        minTree[i].first=sumTree[i];
        return;
    }
    int m=l+((r-l)>>1);
    build((i<<1)+1,l,m);
    build((i<<1)+2,m+1,r);
    sumUpdate(i);
    minUpdate(i);
}

void update(int i, int cL, int cR, int l, int r, int x)
{
    if (cR<l||r<cL)
        return;
    if (l<=cL&&cR<=r)
    {
        minTree[i].second+=x;
        return;
    }
    passDown(i);
    int m=cL+((cR-cL)>>1);
    update((i<<1)+1,cL,m,l,r,x);
    update((i<<1)+2,m+1,cR,l,r,x);
    sumUpdate(i);
    minUpdate(i);
}

void queryMin(int i, int cL, int cR, int l, int r)
{
    if (cR<l||r<cL)
        return;
    if (l<=cL&&cR<=r)
    {
        ans=min(ans,calcMin(i));
        return;
    }
    passDown(i);
    int m=cL+((cR-cL)>>1);
    queryMin((i<<1)+1,cL,m,l,r);
    queryMin((i<<1)+2,m+1,cR,l,r);
    sumUpdate(i);
    minUpdate(i);
}

void querySum(int i, int cL, int cR, int l, int r)
{
    if (cR<l||r<cL)
        return;
    if (l<=cL&&cR<=r)
    {
        ans+=calcSum(i);
        return;
    }
    passDown(i);
    int m=cL+((cR-cL)>>1);
    querySum((i<<1)+1,cL,m,l,r);
    querySum((i<<1)+2,m+1,cR,l,r);
    sumUpdate(i);
    minUpdate(i);    
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n,q,l,r,x;
    char c;
    cin>>n>>q;
    build(0,1,n);
    while (q--)
    {
        cin>>c;
        if (c=='P')
        {
            cin>>l>>r>>x;
            update(0,1,n,l,r,x);
        }
        else if (c=='M')
        {
            cin>>l>>r;
            ans=1e18;
            queryMin(0,1,n,l,r);
            cout<<ans<<"\n";
        }
        else
        {
            cin>>l>>r;
            ans=0;
            querySum(0,1,n,l,r);
            cout<<ans<<"\n";
        }
    }
	return 0;
}