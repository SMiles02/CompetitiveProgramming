#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int checker(string s,int n)
{
    for (int i=1;i<n;++i)
    {
        if (s[i]!=s[0])
        {
            return 0;
        }
    }
    return 1;
}

ll curAns(string s,int n)
{
    ll ans=0;
    for (int i=0;i<n-1;++i)
    {
        if (s[i]==s[i+1])
        {
            s[i+1]='0';
            ++ans;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s,t;
    ll k,ans=0,n;
    cin>>s;
    cin>>k;
    n=s.size();
    if (n==1)
    {
        cout<<k/2;
        return 0;
    }
    if (n==2)
    {
        if (s[0]==s[1])
        {
            cout<<k;
        }
        else
        {
            cout<<0;
        }
        return 0;
    }
    if (checker(s,n))
    {
        cout<<(n*k)/2;
        return 0;
    }
    ll ans1,ans2,ans3;
    t=s;
    ans1=curAns(t,n);
    t+=s;
    ans2=curAns(t,2*n);
    t+=s;
    ans3=curAns(t,3*n);
    if (ans3-ans2==ans2-ans1)
    {
        cout<<ans1+((ans2-ans1)*(k-1));
        return 0;
    }
    //cout<<"not linear\n";
    for (int i=0;i<n-1;++i)
    {
        if (s[i]==s[i+1])
        {
            if (s[i]=='a'||s[(i+2)%n]=='a')
            {
                if (s[i]=='b'||s[(i+2)%n]=='b')
                {
                    s[i+1]='c';
                }
                else
                {
                    s[i+1]='b';
                }
            }
            else
            {
                s[i+1]='a';
            }
            ++ans;
        }
    }
    ans*=k;
    if (s[n-1]==s[0])
    {
        ans+=(k-1);
    }
    cout<<ans;
    return 0;
}