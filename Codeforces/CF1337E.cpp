#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int pos[3001];
map<char,vector<int>> record;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    string s,t;
    cin>>s;
    cin>>t;
    n=sz(s);
    m=sz(t);
    pos[0]=1;
    for (int i=1;i<=m;++i)
    {   
        record[t[m-i]].push_back(i);
    }
    
    return 0;
}