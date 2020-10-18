#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[1007],ans,n,s,c;

void printA()
{
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    cout<<"\n";
}

void check()
{
    c=0;
    for (int i=1;i<=n;++i)
    {
        c+=a[i];
        if (c*2==s)
        {
            ++ans;
            //printA();
            return;
        }
    }
}

void solve(int n)
{
    //cout<<n<<": ";
    if (n%4==1||n%4==2)
    {
        cout<<"0\n";
        return;
    }
    s=(n*(n+1))/2;
    ans=0;
    for (int i=1;i<=n;++i)
        a[i]=i;
    for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;++j)
        {
            swap(a[i],a[j]);
            check();
            swap(a[i],a[j]);
        }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
        solve(i);
    return 0;
}