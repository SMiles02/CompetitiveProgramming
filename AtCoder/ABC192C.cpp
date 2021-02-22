#include <bits/stdc++.h>
using namespace std;

string oop = "0123456789";

int toInt(string s)
{
    int ans=0;
    while (!s.empty())
    {
        ans*=10;
        ans+=(s.back()-'0');
        s.pop_back();
    }
    return ans;
}

int f(int n)
{
    int x,y;
    string s="";
    while (n)
    {
        s+=oop[n%10];
        n/=10;
    }
    sort(s.begin(), s.end());
    x=toInt(s);
    sort(s.rbegin(), s.rend());
    y=toInt(s);
    return x-y;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    while (k--)
        n=f(n);
    cout<<n;
    return 0;
}