#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //cout<<uniform_int_distribution<int>(1,2)(rng);
    //return 0;
    int n=7,q=30,l,r,x,k;
    int a[n+1];
    vector<int> v;
    cout<<n<<" "<<q<<"\n";
    for (int i=1;i<=n;++i)
    {
        a[i]=uniform_int_distribution<int>(1,10)(rng);
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    while (q--)
    {
        k=uniform_int_distribution<int>(1,3)(rng);
        l=uniform_int_distribution<int>(1,n)(rng);
        r=uniform_int_distribution<int>(l,n)(rng);
        x=uniform_int_distribution<int>(1,3)(rng);
        if (k==1)
        {
            cout<<k<<" "<<l<<" "<<r<<" "<<x<<"\n";
            for (int i=l;i<=r;++i)
                a[i]+=x;
        }
        if (k==2)
        {
            cout<<k<<" "<<l<<" "<<r<<" "<<x<<"\n";
            for (int i=l;i<=r;++i)
                a[i]=x;
        }
        if (k==3)
        {
            cout<<k<<" "<<l<<" "<<r<<"\n";
            int ans=0;
            for (int i=l;i<=r;++i)
                ans+=a[i];
            v.push_back(ans);
        }
    }
    cout<<"\n\n";
    for (int i : v)
        cout<<i<<"\n";
    return 0;
}