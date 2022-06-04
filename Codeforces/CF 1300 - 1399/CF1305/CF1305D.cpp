#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
bool edges[1001][1001];
int edgeNumber[1001];
bool done[1001];

void deleteNode(int x)
{
    for (int i=1;i<=n;++i)
    {
        if (edges[i][x])
        {
            edges[i][x]=0;
            edges[x][i]=0;
            --edgeNumber[i];
            --edgeNumber[x];
        }
    }
}

int main()
{
    int a,b,c,cur;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
        ++edgeNumber[a];
        ++edgeNumber[b];
    }
    while (1)
    {
        a=0;b=0;
        for (cur=1;(!a)&&cur<=n;++cur)
        {
            if (edgeNumber[cur]==1)
            {
                a=cur;
            }
            else if ((!edgeNumber[cur])&&(!done[cur]))
            {
                cout<<"! "<<cur;
                return 0;
            }
        }
        for (;(!b)&&cur<=n;++cur)
        {
            if (edgeNumber[cur]==1)
            {
                b=cur;
            }
            else if ((!edgeNumber[cur])&&(!done[cur]))
            {
                cout<<"! "<<cur;
                return 0;
            }
        }
        if (!b)
        {
            cout<<"! "<<a;
            return 0;
        }
        cout<<"? "<<a<<" "<<b<<"\n";
        cin>>c;
        if (c==a)
        {
            cout<<"! "<<a;
            return 0;
        }
        if (c==b)
        {
            cout<<"! "<<b;
            return 0;
        }
        done[a]=1;
        done[b]=1;
        deleteNode(a);
        deleteNode(b);
    }
    return 0;
}