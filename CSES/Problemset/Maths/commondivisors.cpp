#include <bits/stdc++.h>
using namespace std;
 
const int m = 1e6+1;
int f[m];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    while (n--)
    {
        cin>>k;
        ++f[k];
    }
    for (int i=m-1;;--i)
    {
        k=0;
        for (int j=i;j<m;j+=i)
            k+=f[j];
        if (k>1)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}