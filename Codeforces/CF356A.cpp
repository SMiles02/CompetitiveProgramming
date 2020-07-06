#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int beatenBy[1300000];

void update(int cur,int n, int l, int r, int arrL, int arrR)
{
    if (beatenBy[cur]||r<arrL||arrR<l)
    {
        return;
    }
    if (l<=arrL&&arrR<=r)
    {
        beatenBy[cur]=n;
        return;
    }
    update(cur*2+1,n,l,r,arrL,arrL+(arrR-arrL)/2);
    update(cur*2+2,n,l,r,arrL+(arrR-arrL)/2+1,arrR);
}

int getAns(int cur)
{
    if (beatenBy[cur]) return beatenBy[cur];
    if (cur==0) return cur;
    return getAns((cur-1)/2);
}

int findIndice(int x, int arrL, int arrR, int i)
{
    if (arrL==arrR)
    {
        return i;
    }
    if (x<=arrL+(arrR-arrL)/2)
    {
        return findIndice(x,arrL,arrL+(arrR-arrL)/2,2*i+1);
    }
    return findIndice(x,arrL+(arrR-arrL)/2+1,arrR,2*i+2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,l,r,x;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>l>>r>>x;
        if (x==l)
        {
            update(0,x,x,r-1,0,n-1);
        }
        else if (x==r)
        {
            update(0,x,l-1,x-2,0,n-1);
        }
        else
        {
            update(0,x,l-1,x-2,0,n-1);
            update(0,x,x,r-1,0,n-1);
        }
    }
    for (int i=0;i<n;++i)
    {
        cout<<getAns(findIndice(i,0,n-1,0))<<" ";
    }
    return 0;
}