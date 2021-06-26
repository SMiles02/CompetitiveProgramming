#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,minCost=100000,best=1,cur,k;
    int a[9];
    cin>>n;
    for (int i=0;i<9;++i)
    {
        cin>>a[i];
        if (a[i]<=minCost)
        {
            best=i+1;
            minCost=a[i];
        }
    }
    if (minCost>n)
    {
        cout<<-1;
        return 0;
    }
    string s(n/minCost,('0'+best));
    vector<int> v;
    for (int i=0;i<9;++i)
    {
        v.push_back(i);
    }
    cur=n%minCost;
    n/=minCost;
    k=9;
    for (int i=0;i<n;++i)
    {
        while (k&&(a[v.back()]-minCost)>cur)
        {
            v.pop_back();
            --k;
        }
        if (k)
        {
            cur-=a[v.back()];
            cur+=minCost;
            s[i]=('0'+v.back()+1);
        }
        else
        {
            cout<<s;
            return 0;
        }
    }
    cout<<s;
    return 0;
}