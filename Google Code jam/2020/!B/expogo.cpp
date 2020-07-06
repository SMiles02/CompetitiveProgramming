#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int cases=0;
int powers[30];

int firstGreater(int x)
{
    int l=0,r,m;
}

void solve()
{
    ++cases;
    cout<<"Case #"<<cases<<": ";

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    powers[0]=1;
    for (int i=1;i<30;++i)
    {
        powers[i]=powers[i-1]*2;
    }
    int n;
    cin>>n;
    while (n--) solve();
    return 0;
}