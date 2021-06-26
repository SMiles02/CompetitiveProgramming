#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans[500][500];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,cur=1;
    cin>>n;
    if (n==1||n==2)
    {
        cout<<-1;
        return 0;
    }
    if (n%2)
    {
        for (int i=3;i<n;++i)
        {
            if (i%2)
            {
                for (int j=0;j<=i;++j)
                {
                    ans[i][j]=cur;
                    ++cur;
                }
                for (int j=i-1;j+1;--j)
                {
                    ans[j][i]=cur;
                    ++cur;
                }
            }
            else
            {
                for (int j=0;j<=i;++j)
                {
                    ans[j][i]=cur;
                    ++cur;
                }
                for (int j=i-1;j+1;--j)
                {
                    ans[i][j]=cur;
                    ++cur;
                }
            }
        }
    }
    else
    {
        for (int i=3;i<n;++i)
        {
            if (i%2==0)
            {
                for (int j=0;j<=i;++j)
                {
                    ans[i][j]=cur;
                    ++cur;
                }
                for (int j=i-1;j+1;--j)
                {
                    ans[j][i]=cur;
                    ++cur;
                }
            }
            else
            {
                for (int j=0;j<=i;++j)
                {
                    ans[j][i]=cur;
                    ++cur;
                }
                for (int j=i-1;j+1;--j)
                {
                    ans[i][j]=cur;
                    ++cur;
                }
            }
        }
    }
    --cur;
    ans[0][0]=cur+7;
    ans[0][1]=cur+8;
    ans[0][2]=cur+3;
    ans[1][0]=cur+1;
    ans[1][1]=cur+6;
    ans[1][2]=cur+2;
    ans[2][0]=cur+9;
    ans[2][1]=cur+5;
    ans[2][2]=cur+4;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}