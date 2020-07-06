#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,cur1=0,cur2=0,l=0,r,last=0,curL;
    string s="";
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    r=n-1;
    while (l<=r)
    {
        //cout<<"a["<<l<<"] = "<<a[l]<<", a["<<r<<"] = "<<a[r]<<", last = "<<last<<"\n";
        if (max(a[l],a[r])<=last)
        {
            cout<<sz(s)<<"\n"<<s;
            return 0;
        }
        if (l==r)
        {
            cout<<sz(s)+1<<"\n"<<s<<"L";
            return 0;
        }
        if ((a[l]<a[r]&&a[l]>last)||a[r]<=last)
        {
            s+="L";
            last=a[l];
            ++l;
        }
        else if (a[l]==a[r])
        {
            curL=last;
            for (int i=l;a[i]>curL;++i)
            {
                curL=a[i];
                ++cur1;
                //cout<<"l="<<i<<"worked!\n";
            }
            curL=last;
            for (int i=r;a[i]>curL;--i)
            {
                curL=a[i];
                ++cur2;
                //cout<<"r="<<i<<"worked!\n";
            }
            //cout<<s<<", cur1 = "<<cur1<<", cur2 = "<<cur2<<"\n";
            cout<<sz(s)+max(cur1,cur2)<<"\n"<<s;
            if (cur1>cur2)
            {
                for (int i=0;i<cur1;++i)
                {
                    cout<<"L";
                }
            }
            else
            {
                for (int i=0;i<cur2;++i)
                {
                    cout<<"R";
                }
            }
            return 0;
        }
        else
        {
            s+="R";
            last=a[r];
            --r;
        }
    }
    cout<<sz(s)<<"\n"<<s;
    return 0;
}