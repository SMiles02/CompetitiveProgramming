#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x;
    cin>>n>>m;
    multiset<int> s;
    multiset<int>::iterator it;
    while (n--)
    {
        cin>>x;
        s.insert(x);
    }
    while (m--)
    {
        cin>>x;
        if (!sz(s))
        {
            cout<<"-1\n";
            continue;
        }
        it=s.begin();
        if (*it>x)
        {
            cout<<"-1\n";
            continue;
        }
        if (*it==x)
        {
            cout<<*it<<"\n";
            s.erase(it);
            continue;
        }
        it=s.upper_bound(x);
        --it;
        cout<<*it<<"\n";
        s.erase(it);
    }
    return 0;
}