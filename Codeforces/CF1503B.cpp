#include <bits/stdc++.h>
using namespace std;

vector<array<int,2>> v[3];

void print(int x, array<int,2> a)
{
    cout<<x<<" "<<a[0]<<" "<<a[1]<<endl;
}

int main()
{
    int n,k;
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            v[((i+j)&1)+1].push_back({i,j});
    n*=n;
    while (n--)
    {
        cin>>k;
        if (k!=1&&!v[1].empty())
        {
            print(1,v[1].back());
            v[1].pop_back();
        }
        else if (k!=2&&!v[2].empty())
        {
            print(2,v[2].back());
            v[2].pop_back();
        }
        else if (!v[1].empty())
        {
            print(3,v[1].back());
            v[1].pop_back();
        }
        else
        {
            print(3,v[2].back());
            v[2].pop_back();
        }
    }
    return 0;
}