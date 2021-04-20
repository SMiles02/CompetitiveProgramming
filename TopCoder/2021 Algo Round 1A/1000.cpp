#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
class EllysRansom {
  public:
    const int X = 2e9;
    double rnd()
    {
        return double(rng()%X)/X;
    }

    string getRansom(string a, string b, string t)
    {
        int score=0,newScore,x,n=sz(a);
        vector<int> f(26,0), g(26,0);
        for (auto i : t)
            ++f[i-'A'];
       	bitset<1000> c;
       	for (int i=0;i<n;++i)
        {
            c[i]=uniform_int_distribution<int>(0,1)(rng);
            if (c[i])
                ++g[b[i]-'A'];
            else
                ++g[a[i]-'A'];
        }
        for (int i=0;i<26;++i)
            score+=max(0,f[i]-g[i]);
        const int iterations = 10000000;
        double tp = 50;
        double mpl = pow((1e-5)/tp,(double)1/iterations);
        for (int _=0;_<1000000&&score>0;++_)
        {
            tp*=mpl;
            x=uniform_int_distribution<int>(0,n-1)(rng);
            newScore=score;
            if (c[x]==0)
            {
                newScore-=max(0,f[a[x]-'A']-g[a[x]-'A']);
                --g[a[x]-'A'];
                newScore+=max(0,f[a[x]-'A']-g[a[x]-'A']);
                newScore-=max(0,f[b[x]-'A']-g[b[x]-'A']);
                ++g[b[x]-'A'];
                newScore+=max(0,f[b[x]-'A']-g[b[x]-'A']);
            }
            else
            {
                newScore-=max(0,f[b[x]-'A']-g[b[x]-'A']);
                --g[b[x]-'A'];
                newScore+=max(0,f[b[x]-'A']-g[b[x]-'A']);
                newScore-=max(0,f[a[x]-'A']-g[a[x]-'A']);
                ++g[a[x]-'A'];
                newScore+=max(0,f[a[x]-'A']-g[a[x]-'A']);
            }
            if (newScore<=score||rnd()<exp((score-newScore)/tp))
            {
                c[x]=1-c[x];
                score=newScore;
            }
            else
            {
                if (c[x])
                {
                    --g[a[x]-'A'];
                    ++g[b[x]-'A'];
                }
                else
                {
                    --g[b[x]-'A'];
                    ++g[a[x]-'A'];
                }
            }
        }
        if (score>0)
    		return "NO SOLUTION";
        string ans = "";
        for (int i=0;i<26;++i)
            g[i]=0;
       	for (int i=0;i<n;++i)
        {
            if (c[i]==0)
            {
                if (g[a[i]-'A']==f[a[i]-'A'])
                	ans+='_';
                else
                {
                    ans+=a[i];
                    ++g[a[i]-'A'];
            	}
            }
            else
            {
                if (g[b[i]-'A']==f[b[i]-'A'])
                	ans+='_';
                else
                {
                    ans+=b[i];
                    ++g[b[i]-'A'];
            	}
            }
        }
        return ans;
    }
};
