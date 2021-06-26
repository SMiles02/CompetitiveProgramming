#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
vector<vector<int>> v,w;

vector<vector<int>> sortBy(vector<int> t, int k)
{
    for (int i=0;i<n;++i)
        for (int j=i-1;j>=0&&v[t[j]][k]<v[t[j+1]][k];--j)
            swap(t[j],t[j+1]);
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    v.resize(n,vector<int> (n));
    w.resize(n,vector<int> (n));
    vector<int> a(n),b(n),c;
    map<vector<int>,deque<int>> m;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
            cin>>v[i][j];
        m[v[i]].push_back(i);
        a[i]=i;
    }
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
            cin>>w[i][j];
        if (m[w[i]].empty())
        {
            cout<<-1;
            return 0;
        }
        b[i]=m[w[i]].front();
        m[w[i]].pop_front();
    }
    for (int i=0;i<n;++i)
    {
        c=sortBy(b,i);
        if (a==c)
        {
            cout<<"1 ";
        }
    }
    return 0;
}