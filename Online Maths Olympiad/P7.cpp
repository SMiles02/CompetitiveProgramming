#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans=0,total=0;
map<pair<int,int>,int> collisions;
map<int,string> directions;

void printer(int a,int b,int c,int d,int n,int k)
{
    for (int i=0;i<5;++i)
    {
        cout<<"|";
        for (int j=0;j<5;++j)
        {
            if (i==a&&j==b)
            {
                cout<<1<<directions[n];
            }
            else if (i==c&&j==d)
            {
                cout<<2<<directions[k];
            }
            else
            {
                cout<<"   ";
            }
            cout<<"|";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void works(int o, int p, int q, int r, int s, int t)
{
    int a=o,b=p,c=q,d=r,n=s,k=t;
    ++total;
    map<pair<int,int>,int> m;
    if (n==0)
    {
        for (int i=0;i<5;++i)
        {
            m[{a,b}]=1;
            ++a;
        }
    }
    if (n==1)
    {
        for (int i=0;i<5;++i)
        {
            m[{a,b}]=1;
            --a;
        }
    }
    if (n==2)
    {
        for (int i=0;i<5;++i)
        {
            m[{a,b}]=1;
            ++b;
        }
    }
    if (n==3)
    {
        for (int i=0;i<5;++i)
        {
            m[{a,b}]=1;
            --b;
        }
    }
    if (k==0)
    {
        for (int i=0;i<5;++i)
        {
            if (m[{c,d}])
            {
                ++ans;
                ++collisions[{c,d}];
                printer(o,p,q,r,s,t);
                return;
            }
            ++c;
        }
    }
    if (k==1)
    {
        for (int i=0;i<5;++i)
        {
            if (m[{c,d}])
            {
                ++ans;
                ++collisions[{c,d}];
                printer(o,p,q,r,s,t);
                return;
            }
            --c;
        }
    }
    if (k==2)
    {
        for (int i=0;i<5;++i)
        {
            if (m[{c,d}])
            {
                ++ans;
                ++collisions[{c,d}];
                printer(o,p,q,r,s,t);
                return;
            }
            ++d;
        }
    }
    if (k==3)
    {
        for (int i=0;i<5;++i)
        {
            if (m[{c,d}])
            {
                ++ans;
                ++collisions[{c,d}];
                printer(o,p,q,r,s,t);
                return;
            }
            --d;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    directions[0]="Dn";
    directions[1]="Up";
    directions[2]="Rt";
    directions[3]="Lt";
    for (int a=0;a<5;++a)
    {
        for (int b=0;b<5;++b)
        {
            for (int c=0;c<5;++c)
            {
                for (int d=0;d<5;++d)
                {
                    for (int n=0;n<4;++n)
                    {
                        for (int m=0;m<4;++m)
                        {
                            if (!((a==c)&&(b==d)))
                                works(a,b,c,d,n,m);
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<" "<<total;
    for (int i=0;i<5;++i)
    {
        cout<<"\n";
        for (int j=0;j<5;++j)
        {
            cout<<collisions[{i,j}]<<" ";
        }
    }
    return 0;
}