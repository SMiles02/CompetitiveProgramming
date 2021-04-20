#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPrime(int n)
{
    if (n==1)
        return 0;
    for (ll i=2;i*i<=n;++i)
        if (n%i==0)
            return 0;
    return 1;
}

int base(int n, int b)
{
    int rtn=0;
    while (n)
    {
        rtn+=(n%b);
        n/=b;
    }
    return rtn;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    if (!isPrime(n))
    {
        cout<<"NOT";
        return 0;
    }
    for (int i=2;i<10;++i)
        if (!isPrime(base(n,i)))
        {
            cout<<"NOT";
            return 0;
        }
    cout<<"YES";
    return 0;
}