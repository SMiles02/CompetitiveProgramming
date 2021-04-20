#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,mx;
    cin>>n;
    int a[n];
    set<int> s;
    cin>>a[0];
    mx=a[0];
    for (int i=1;i<n;++i)
    {
        cin>>a[i];
        mx=max(a[i],mx);
        s.insert(a[i]-a[i-1]);
    }
    if (sz(s)==1||n==1)
        cout<<"0\n";
    else if (sz(s)==2&&*(s.begin())<0&&*(--s.end())>0&&mx<-*(s.begin())+*(--s.end()))
        cout<<-*(s.begin())+*(--s.end())<<" "<<*(--s.end())<<"\n"; 
    else
        cout<<"-1\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}