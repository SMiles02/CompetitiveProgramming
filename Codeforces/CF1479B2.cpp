#include <bits/stdc++.h>
using namespace std;

vector<int> nextO[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x=0,y=0,ans=0;
    cin>>n;
    int a[n];
    nextO[n].push_back(n);
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        nextO[i].push_back(n);
    }
    for (int i=n-1;i+1;--i)
        nextO[a[i]].push_back(i);
    for (int i=0;i<n;++i)
    {
        if (x==y)
        {
            if (x^a[i])
            {
                ++ans;
                x=a[i];
            }
        }
        else if (x==a[i])
            x=a[i];
        else if (y==a[i])
            y=a[i];
        else if (nextO[x].back()>nextO[y].back())
        {
            ++ans;
            x=a[i];
        }
        else
        {
            ++ans;
            y=a[i];
        }
        nextO[a[i]].pop_back();
    }
    cout<<ans;
    return 0;
}