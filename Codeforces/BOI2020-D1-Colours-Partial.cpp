#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,inp,l=69,r;
    cin>>n;
    for (int i=1;i<5;++i)
    {
        cout<<"? 1"<<endl;
        cin>>inp;
        cout<<"? "<<i*16<<endl;
        cin>>inp;
        if (inp)
        {
            l=i*16-15;
            r=i*16;
        }
    }
    if (l==69)
    {
        cout<<"= 64"<<endl;
        return;
    }
    for (int i=l;i<=r;++i)
    {
        cout<<"? 1"<<endl;
        cin>>inp;
        cout<<"? "<<i+1<<endl;
        cin>>inp;
        if (inp)
        {
            cout<<"= "<<i<<endl;
            return;
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}