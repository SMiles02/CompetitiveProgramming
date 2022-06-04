#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define pip pair<int,pii>
#define f first
#define s second
using namespace std;

int n,a[300][300];
string str[300],t[300];

bool ok(int a, int b)
{
    if (a<0||b<0)
        return 0;
    if (a>=n||b>=n)
        return 0;
    if (t[a][b]=='X')
        return 1;
    return 0;
}

void smol(int x1, int y1, int x2, int y2)
{
    --a[x1][y1];
    --a[x2][y2];
}

void solve()
{
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>str[i];
        for (int j=0;j<n;++j)
            a[i][j]=0;
    }
    for (int i=0;i<n;++i)
        for (int j=0;j+2<n;++j)
            if (str[i][j]=='X'&&str[i][j+1]=='X'&&str[i][j+2]=='X')
            {
                ++a[i][j];
                ++a[i][j+1];
                ++a[i][j+2];
            }
    for (int i=0;i<n;++i)
        for (int j=0;j+2<n;++j)
            if (str[j][i]=='X'&&str[j+1][i]=='X'&&str[j+2][i]=='X')
            {
                ++a[j][i];
                ++a[j+1][i];
                ++a[j+2][i];
            }
    priority_queue<pip> pq;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            //cout<<a[i][j];
            if (a[i][j])
                pq.push({a[i][j],{i,j}});
        }
        //cout<<"\n";
    }
    pip p;
    int i,j;
    while (!pq.empty())
    {
        p=pq.top();
        pq.pop();
        if (p.f!=a[p.s.f][p.s.s])
        {
            pq.push({a[p.s.f][p.s.s],{p.s.f,p.s.s}});
            continue;
        }
        if (p.f==0)
            break;
        i=p.s.f;
        j=p.s.s;
        for (int k=max(0,i-2);k<min(n,i+3);++k)
            t[k][j]=str[k][j];
        for (int k=max(0,j-2);k<min(n,j+3);++k)
            t[i][k]=str[i][k];
        //cout<<a[i][j]<<"\n";
        cout<<i<<" "<<j<<"\n";
        str[i][j]='O';
        a[i][j]=0;
        if (ok(i-1,j)&&ok(i-2,j))
            smol(i-1,j,i-2,j);
        if (ok(i+1,j)&&ok(i+2,j))
            smol(i+1,j,i+2,j);
        if (ok(i-1,j)&&ok(i+1,j))
            smol(i-1,j,i+1,j);
        if (ok(i,j-1)&&ok(i,j-2))
            smol(i,j-1,i,j-2);
        if (ok(i,j+1)&&ok(i,j+2))
            smol(i,j+1,i,j+2);
        if (ok(i,j-1)&&ok(i,j+1))
            smol(i,j-1,i,j+1);
        for (int i=0;i<n;++i)
            cout<<str[i]<<"\n";
        cout<<"\n";
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<n;++j)
                cout<<a[i][j];
            cout<<"\n";
        }
        cout<<"\n";
    }
    for (int i=0;i<n;++i)
        cout<<str[i]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}