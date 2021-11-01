#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=1;
    string a,b,c;
    cin>>n;
    map<string,int> chainLength;
    chainLength["polycarp"]=1;
    while (n--)
    {
        cin>>a>>b>>c;
        chainLength[to_lower(a)]=chainLength[to_lower(c)]+1;
        ans=max(ans,chainLength[to_lower(a)]);
    }
    cout<<ans;
    return 0;
}