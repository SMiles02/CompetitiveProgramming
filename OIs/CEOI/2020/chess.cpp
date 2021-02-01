#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int r,c,mod=1e9+7;

bool isok(pair<int,int> p)
{
    if (1<=p.first&&p.first<=r)
        if (1<=p.second&&p.second<=c)
            return 1;
    return 0;
}

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int ans[101][101][101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,c1,cR,x,a,b;
    cin>>r>>c>>q;
    char s;
    if (r<101&&c<101)
    {
        for (int i=1;i<=c;++i)
            ans[1][i][i]=1;
        for (int i=2;i<=r;++i)
        {
            for (int j=1;j<=c;++j)
                ans[i][1][j]=add(ans[i-1][1][j],ans[i-1][2][j]);
            for (int j=1;j<=c;++j)
                ans[i][c][j]=add(ans[i-1][c][j],ans[i-1][c-1][j]);
            for (int j=2;j<c;++j)
                for (int k=1;k<=c;++k)
                    ans[i][j][k]=add(ans[i-1][j-1][k],add(ans[i-1][j][k],ans[i-1][j+1][k]));
        }
    }
    while (q--)
    {
        cin>>s>>c1>>cR;
        if (s=='P')
        {
            if (c1==cR)
                cout<<r-1<<" 1\n";
            else
                cout<<"0 0\n";
        }
        else if (s=='R')
        {
            if (c1==cR)
                cout<<"1 1\n";
            else
                cout<<"2 2\n";
        }
        else if (s=='Q')
        {
            if (c1==cR||c1-1==cR-r||c1+1==cR+r)
                cout<<"1 1\n";
            else
            {
                x=2;
                if (isok({1,(cR+r)-1}))
                {
                    ++x;
                    //cout<<"t1\n";
                }
                if (isok({1,1+(cR-r)}))
                {
                    ++x;
                    //cout<<"t2\n";
                }
                if (isok({r,c1+1-r}))
                {
                    ++x;
                    //cout<<"t3\n";
                }
                if (isok({r,r+c1-1}))
                {
                    ++x;
                    //cout<<"t4\n";
                }
                if (isok({r+cR-c1,c1}))
                {
                    ++x;
                    //cout<<"t5\n";
                }
                if (isok({r-cR+c1,c1}))
                {
                    ++x;
                    //cout<<"t6\n";
                }
                if (isok({c1+1-cR,cR}))
                {
                    ++x;
                    //cout<<"t7\n";
                }
                if (isok({1-c1+cR,cR}))
                {
                    ++x;
                    //cout<<"t8\n";
                }
                if ((r+cR+1-c1)%2==0)
                {
                    a=(r+cR+1-c1)/2;
                    b=r+cR-a;
                    if (isok({a,b}))
                        ++x;
                }
                if ((c1+1+r-cR)%2==0)
                {
                    a=(c1+1+r-cR)/2;
                    b=1+c1-a;
                    if (isok({a,b}))
                        ++x;
                }
                cout<<"2 "<<x<<"\n";
            }
        }
        else if (s=='K')
        {
            cout<<max(r-1,abs(cR-c1))<<" "<<ans[r][cR][c1]<<"\n";
        }
        else
        {
            cout<<"¯|_(ツ)_|¯\n";
            return 0;
        }
    }
    return 0;
}