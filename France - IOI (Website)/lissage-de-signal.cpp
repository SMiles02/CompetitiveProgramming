#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
double a[100];
double b[100];
double diffMax;

void honHon()
{
    for (int i=1;i<n-1;++i)
    {
        b[i]=(a[i-1]+a[i+1])/2;
    }
    for (int i=1;i<n-1;++i)
    {
        a[i]=b[i];
    }
    return;
}

int works()
{
    for (int i=0;i<n-1;++i)
    {
        if (abs(a[i]-a[i+1])>diffMax)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>diffMax;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for (int i=0;i<5001;++i)
    {
        if (works())
        {
            cout<<i;
            return 0;
        }
        honHon();
    }
    return 0;
}