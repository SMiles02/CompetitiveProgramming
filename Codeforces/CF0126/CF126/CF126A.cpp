#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x1,x2,t0,l,r,mid,ans1=0,ans2;
    ll t1,t2;
    cin>>t1>>t2>>x1>>x2>>t0;
    double ans=t2,cur;
    ans2=2;
    for (int i=0;i<=x1;++i)
    {
        if (i==0)
        {
            l=1;
        }
        else
        {
            l=0;
        }
        r=x2;
        while (l<r)
        {
            mid=l+(r-l)/2;
            cur=t1*i+t2*mid;
            cur/=(i+mid);
            if (cur<t0) l=mid+1;
            else
            {
                r=mid;
            }
        }
        cur=t1*i+t2*l;
        cur/=(i+l);
        if (cur>=t0)
        {
            if (cur<ans)
            {
                ans=cur;
                ans1=i;
                ans2=l;
            }
            else if (cur==ans)
            {
                if (i+l>ans1+ans2)
                {
                    ans=cur;
                    ans1=i;
                    ans2=l;    
                }
            }
        }
    }
    if (ans1==0) ans2=x2;
    if (ans2==0) ans1=x1;
    if (t1==t2&&t0==t1) 
    {
        ans1=x1;
        ans2=x2;
    }
    cout<<ans1<<" "<<ans2<<"\n";
    return 0;
}