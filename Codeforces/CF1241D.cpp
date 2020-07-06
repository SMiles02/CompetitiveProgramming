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
    int q,n,k,cur,maxChain,diff,chnLn,curChain;
    vector<int> v;
    vector<int> unique;
    vector<vector<int>> chains;
    map<int,int> m;
    map<int,int> indices;
    cin>>q;
    while (q--)
    {
        cin>>n;
        for (int i=0;i<n;++i)
        {
            cin>>k;
            if (!m[k])
            {
                unique.push_back(k);
            }
            ++m[k];
            v.push_back(k);
        }
        cur=1;
        for (int i=1;i<n;++i)
        {
            if (v[i]==v[i-1])
            {
                ++cur;
            }
            else
            {
                if (cur==m[v[i-1]])
                {
                    chains.push_back({v[i-1],i-m[v[i-1]],i-1});
                    cout<<"At "<<i<<" Chain added: "<<v[i-1]<<" "<<i-m[v[i-1]]<<" "<<i-1<<"\n";
                }
                cur=1;
            }
            cout<<"At "<<i<<", cur = "<<cur<<"\n";
        }
        if (cur==m[v[n-1]])
        {
            chains.push_back({v[n-1],n-m[v[n-1]],n-1});
            cout<<"At "<<n<<" Chain added: "<<v[n-1]<<" "<<n-m[v[n-1]]<<" "<<n-1<<"\n";
        }
        diff=sz(unique);
            sort(unique.begin(), unique.end());
            for (int i=0;i<diff;++i)
            {
                indices[unique[i]]=i;
            }
            chnLn=sz(chains);
            maxChain=max(0,min(chnLn,1));
            curChain=0;
            for (int i=0;i<chnLn-1;++i)
            {
                ++curChain;
                maxChain=max(maxChain,curChain);
                if (chains[i][2]+1==chains[i+1][1])
                {
                    if (indices[chains[i][0]]+1!=indices[chains[i+1][0]])
                    {
                        curChain=0;
                    }
                }
                else
                {
                    curChain=0;
                }
            }
            ++curChain;
            maxChain=max(maxChain,curChain);
            cout<<diff-maxChain<<"\n";
        v.clear();
        m.clear();
        unique.clear();
        chains.clear();
        indices.clear();
    }
    return 0;
}