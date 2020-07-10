#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,x,y,c,d;
    double mini=10000000,maxi=0,cur,a1,b1=-1,c1,tem;
    cin>>n>>x>>y;
    ll e[n+1][2];
    for (int i=0;i<n;++i)
    {
        cin>>e[i][0]>>e[i][1];
        c=x-e[i][0];
        d=y-e[i][1];
        c*=c;
        d*=d;
        cur=c+d;
        cur=sqrt(cur);
        if (maxi<cur)
            maxi=cur;
    }
    e[n][0]=e[0][0];e[n][1]=e[0][1];
    for (int i=0;i<n;++i)
    {
        a1=e[i+1][1]-e[i][1];
        a1/=(e[i+1][0]-e[i][0]);
        c1=e[i][1];
        c1-=(a1*e[i][0]);
        cur=abs(a1*(x)+b1*(y)+c1);
        tem=a1*a1+b1*b1;
        tem=sqrt(tem);
        cur/=tem;
        if (cur<mini)
            mini=cur;
    }
    cout<<maxi<<" "<<mini<<"\n";
    maxi*=maxi;
    mini*=mini;
    cur=maxi-mini;
    cur*=pi;
    cout<<fixed<<setprecision(10)<<cur;
    return 0;
}