#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;
int a[100][100];
int b[100][100];

int check(int k)
{
    int x,cc=k;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            b[i][j]=0;
    for (int j=0;j<m;++j)
    {
        b[0][j]=k;
        if (b[0][j]<a[0][j])
        {
            x=a[0][j]-b[0][j];
            cc+=x;
            for (int i=0;i<n;++i)
                b[i][j]+=x;
        }
    }
    for (int i=1;i<n;++i)
        if (b[i][0]<a[i][0])
        {
            x=a[i][0]-b[i][0];
            cc+=x;
            for (int j=0;j<m;++j)
                b[i][j]+=x;
        }
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (a[i][j]!=b[i][j])
                return -1;
    return cc;
}

void make(int k)
{
    int x;
    vector<int> r;
    vector<int> c;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            b[i][j]=0;
    for (int i=0;i<k;++i)
        r.push_back(1);
    for (int j=0;j<m;++j)
    {
        b[0][j]=k;
        if (b[0][j]<a[0][j])
        {
            x=a[0][j]-b[0][j];
            for (int i=0;i<x;++i)
                c.push_back(j+1);
            for (int i=0;i<n;++i)
                b[i][j]+=x;
        }
    }
    for (int i=1;i<n;++i)
        if (b[i][0]<a[i][0])
        {
            x=a[i][0]-b[i][0];
            for (int j=0;j<x;++j)
                r.push_back(i+1);
            for (int j=0;j<m;++j)
                b[i][j]+=x;
        }
    cout<<sz(r)+sz(c)<<"\n";
    for (int i : r)
        cout<<"row "<<i<<"\n";
    for (int i : c)
        cout<<"col "<<i<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    int xx;
    vector<pair<int,int>> v;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    for (int i=0;i<=500;++i)
    {
        xx=check(i);
        if (xx>=0)
            v.push_back({xx,i});
    }
    if (sz(v)==0)
    {
        cout<<-1;
        return 0;
    }
    sort(v.begin(), v.end());
    make(v[0].second);
    return 0;
}