#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int checker(int k,int x)
{
    if (k==x*9)
    {
        return 9;
    }
    for (int i=1;i<10;++i)
    {
        if (k<x*i)
        {
            return i-1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        //cout<<n<<" = ";
        if (n==1000000000) //9
        {
            cout<<9*9+checker(n,1111111111)<<"\n";
        }
        else if (n>=100000000) //8
        {
            cout<<9*8+checker(n,111111111)<<"\n";
        }
        else if (n>=10000000) //7
        {
            cout<<9*7+checker(n,11111111)<<"\n";
        }
        else if (n>=1000000) //6
        {
            cout<<9*6+checker(n,1111111)<<"\n";
        }
        else if (n>=100000) //5
        {
            cout<<9*5+checker(n,111111)<<"\n";
        }
        else if (n>=10000) //4
        {
            cout<<9*4+checker(n,11111)<<"\n";
        }
        else if (n>=1000) //3
        {
            cout<<9*3+checker(n,1111)<<"\n";
        }
        else if (n>=100) //2
        {
            cout<<9*2+checker(n,111)<<"\n";
        }
        else if (n>=10) //1
        {
            cout<<9*1+checker(n,11)<<"\n";
        }
        else
        {
            cout<<n<<"\n";
        }
    }
    return 0;
}