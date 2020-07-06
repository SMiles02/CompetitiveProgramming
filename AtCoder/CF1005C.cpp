#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans=0;
vector<int> powers;
map<int,int> m;
vector<int> uni;

void genPow()
{
    int abc=1;
    for (int i=1;i<31;++i)
    {
        abc*=2;
        powers.push_back(abc);
    }
    return;
}

void check(int indice)
{
    for (int j=0;j<30;++j)
    {
        if (m[powers[j]-uni[indice]])
        {
            if (powers[j]-uni[indice]==uni[indice])
            {
                if (m[powers[j]-uni[indice]]>1)
                {
                    return;
                }
            }
            else
            {
                return;
            }
        }
    }
    ans+=m[uni[indice]];
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    genPow();
    int n,k;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (!m[k])
        {
            uni.push_back(k);
        }
        ++m[k];
    }
    k=sz(uni);
    for (int i=0;i<k;++i)
    {
        check(i);
    }
    cout<<ans;
    return 0;
}