#include <bits/stdc++.h>
using namespace std;

int besthub(int R, int L, int a[], long long B)
{
    int l=0,r=R,m,x,y;
    bool ok;
    long long cur;
    while (l<r)
    {
        ok=0;
        m=l+(r-l)/2+1;
        cur=0;
        x=0;y=m-1;
        for (int i=0;i<=y/2;++i)
            cur-=a[i];
        for (int i=y/2+1;i<m;++i)
            cur+=a[i];
        if (cur+1LL*a[(x+y)/2]*((m-1)/2+1)-1LL*a[(x+y)/2]*(m-(m-1)/2-1)<=B)
            ok=1;
        for (++x,++y;y<R;++x,++y)
        {
            cur+=a[x-1];
            cur+=a[y];
            cur-=a[(x+y)/2]*2;
            if (cur+1LL*a[(x+y)/2]*((m-1)/2+1)-1LL*a[(x+y)/2]*(m-(m-1)/2-1)<=B)
                ok=1;
        }
        if (ok)
            l=m;
        else
            r=m-1;
    }
    return l;
}