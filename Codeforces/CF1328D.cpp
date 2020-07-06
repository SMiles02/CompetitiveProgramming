#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    set<int> s;
    int n,totalDiff=0,f=0;
    cin>>n;
    int a[n];
    cin>>a[0];
    s.insert(a[0]);
    for (int i=1;i<n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
        if (a[i]!=a[i-1])
        {
            ++totalDiff;
        }
    }
    if (a[0]!=a[n-1])
    {
        ++totalDiff;
    }
    if (sz(s)==1)
    {
        cout<<"1\n";
        for (int i=0;i<n;++i)
        {
            cout<<"1 ";
        }
        cout<<"\n";
        return;
    }
    if (n%2==0)
    {
        cout<<"2\n";
        for (int i=0;i<n;++i)
        {
            if (i%2)
            {
                cout<<"2 ";
            }
            else
            {
                cout<<"1 ";
            }
        }
        cout<<"\n";
        return;
    }
    if (totalDiff!=n)
    {
        cout<<"2\n";
        if (a[0]==a[n-1])
        {
            cout<<"2 ";
            f=1;
        }
        else
        {
            cout<<"1 ";
        }
        for (int i=1;i<n;++i)
        {
            if (f)
            {
                if (i%2)
                {
                    cout<<"1 ";
                }
                else
                {
                    cout<<"2 ";
                }
            }
            else
            {
                if (a[i]==a[i-1])
                {
                    if (i%2)
                    {
                        cout<<"1 ";
                    }
                    else
                    {
                        cout<<"2 ";
                    }
                    f=1;
                }
                else
                {
                    if (i%2)
                    {
                        cout<<"2 ";
                    }
                    else
                    {
                        cout<<"1 ";
                    }
                }
            }
        }
        cout<<"\n";
        return;
    }
    cout<<"3\n";
    for (int i=1;i<n;++i)
    {
        if (i%2)
        {
            cout<<"1 ";
        }
        else
        {
            cout<<"2 ";
        }
    }
    cout<<"3\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}