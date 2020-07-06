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
    int n,m,s,f,k,l,r,direction;
    cin>>n>>m>>s>>f;
    if (s>f)
    {
        direction=-1;
    }
    else
    {
        direction=1;
    }
    map<int,vector<int>> a;
    while (m--)
    {
        cin>>k>>l>>r;
        a[k].push_back(l);
        a[k].push_back(r);
    }
    for (int i=1;s!=f;++i)
    {
        if (sz(a[i]))
        {
            if ((s>=a[i][0]&&a[i][1]>=s)||(s+direction>=a[i][0]&&a[i][1]>=s+direction))
            {
                cout<<"X";
            }
            else
            {
                if (s>f)
                {
                    cout<<"L";
                    --s;
                }
                else
                {
                    cout<<"R";
                    ++s;
                }
            }
        }
        else
        {
            if (s>f)
            {
                cout<<"L";
                --s;
            }
            else
            {
                cout<<"R";
                ++s;
            }
        }
    }
    return 0;
}