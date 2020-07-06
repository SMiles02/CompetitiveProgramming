#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,x,equal,mini,cur;
    cin>>n>>m;
    map<int,int> occurencesA;
    map<int,int> occurencesB;
    vector<int> a;
    vector<int> b;
    map<int,vector<int>> frequencyA;
    map<int,vector<int>> frequencyB;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (!occurencesA[k])
        {
            a.push_back(k);
        }
        ++occurencesA[k];
    }
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (!occurencesB[k])
        {
            b.push_back(k);
        }
        ++occurencesB[k];
    }
    x=sz(a);
    for (int i=0;i<x;++i)
    {
        frequencyA[occurencesA[a[i]]].push_back(a[i]);
    }
    for (int i=0;i<x;++i)
    {
        frequencyB[occurencesB[b[i]]].push_back(b[i]);
    }
    for (int i=1;i<2001;++i)
    {
        if (sz(frequencyA[i]))
        {
            mini=m;
            sort(frequencyA[i].begin(), frequencyA[i].end());
            sort(frequencyB[i].begin(), frequencyB[i].end());
            vector<int> v;
            vector<int> w;
            x=sz(frequencyA[i]);
            for (int j=0;j<x-1;++j)
            {
                v.push_back(frequencyA[i][j+1]-frequencyA[i][j]);
            }
            v.push_back(frequencyA[i][0]-frequencyA[i][x-1]+m);
            for (int j=0;j<x-1;++j)
            {
                w.push_back(frequencyB[i][j+1]-frequencyB[i][j]);
            }
            w.push_back(frequencyB[i][0]-frequencyB[i][x-1]+m);
            for (int j=0;j<x;++j)
            {
                equal=1;
                for (int index=0;index<x;++index)
                {
                    if (v[index]!=w[(index+j)%x])
                    {
                        equal=0;
                        break;
                    }
                }
                if (equal)
                {
                    cur=(frequencyB[i][j]-frequencyA[i][0]);
                    if (cur<0)
                    {
                        cur+=m;
                    }
                    mini=min(mini,cur);
                    //cout<<"cur = "<<cur<<", mini = "<<mini<<", j = "<<j<<"\n";
                }
            }
            cout<<mini;
            return 0;
        }
    }
    return 0;
}