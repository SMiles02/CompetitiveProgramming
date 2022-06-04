#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string alpha="abcdefghijklmnopqrstuvwxyz";
int a[50];

void print()
{
    for (int i=0;i<50;++i)
        cout<<alpha[a[i]];
    cout<<"\n";
}

void solve()
{
    int n,k;
    cin>>n;
    for (int i=0;i<50;++i)
        a[i]=0;
    print();
    while (n--)
    {
        cin>>k;
        for (int i=k;i<50;++i)
            a[i]=(++a[i])%26;
        print();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}