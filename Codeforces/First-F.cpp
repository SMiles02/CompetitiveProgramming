#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,a,b;
    cin>>n>>m>>x>>y;
    if (n%2==0)
    {
        a=x;
        b=y;
        for (int i=1;i<m;++i)
        {
            if (b>m)
            {
                b-=m;
            }
            cout<<a<<" "<<b<<"\n";
            ++b;
        }
        if (b>m)
        {
            b-=m;
        }
        cout<<a<<" "<<b<<"\n";
        for (int i=1;i<n;++i)
        {
            ++a;
            if (a>n)
            {
                a-=n;
            }
            cout<<a<<" "<<b<<"\n";
            if (i%2)
            {
                for (int j=2;j<m;++j)
                {
                    --b;
                    if (b<1)
                    {
                        b+=m;
                    }
                    cout<<a<<" "<<b<<"\n";
                }
            }
            else
            {
                for (int j=2;j<m;++j)
                {
                    ++b;
                    if (b>m)
                    {
                        b-=m;
                    }
                    cout<<a<<" "<<b<<"\n";
                }
            }
        }
        --b;
        if (b<1)
        {
            b+=m;
        }
        for (int i=0;i<n;++i)
        {
            cout<<a<<" "<<b<<"\n";
            --a;
            if (a<1)
            {
                a+=n;
            }
        }
        return 0;
    }
    if (m%2==0)
    {
        a=x;
        b=y;
        for (int i=1;i<n;++i)
        {
            if (a>n)
            {
                a-=n;
            }
            cout<<a<<" "<<b<<"\n";
            ++a;
        }
        if (a>n)
        {
            a-=n;
        }
        cout<<a<<" "<<b<<"\n";
        for (int i=1;i<m;++i)
        {
            ++b;
            if (b>m)
            {
                b-=m;
            }
            cout<<a<<" "<<b<<"\n";
            if (i%2)
            {
                for (int j=2;j<n;++j)
                {
                    --a;
                    if (a<1)
                    {
                        a+=n;
                    }
                    cout<<a<<" "<<b<<"\n";
                }
            }
            else
            {
                for (int j=2;j<n;++j)
                {
                    ++a;
                    if (a>n)
                    {
                        a-=n;
                    }
                    cout<<a<<" "<<b<<"\n";
                }
            }
        }
        --a;
        if (a<1)
        {
            a+=n;
        }
        for (int i=0;i<m;++i)
        {
            cout<<a<<" "<<b<<"\n";
            --b;
            if (b<1)
            {
                b+=m;
            }
        }
        return 0;
    }
    a=x-1;
    b=y;
    for (int i=0;i<n;++i)
    {
        ++a;
        if (a>n)
        {
            a-=n;
        }
        cout<<a<<" "<<b<<"\n";
    }
    for (int i=1;i<m;++i)
    {
        --b;
        if (b<1)
        {
            b+=m;
        }
        cout<<a<<" "<<b<<"\n";
    }
    for (int i=1;i<n;++i)
    {
        --a;
        if (a<1)
        {
            a+=n;
        }
        cout<<a<<" "<<b<<"\n";
        if (i%2)
        {
            for (int j=2;j<m;++j)
            {
                ++b;
                if (b>m)
                {
                    b-=m;
                }
                cout<<a<<" "<<b<<"\n";
            }
        }
        else
        {
            for (int j=2;j<m;++j)
            {
                --b;
                if (b<1)
                {
                    b+=m;
                }
                cout<<a<<" "<<b<<"\n";
            }
        }
    }
    cout<<x<<" "<<y;
    return 0;
}