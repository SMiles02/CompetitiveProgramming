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
    int t,a,b,c,wins,g;
    double n;
    string s;
    cin>>t;
    map<int,int> done;
    while (t--)
    {
        wins=0;
        cin>>n;
        g=n;
        char dd[g];
        cin>>a>>b>>c;
        cin>>s;
        for (int i=0;i<n;++i)
        {
            if (s[i]=='R')
            {
                if (b>0)
                {
                    --b;
                    done[i]=1;
                    ++wins;
                    dd[i]='P';
                }
            }
            if (s[i]=='P')
            {
                if (c>0)
                {
                    --c;
                    done[i]=1;
                    ++wins;
                    dd[i]='S';
                }
            }
            if (s[i]=='S')
            {
                if (a>0)
                {
                    --a;
                    done[i]=1;
                    ++wins;
                    dd[i]='R';
                }
            }

        }
        if (wins>=n/2)
        {
            cout<<"YES\n";
            for (int i=0;i<n;++i)
            {
                if (!done[i])
                {
                    if (a>0)
                    {
                        cout<<"R";
                        --a;
                    }
                    else if (b>0)
                    {
                        cout<<"P";
                        --b;
                    }
                    else
                    {
                        cout<<"S";
                        --c;
                    }
                }
                else
                {
                    cout<<dd[i];
                }
            }
        }
        else
        {
            cout<<"NO";
        }
        cout<<"\n";
        done.clear();
    }
    return 0;
}