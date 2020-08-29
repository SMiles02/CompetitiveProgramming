#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int MAXN=500, INF=1e9;
int r[MAXN],curRank[MAXN],peakRating[MAXN],peakRanking[MAXN],monthRating[MAXN],monthRanking[MAXN];

void update(int i, int rating, int ranking, int month)
{
    if (rating>peakRating[i])
    {
        peakRating[i]=rating;
        monthRating[i]=month;
    }
    if (ranking<peakRanking[i])
    {
        peakRanking[i]=ranking;
        monthRanking[i]=month;
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;++i)
    {
        cin>>r[i];
        peakRanking[i]=INF;
        peakRating[i]=-INF;
    }
    int k;
    vector<pii> v[m];
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
        {
            cin>>k;
            r[i]+=k;
            v[j].push_back({r[i],i});
        }
    }
    for (int i=0;i<m;++i)
    {
        sort(v[i].rbegin(), v[i].rend());
        curRank[0]=0;
        update(v[i][0].s,v[i][0].f,curRank[0],i);
        //cout<<v[i][0].f<<" ";
        for (int j=1;j<n;++j)
        {
            //cout<<v[i][j].f<<" ";
            if (v[i][j].f==v[i][j-1].f)
                curRank[j]=curRank[j-1];
            else
                curRank[j]=j;
            update(v[i][j].s,v[i][j].f,curRank[j],i);
        }
        //cout<<"\n";
    }
    int ans=0;
    for (int i=0;i<n;++i)
    {
        //cout<<peakRanking[i]<<" "<<peakRating[i]<<"\n";
        //cout<<monthRanking[i]<<" "<<monthRating[i]<<"\n\n";
        if (monthRanking[i]!=monthRating[i])
            ++ans;
    }
    cout<<ans<<"\n";
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