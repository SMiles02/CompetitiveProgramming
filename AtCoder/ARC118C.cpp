#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    cout<<"6 10 15 ";
    n-=3;
    for (int i=16;i<=10000&&n>0;++i)
        if (gcd(i,6)>1&&gcd(i,10)>1&&gcd(i,15)>1)
        {
            --n;
            cout<<i<<" ";
        }
    return 0;
}