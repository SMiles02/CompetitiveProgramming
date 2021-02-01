#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve()
{
    string s;
    int n;
    cin>>s;
    n=sz(s);
    s=to_lower(s);
    for (int i=0;i<n;++i)
    {
        if (s[i]=='a') cout<<"Hi! ";
        if (s[i]=='e') cout<<"Bye! ";
        if (s[i]=='i') cout<<"How are you? ";
        if (s[i]=='o') cout<<"Follow me! ";
        if (s[i]=='u') cout<<"Help! ";
        if ('0'<=s[i]&&s[i]<='9') cout<<"Yes! ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}