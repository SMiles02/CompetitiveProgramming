#include <bits/stdc++.h>
using namespace std;

struct seg
{
    int n,s,m;
    vector<array<int,2>> p, a;
    int d(int x, int y)
    {
        return abs(p[x][0]-p[y][0])+abs(p[x][1]-p[y][1]);
    } 
    seg(int n) : n(n), p(n), a(n*4)
    {
        for (int i=0;i<n;++i)
            cin>>p[i][0]>>p[i][1];
        build(0,0,n-1);
    }
    void build(int i, int l, int r)
    {
        if (l==r)
        {
            if (l+1<n)
                a[i][0]=d(l,l+1);
            else
                a[i][0]=0;
            if (0<=l-1&&l+1<n)
                a[i][1]=d(l-1,l)+d(l,l+1)-d(l-1,l+1);
            else
                a[i][1]=0;
            return;
        }
        build(i*2+1,l,l+(r-l)/2);
        build(i*2+2,l+(r-l)/2+1,r);
        a[i][0]=a[i*2+1][0]+a[i*2+2][0];
        a[i][1]=max(a[i*2+1][1],a[i*2+2][1]);
    }
    void update(int i, int l, int r, int x)
    {
        if (x<l||r<x)
            return;
        if (l==r)
        {
            if (l+1<n)
                a[i][0]=d(l,l+1);
            else
                a[i][0]=0;
            if (0<=l-1&&l+1<n)
                a[i][1]=d(l-1,l)+d(l,l+1)-d(l-1,l+1);
            else
                a[i][1]=0;
            return;
        }
        update(i*2+1,l,l+(r-l)/2,x);
        update(i*2+2,l+(r-l)/2+1,r,x);
        a[i][0]=a[i*2+1][0]+a[i*2+2][0];
        a[i][1]=max(a[i*2+1][1],a[i*2+2][1]);
    }
    void update()
    {
        int x;
        cin>>x;--x;
        cin>>p[x][0]>>p[x][1];
        update(0,0,n-1,x-1);
        update(0,0,n-1,x);
        update(0,0,n-1,x+1);
    }
    void query(int i, int cL, int cR, int l, int r)
    {
        if (r<cL||cR<l)
            return;
        if (l<=cL&&cR<=r)
        {
            s+=a[i][0];
            m=max(m,a[i][1]);
            return;
        }
        query(i*2+1,cL,cL+(cR-cL)/2,l,r);
        query(i*2+2,cL+(cR-cL)/2+1,cR,l,r);
    }
    void query()
    {
        int l,r,x;
        cin>>l>>r;
        --l;--r;
        if (l<r)
        {
            s=0;
            query(0,0,n-1,l,r-1);
            x=s;
        }
        else
            x=0;
        m=0;
        if (l+1<r)
            query(0,0,n-1,l+1,r-1);
        cout<<x-m<<"\n";
    }
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    int n,q;
    cin>>n>>q;
    char c;
    seg s(n);
    while (q--)
    {
        cin>>c;
        if (c=='Q')
            s.query();
        else
            s.update();
    }
	return 0;
}