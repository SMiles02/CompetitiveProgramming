#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[100000],R;
ll b;

int check()
{
    
}

int besthub(int r1, int L, int x[], ll B)
{
    int l=1,r=L,m1,m2,s1,s2;
    R=r1;b=B;
    for (int i=0;i<r;++i)
        a[i]=x[i];
    while (l<r)
    {
        m1=l+(r-l)/3;
        m2=r-(r-l)/3;
        s1=check(m1);
        s2=check(m2);
    }
}