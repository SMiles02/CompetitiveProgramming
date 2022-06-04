// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string s;

bool check(int x)
{
    return (s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c');
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,ct=0,k;
    char c;
    cin>>n>>q;
    cin>>s;
    for (int i=0;i+2<n;++i)
        ct += check(i);
    while (q--)
    {
        cin>>k>>c;
        for (int i=max(k-3,0);i+2<n&&i<k;++i)
            ct-=check(i);
        s[k-1]=c;
        for (int i=max(k-3,0);i+2<n&&i<k;++i)
            ct+=check(i);
        cout<<ct<<"\n";
    }
    return 0;
}