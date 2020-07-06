#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y;
    cin>>n>>q;
    vector<int> rows;
    vector<int> columns;
    vector<int> rightDiagonal;
    vector<int> leftDiagonal;
    map<int,vector<pair<int,int>>> r;
    map<int,vector<pair<int,int>>> c;
    map<int,vector<pair<int,int>>> rD;
    map<int,vector<pair<int,int>>> lD;
    for (int i=0;i<q;++i)
    {
        cin>>x>>y;
        r[x].push_back({y,i+1});
        if (sz(r[x])==2)
        {
            rows.push_back(x);
        }
        c[y].push_back({x,i+1});
        if (sz(c[y])==2)
        {
            columns.push_back(y);
        }
        rD[y-x].push_back({x,i+1});
        if (sz(rD[y-x])==2)
        {
            rightDiagonal.push_back(y-x);
        }
        lD[x+y].push_back({x,i+1});
        if (sz(lD[x+y])==2)
        {
            leftDiagonal.push_back(x+y);
        }
    }
    vector<pair<int,int>> answers;
    n=sz(rows);
    for (int i=0;i<n;++i)
    {
        q=sz(r[rows[i]]);
        sort(r[rows[i]].begin(), r[rows[i]].end());
        for (int j=0;j<q-1;++j)
        {
            answers.push_back({min(r[rows[i]][j].second,r[rows[i]][j+1].second),max(r[rows[i]][j].second,r[rows[i]][j+1].second)});
        }
    }
    n=sz(columns);
    for (int i=0;i<n;++i)
    {
        q=sz(c[columns[i]]);
        sort(c[columns[i]].begin(), c[columns[i]].end());
        for (int j=0;j<q-1;++j)
        {
            answers.push_back({min(c[columns[i]][j].second,c[columns[i]][j+1].second),max(c[columns[i]][j].second,c[columns[i]][j+1].second)});
        }
    }
    n=sz(rightDiagonal);
    for (int i=0;i<n;++i)
    {
        q=sz(rD[rightDiagonal[i]]);
        sort(rD[rightDiagonal[i]].begin(), rD[rightDiagonal[i]].end());
        for (int j=0;j<q-1;++j)
        {
            answers.push_back({min(rD[rightDiagonal[i]][j].second,rD[rightDiagonal[i]][j+1].second),max(rD[rightDiagonal[i]][j].second,rD[rightDiagonal[i]][j+1].second)});
        }
    }
    n=sz(leftDiagonal);
    for (int i=0;i<n;++i)
    {
        q=sz(lD[leftDiagonal[i]]);
        sort(lD[leftDiagonal[i]].begin(), lD[leftDiagonal[i]].end());
        for (int j=0;j<q-1;++j)
        {
            answers.push_back({min(lD[leftDiagonal[i]][j].second,lD[leftDiagonal[i]][j+1].second),max(lD[leftDiagonal[i]][j].second,lD[leftDiagonal[i]][j+1].second)});
        }
    }
    sort(answers.begin(), answers.end());
    n=sz(answers);
    cout<<n<<"\n";
    for (int i=0;i<n;++i)
    {
        cout<<min(answers[i].first,answers[i].second)<<" "<<max(answers[i].first,answers[i].second)<<"\n";
    }
    return 0;
}