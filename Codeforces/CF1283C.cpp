#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int doesntGive[200001];
int getter[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (!a[i])
        {
            doesntGive[i]=1;
        }
        else
        {
            getter[a[i]]=1;
        }
    }
    vector<int> needToGive;
    vector<int> needToGet;
    vector<int> both;
    for (int i=1;i<=n;++i)
    {
        if (doesntGive[i]&&!getter[i])
            both.push_back(i);
        else if (doesntGive[i])
            needToGive.push_back(i);
        else if (!getter[i])
            needToGet.push_back(i);
    }
    if (sz(both)==1)
    {
        a[both[0]]=needToGet.back();
        a[needToGive.back()]=both[0];
        needToGive.pop_back();
        needToGet.pop_back();
        both.pop_back();
    }
    else if (sz(both))
    {
        for (int i=0;i<sz(both)-1;++i)
        {
            a[both[i]]=both[i+1];
        }
        a[both[sz(both)-1]]=both[0];
    }
    while (sz(needToGet))
    {
        a[needToGive.back()]=needToGet.back();
        needToGive.pop_back();
        needToGet.pop_back();
    }
    for (int i=1;i<=n;++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}