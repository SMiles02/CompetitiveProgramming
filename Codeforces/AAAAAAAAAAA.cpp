#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int big(int n)
{
    vector<int> v;
    while (n)
    {
        v.push_back(n%10);
        n/=10;
    }
    sort(v.begin(), v.end());
    int cur=0;
    for (int i : v)
    {
        cur*=10;
        cur+=i;
    }
    return cur;
}

int small(int n)
{
    vector<int> v;
    while (n)
    {
        v.push_back(n%10);
        n/=10;
    }
    sort(v.rbegin(), v.rend());
    int cur=0;
    for (int i : v)
    {
        cur*=10;
        cur+=i;
    }
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<=100000;++i)
        if (big(i)-small(i)==i)
            cout<<i<<"\n";
    return 0;
}