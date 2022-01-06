// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+1;
int r[N];

void precalc()
{
    int c,x;
    for (int i=2;i<N;++i)
        if (r[i]==0)
            for (int j=i;j<N;j+=i)
            {
                if ((j/i)%i)
                    ++r[j];
                else
                    r[j]+=N;
            }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    precalc();
    int ct=0;
    for (int i=2;i<N;++i)
        ct += (r[i]<N);
    cout<<ct;
    return 0;
}