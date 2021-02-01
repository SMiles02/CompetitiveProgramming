#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    int a[4];
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>n;
    sort(a,a+4);
    if (n==4)
    {
        if (a[0]==a[3]) cout<<1;
        else cout<<0;
    }
    if (n==3)
    {
        if (a[0]==a[1]&&a[2]==a[3]) cout<<1;
        else cout<<0;
    }
    if (n==1)
    {
        if (a[0]+a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
    }
    if (n==2)
    {
        if (a[0]+a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
    }
    return 0;
}