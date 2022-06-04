#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int xPrefix[200001];
int yPrefix[200001];
int finalX,finalY,x,y,n;
string s;

bool possible(int k)
{
    int x1,y1,a,b;
    for (int i=n;i-k>=0;--i)
    {
        x1=finalX-xPrefix[i]+xPrefix[i-k];
        y1=finalY-yPrefix[i]+yPrefix[i-k];
        a=abs(x-x1);
        b=abs(y-y1);
        if (a+b<=k&&(a+b)%2==k%2)
            return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>s;
    cin>>x>>y;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='R')
        {
            xPrefix[i+1]=xPrefix[i]+1;
            yPrefix[i+1]=yPrefix[i];
        }
        if (s[i]=='L')
        {
            xPrefix[i+1]=xPrefix[i]-1;
            yPrefix[i+1]=yPrefix[i];
        }
        if (s[i]=='U')
        {
            xPrefix[i+1]=xPrefix[i];
            yPrefix[i+1]=yPrefix[i]+1;
        }
        if (s[i]=='D')
        {
            xPrefix[i+1]=xPrefix[i];
            yPrefix[i+1]=yPrefix[i]-1;
        }
    }
    finalX=xPrefix[n];
    finalY=yPrefix[n];
    if (finalX==x&&finalY==y)
    {
        cout<<0;
        return 0;
    }
    if (n==1)
    {
        if (abs(x)+abs(y)==1)
            cout<<1;
        else
            cout<<-1;
        return 0;
    }
    int l=1,r=n,m,ans1,ans2;
    vector<int> odds;
    vector<int> evens;
    for (int i=1;i<=n;i+=2)
        odds.push_back(i);
    for (int i=2;i<=n;i+=2)
        evens.push_back(i);
    bool c=possible(odds.back()),d=possible(evens.back());
    if (!c&&!d)
    {
        cout<<-1;
        return 0;
    }
    if (c)
    {
        l=0;r=sz(odds)-1;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (possible(odds[m]))
                r=m;
            else
                l=m+1;
        }
        ans1=odds[l];
    }
    else
        ans1=10000000;
    if (d)
    {
        l=0;r=sz(evens)-1;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (possible(evens[m]))
                r=m;
            else
                l=m+1;
        }
        ans2=evens[l];
    }
    else
        ans2=10000000;
    cout<<min(ans1,ans2);
    return 0;
}