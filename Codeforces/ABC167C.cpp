#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans=1000000000,n,m,x;
int a[12][12];
int c[12];
int curBooksBought[12];
int skills[12];

void test()
{
    for (int i=0;i<m;++i)
        skills[i]=0;
    int cur=0;
    for (int i=0;i<n;++i)
        if (curBooksBought[i])
        {
            cur+=c[i];
            for (int j=0;j<m;++j)
                skills[j]+=a[i][j];
        }
    for (int i=0;i<m;++i)
        if (x>skills[i])
            return;
    ans=min(ans,cur);
}

void permutations(int cur)
{
    if (cur==n)
    {
        test();
        return;
    }
    curBooksBought[cur]=0;
    permutations(cur+1);
    curBooksBought[cur]=1;
    permutations(cur+1);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>x;
    for (int i=0;i<n;++i)
    {
        cin>>c[i];
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    }
    permutations(0);
    if (ans==1000000000)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}