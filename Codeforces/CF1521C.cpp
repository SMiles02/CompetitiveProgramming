#include <bits/stdc++.h>
using namespace std;

bool local = 0;
int inp[10001];

int query(int t, int i, int j, int x)
{
    int k;
    cout<<"? "<<t<<" "<<i<<" "<<j<<" "<<x<<endl;
    if (local)
    {
        if (t==1)
            k=max(min(x,inp[i]),min(x+1,inp[j]));
        else
            k=min(max(x,inp[i]),max(x+1,inp[j]));
    }
    else
        cin>>k;
    return k;
}

bitset<10001> b;

void solve()
{
    int n,x,y;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        b[i]=0;
        if (local)
            cin>>inp[i];
    }
    int a[n+2],ans[n+2];
    for (int i=1;i<n;i+=2)
    {
        a[i]=query(2,i,i+1,1);
        if (a[i]==2)
        {
            x=query(2,i+1,i,1);
            if (x==1)
                a[i]=1;
        }
        a[i+1]=query(1,i,i+1,n-1);
        if (a[i+1]==n-1)
        {
            x=query(1,i+1,i,n-1);
            if (x==n)
                a[i+1]=n;
        }
        b[a[i]]=1;
        b[a[i+1]]=1;
    }
    for (int i=1;i<=n;++i)
        if (b[i]==0)
        {
            a[n]=i;
            ans[n]=i;
        }
    for (int i=1;i+3<=n;i+=4)
    {
        y=query(2,i+1,i+2,1);
        if (y==2)
        {
            x=query(2,i+2,i+1,1);
            if (x==1)
                y=1;
        }
        if (a[i+1]==y)
            ans[i+1]=y,ans[i]=a[i];
        else if (a[i]==y)
            ans[i+1]=y,ans[i]=a[i+1];
        else if (a[i+2]==y)
            ans[i+2]=y,ans[i+3]=a[i+3];
        else
            ans[i+2]=y,ans[i+3]=a[i+2];

        y=query(1,i+1,i+2,n-1);
        if (y==n-1)
        {
            x=query(1,i+2,i+1,n-1);
            if (x==n)
                y=n;
        }
        if (a[i+1]==y)
            ans[i+1]=y,ans[i]=a[i];
        else if (a[i]==y)
            ans[i+1]=y,ans[i]=a[i+1];
        else if (a[i+2]==y)
            ans[i+2]=y,ans[i+3]=a[i+3];
        else
            ans[i+2]=y,ans[i+3]=a[i+2];
    }
    if (n%4==2)
    {
        y=query(2,n-2,n-1,1);
        if (y==2)
        {
            x=query(2,n-1,n-2,1);
            if (x==1)
                y=1;
        }
        if (a[n]!=y&&a[n-1]!=y)
        {
            y=query(1,n-2,n-1,n-1);
            if (y==n-1)
            {
                x=query(1,n-1,n-2,n-1);
                if (x==n)
                    y=n;
            }
        }
        if (a[n-1]==y)
            ans[n-1]=a[n-1],ans[n]=a[n];
        else
            ans[n-1]=a[n],ans[n]=a[n-1];
    }
    if (n%4==3)
    {
        y=query(2,n-1,n,1);
        if (y==2)
        {
            x=query(2,n,n-1,1);
            if (x==1)
                y=1;
        }
        if (a[n-2]!=y&&a[n-1]!=y)
        {
            y=query(1,n-1,n,n-1);
            if (y==n-1)
            {
                x=query(1,n,n-1,n-1);
                if (x==n)
                    y=n;
            }
        }
        if (a[n-1]==y)
            ans[n-2]=a[n-2],ans[n-1]=a[n-1];
        else
            ans[n-2]=a[n-1],ans[n-1]=a[n-2];
    }
    cout<<"! ";
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}