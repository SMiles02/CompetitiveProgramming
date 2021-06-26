#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int query(int x, int y)
{
    int k;
    cout<<"? "<<x<<" "<<y<<endl;
    cin>>k;
    return k;
}

int main()
{
    int n,a,b,c,d,e;
    cin>>n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end(), rng);
    a=p[0];b=p[1];c=query(a,b);
    for (int i=2;i<n;++i)
    {
        d=query(b,p[i]);
        if (d<c)
        {
            a=p[i];
            c=d;
        }
        else if (c==d)
        {
            b=p[i];
            c=query(a,b);
        }
    }
    while (1)
    {
        e=uniform_int_distribution<int>(1,n)(rng);
        if (a==e||b==e)
            continue;
        c=query(a,e);d=query(b,e);
        if (c<d)
            break;
        else if (d<c)
        {
            a=b;
            break;
        }
    }
    int ans[n+1];
    for (int i=1;i<=n;++i)
    {
        if (a==i)
            ans[i]=0;
        else
            ans[i]=query(a,i);
    }
    cout<<"! ";
    for (int i=1;i<=n;++i)
        cout<<" "<<ans[i];
    cout<<endl;
    return 0;
}