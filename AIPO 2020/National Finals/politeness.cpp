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
    string n1,s1,r11,r12,l1,n2,s2,r21,r22,l2,t="tu",v="vous";
    int a1,a2;
    cin>>n1>>a1>>s1>>r11>>r12>>l1;
    cin>>n2>>a2>>s2>>r21>>r22>>l2;
    n1=to_lower(n1);
    s1=to_lower(s1);
    r11=to_lower(r11);
    r12=to_lower(r12);
    l1=to_lower(l1);
    n2=to_lower(n2);
    s2=to_lower(s2);
    r21=to_lower(r21);
    r22=to_lower(r22);
    l2=to_lower(l2);
    if (a1<16)
    {
        if (a2<16)
        {
            cout<<t;
            return 0;
        }
        if (r21=="family")//21
        {
            cout<<t;
            return 0;
        }
        cout<<v;
        return 0;
    }
    if (a2<16)
    {
        if (s2=="royal")
        {
            cout<<v;
            return 0;
        }
        cout<<t;
        return 0;
    }
    if (r11=="friend"||r11=="lover")
    {
        cout<<t;
        return 0;
    }
    if (r11=="stranger"||r11=="unsure"||r11=="peer")
    {
        if (s2=="god")
        {
            cout<<t;
            return 0;
        }
        if (a1+10<=a2)
        {
            cout<<v;
            return 0;
        }
        if (r12=="may-1968")
        {
            cout<<t;
            return 0;
        }
        if (r12=="woodstock")
        {
            cout<<t;
            return 0;
        }
        if (r11=="peer")
        {
            cout<<t;
            return 0;
        }
        if (r11!="unsure")
        {
            cout<<v;
            return 0;
        }
        if (l1=="lucky")
        {
            cout<<t;
            return 0;
        }
        else
        {
            cout<<v;
            return 0;
        }
    }
    if (r11=="spouse")
    {
        if (n2=="jacques-chirac")
        {
            cout<<v;
            return 0;
        }
        cout<<t;
        return 0;
    }
    if (r11=="father-in-law")
    {
        cout<<"dunno";
        return 0;
    }
    if (r11=="boss")
    {
        if (s1=="le-google-employed"||r12=="ticked-off"||r22=="ticked-off")
        {
            cout<<t;
            return 0;
        }
        cout<<v;
        return 0;
    }
    if (r11=="teacher")
    {
        if (a1>=a2+20)
        {
            cout<<t;
            return 0;
        }
        cout<<v;
        return 0;
    }
    cout<<v;
    return 0;
}