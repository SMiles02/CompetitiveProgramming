#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    while (n--)
    {
        cin>>k;
        if (k%3==0)
            cout<<k/3<<" 0 0\n";
        else if (k%3==1)
        {
            if (k==1||k==4)
                cout<<"-1\n";
            else
                cout<<(k-7)/3<<" 0 1\n";
        }
        else if (k==2)
            cout<<"-1\n";
        else
            cout<<(k-5)/3<<" 1 0\n";
    }
    return 0;
}