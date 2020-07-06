#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x;
    cin>>n>>k;
    if (k%2)
        x=0;
    else
        x=-1;
    int a[n];
    multiset<int> m;
    multiset<int>::iterator it;
    for (int i=0;i<k;++i)
    {
        cin>>a[i];
        m.insert(a[i]);
    }
    it=next(m.begin(),k/2+x);
    cout<<*it<<" ";
    for (int i=k;i<n;++i)
    {
        cin>>a[i];
        m.insert(a[i]);
        if (a[i-k]<*it)
            ++it;
        if (a[i-k]==*it)
        {
            ++it;
            if (a[i-k])
        }
        m.erase(m.find(a[i-k]));
        cout<<*it<<" ";
    }
    return 0;
}