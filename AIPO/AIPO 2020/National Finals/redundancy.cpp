#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,total=0;
    cin>>n;
    map<int,int> first;
    map<int,int> second;
    map<int,int> dontShow;
    string s,t;
    vector<int> cur;
    cin>>s;
    while (cin>>t)
    {
        s+=" "+t;
    }
    while (sz(s)<n)
    {
        s+=" ";
    }
    for (int i=0;i<n;++i)
    {
        if (s[i]=='(')
        {
            ++total;
            first[total]=i;
            cur.push_back(total);
        }
        else if (s[i]==')')
        {
            second[cur.back()]=i;
            cur.pop_back();
        }
    }
    for (int i=1;i<total;++i)
    {
        if (first[i]+1==first[i+1]&&second[i]-1==second[i+1])
        {
            dontShow[first[i]]=1;
            dontShow[second[i]]=1;
        }
    }
    for (int i=0;i<n;++i)
    {
        if (!dontShow[i])
        {
            cout<<s[i];
        }
    }
    return 0;
}