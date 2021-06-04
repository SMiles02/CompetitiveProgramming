#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in.txt","w",stdout);
    int n = uniform_int_distribution<int>(12,16)(rng), q = 20;
    cout << n << " " << q << endl;
    for (int i=1;i<=n;++i)
        cout << uniform_int_distribution<int>(1,n)(rng) << " ";
    cout << endl;
    int t,x,y;
    while (q--)
    {
        t=uniform_int_distribution<int>(0,1)(rng);
        cout << t << " ";
        if (t==0)
        {
            x=uniform_int_distribution<int>(1,n)(rng);
            y=uniform_int_distribution<int>(1,n)(rng);
            cout << x << " " << y << endl;
        }
        else
        {
            x=uniform_int_distribution<int>(1,n)(rng);
            cout << x << endl;
        }
    }
    return 0;
}