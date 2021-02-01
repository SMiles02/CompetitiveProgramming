#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int books[1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,a,b;
    cin>>n>>m;
    while (m--)
    {
        for (int i=0;i<n;++i)
        {
            books[i]=max(0,books[i]-1);
        }
        cin>>k;
        while (k--)
        {
            cin>>a>>b;
            if (books[a])
            {
                cout<<"0\n";
            }
            else
            {
                cout<<"1\n";
                books[a]=b;
            }
        }
    }
    return 0;
}