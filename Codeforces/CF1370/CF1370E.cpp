#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,cur,ans=0;
    cin>>n;
    string a,b;
    cin>>a;
    cin>>b;
    set<int> s;
    set<int> t;
    vector<int> v;
    vector<int> w;
    vector<int> x;
    vector<int> y;
    set<int>::iterator it1;
    set<int>::iterator it2;
    for (int i=0;i<n;++i)
    {
        if (a[i]=='1'&&b[i]=='0')
            s.insert(i);
        else if (a[i]=='0'&&b[i]=='1')
            t.insert(i);
    }
    if (sz(s)!=sz(t))
    {
        cout<<-1;
        return 0;
    }
    while (sz(s))
    {
        ++ans;
        cur=-1;
        v.clear();
        w.clear();
        x.clear();
        y.clear();
        while (1)
        {
            it1=s.lower_bound(cur);
            if (it1==s.end())
                break;
            it2=t.lower_bound(*it1);
            if (it2==t.end())
                break;
            cur=*it2;
            v.push_back(*it1);
            w.push_back(*it2);
            s.erase(it1);
            t.erase(it2);
        }
        for (int i : v)
            s.insert(i);
        for (int i : w)
            t.insert(i);
        cur=-1;
        while (1)
        {
            it1=t.lower_bound(cur);
            if (it1==t.end())
                break;
            it2=s.lower_bound(*it1);
            if (it2==s.end())
                break;
            cur=*it2;
            x.push_back(*it1);
            y.push_back(*it2);
            t.erase(it1);
            s.erase(it2);
        }
        if (sz(v)>sz(x))
        {
            for (int i : x)
                t.insert(i);
            for (int i : y)
                s.insert(i);
            for (int i : v)
                s.erase(s.lower_bound(i));
            for (int i : w)
                t.erase(t.lower_bound(i));
        }
    }
    cout<<ans;
    return 0;
}