#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n, a[2000];

bool check(int k)
{
    int c=a[2*n-1],x,y;
    multiset<int> s;
    for (int i=0;i+1<2*n;++i)
        s.insert(a[i]);
    s.erase(s.find(a[k]));
    vector<array<int,2>> v(n);
    for (int i=1;i<n;++i)
    {
        x=*(--s.end());
        s.erase(s.find(x));
        y=c-x;
        if (s.find(y)==s.end())
            return 0;
        s.erase(s.find(y));
        c=v[i][0]=x;
        v[i][1]=y;
    }
    cout<<"YES\n"<<a[2*n-1]+a[k]<<"\n"<<a[2*n-1]<<" "<<a[k]<<"\n";
    for (int i=1;i<n;++i)
        cout<<v[i][0]<<" "<<v[i][1]<<"\n";
    return 1;
}

void solve()
{
    cin>>n;
    for (int i=0;i<2*n;++i)
        cin>>a[i];
    sort(a,a+(2*n));
    for (int i=0;i+1<2*n;++i)
        if (check(i))
            return;
    cout<<"NO\n";
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