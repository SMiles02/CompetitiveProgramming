#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define double long double
using namespace std;

double X,Y,R;

double sq(double x)
{
    return x*x;
}

bool inCircle(double x, double y)
{
    if (sq(x-X)+sq(y-Y)<=sq(R))
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>X>>Y>>R;
    int l,r,m,p1,p2,yD,yU;
    yD=Y;
    ll ans=0;
    if ((int)Y==Y)
        yU=Y;
    else
    {
        yU=Y;
        ++yU;
    }
    //cout<<yD<<" "<<yU<<"\n";
    for (int i=X-100010;i<=X+100010;++i)
    {
        if (inCircle(i,yD))
        {
            l=yD-100010,r=yD;
            while (l<r)
            {
                m=l+(r-l)/2;
                if (inCircle(i,m))
                    r=m;
                else
                    l=m+1;
            }
            if (!inCircle(i,m))
                ++m;
            p1=abs(m-yD)+1;
            //cout<<i<<" "<<yD<<" "<<m<<"!\n";
        }
        else
            p1=-1;
        if (inCircle(i,yU))
        {
            l=yU;r=yU+100010;
            while (l<r)
            {
                m=l+(r-l)/2+1;
                if (inCircle(i,m))
                    l=m;
                else
                    r=m-1;
            }
            if (!inCircle(i,m))
                --m;
            p2=abs(m-yU)+1;
            //cout<<i<<" "<<m<<" "<<yU<<"!!\n";
        }
        else
            p2=-1;
        if (p1==-1&&p2==-1)
            continue;
        //cout<<i<<" "<<p1<<" "<<" "<<p2<<"\n";
        if (p1==-1)
        {
            ans+=p2;
            continue;
        }
        if (p2==-1)
        {
            ans+=p1;
            continue;
        }
        ans+=p1+p2;
        if (yD==yU)
            --ans;
    }
    cout<<ans;
    return 0;
}