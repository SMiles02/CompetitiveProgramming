#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int seg[N*4][2], n, m;
//0 min
//1 val

void pass(int i)
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
    seg[i][0]=min(calc(i*2+1),calc(i*2+2));
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
    pass(i);
    update(i*2+1,l,l+(r-l)/2,qL,qR,x);
    update(i*2+2,l+(r-l)/2+1,r,qL,qR,x);
    recalc(i);
}

void update(int l, int r, int x)
{
    update(0,1,m-1,l,r,x);
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int j=-1,ans;
    cin>>n>>m;
    array<int,3> a[n];
    for (int i=0;i<n;++i)
        cin>>a[i][1]>>a[i][2]>>a[i][0];
    sort(a,a+n);
    while (calc(0)==0)
    {
        ++j;
        update(a[j][1],a[j][2]-1,1);
    }
    ans=a[j][0]-a[0][0];
    for (int i=1;i<n;++i)
    {
        update(a[i-1][1],a[i-1][2]-1,-1);
        while (calc(0)==0&&j+1<n)
        {
            ++j;
            update(a[j][1],a[j][2]-1,1);
        }
        if (calc(0)==0)
            break;
        ans=min(ans,a[j][0]-a[i][0]);
    }
    cout<<ans;
    return 0;
}