#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define ppi pair<pii,pii>
#define f first
#define s second
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ppi p[n];
    for (int i=0;i<n;++i)
    {
        cin>>p[i].f.f>>p[i].f.s>>p[i].s.f>>p[i].s.s;
        if (p[i].f.f>p[i].s.f||(p[i].f.f==p[i].s.f&&p[i].f.s>p[i].s.s))
        {
            swap(p[i].f.f,p[i].s.f);
            swap(p[i].f.s,p[i].s.s);
        }
    }
    if (p[0].f.f==p[0].s.f)
    {
        sort(p,p+n);
        for (int i=0;i+1<n;++i)
            cout<<p[i].s.f<<" "<<p[i].s.s<<" "<<p[i+1].f.f<<" "<<p[i+1].f.s<<"\n";
        return 0;
    }
    long double m=(p[0].f.s-p[0].s.s);
    m/=(p[0].f.f-p[0].s.f);
    pair<long double,int> a[n];
    for (int i=0;i<n;++i)
    {
        a[i].s=i;
        a[i].f=p[i].f.s;
        a[i].f-=(m*p[i].f.f);
    }
    sort(a,a+n);
    /**for (int i=0;i<n;++i)
        cout<<a[i].s<<" ";
    cout<<"\n";
    for (int i=0;i<n;++i)
        cout<<a[i].f<<" ";
    cout<<"\n";**/
    for (int i=0;i+1<n;++i)
        cout<<p[a[i].s].s.f<<" "<<p[a[i].s].s.s<<" "<<p[a[i+1].s].f.f<<" "<<p[a[i+1].s].f.s<<"\n";
    return 0;
}