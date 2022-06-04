#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int n,a[200000],ans[200000],qC=0;
bool local = 0;

void makeQ(int k)
{
    if (a[k]==0)
    {
        cout<<"? "<<k<<endl;
        ++qC;
        if (local)
            a[k]=ans[k];
        else
            cin>>a[k];
    }
}

void printAns(int k)
{
    cout<<"! "<<k<<endl;
    if (local)
        cout<<"Queries: "<<qC<<endl;
}

int main()
{
    cin>>n;
    if (n==1)
    {
        printAns(1);
        return 0;
    }
    if (local)
    {
        for (int i=1;i<=n;++i)
            cin>>ans[i];
    }
    for (int i=0;i<n+2;++i)
        a[i]=0;
    a[0]=a[n+1]=n+5;
    int l=1,r=n,m;
    while (l^r)
    {
        m=l+(r-l)/2;
        makeQ(m);
        makeQ(m+1);
        makeQ(m-1);
        if (a[m]<min(a[m-1],a[m+1]))
        {
            printAns(m);
            return 0;
        }
        if (a[m-1]<a[m+1])
            r=m-1;
        else
            l=m+1;
    }
    for (int i=1;i<=n;++i)
        if (a[i]&&a[i]<min(a[i-1],a[i+1]))
        {
            printAns(i);
            return 0;
        }
    return 0;
}