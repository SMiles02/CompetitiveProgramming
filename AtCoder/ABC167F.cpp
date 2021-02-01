#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,score,lowest,tot=0;
    cin>>n;
    vector<pair<int,int>> pos;
    vector<pair<int,int>> neg;
    string s;
    for (int i=0;i<n;++i)
    {
        cin>>s;
        score=0;lowest=0;
        for (auto i : s)
        {
            if (i=='(')
                ++score;
            else
            {
                --score;
                lowest=min(lowest,score);
            }
        }
        //cout<<lowest<<" "<<score<<"\n";
        if (lowest==0)
            tot+=score;
        else if (score>=0)
            pos.push_back({lowest,score});
        else
            neg.push_back({lowest,score});
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());
    score=tot;
    for (auto i : pos)
    {
        if (score+i.first<0)
        {
            cout<<"No";
            return 0;
        }
        score+=i.second;
    }
    for (auto i : neg)
    {
        if (score+i.first<0)
        {
            cout<<"No";
            return 0;
        }
        score+=i.second;
    }
    if (score!=0)
    {
        cout<<"No";
        return 0;
    }
    cout<<"Yes";
    return 0;
}