#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string s;
map<int,int> m;

string f(int l, int r)
{
    int cur=0;
    string t="",u="";
    //cout<<l<<" "<<r<<"\n";
    for (int i=l;i<=r;++i)
    {
        if (s[i]=='(')
        {
            t+=f(i+1,m[i]-1);
            i=m[i];
        }
        else if ('0'<=s[i]&&s[i]<='9')
        {
            cur*=10;
            cur+=(s[i]-'0');
        }
        else
            t+=s[i];
    }
    cur=max(cur,1);
    for (int i=0;i<cur;++i)
        u+=t;
    //cout<<cur<<"\n";
    //cout<<t<<"\n";
    //cout<<l<<" "<<r<<" "<<u<<"\n";
    return u;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    int n=sz(s);
    stack<int> st;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='(')
            st.push(i);
        else if (s[i]==')')
        {
            m[st.top()]=i;
            st.pop();
        }
    }
    cout<<f(0,n-1);
    return 0;
}