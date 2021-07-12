#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string combine(char a, char b, char c)
{
    string s = "";
    s += a;
    s += b;
    s += c;
    return s;
}

const int N = 5e5;
int dp[N], from[N], e[N];
bitset<N> done;
vector<int> to[N];
map<string,int> mp;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x;
    cin>>n;
    m=n;
    string s,t;
    for (int i=1;i<=n;++i)
    {
        cin>>s;
        t=combine(s[0],s[1],s[2]);
        if (!mp[t])
        {
            mp[t]=++m;
            //cout<<"! "<<t<<" "<<m<<"\n";
        }
        to[i].push_back(mp[t]);
        ++from[mp[t]];
        ++e[mp[t]];
        t=combine(s[sz(s)-3],s[sz(s)-2],s[sz(s)-1]);
        if (!mp[t])
        {
            mp[t]=++m;
            //cout<<"! "<<t<<" "<<m<<"\n";
        }
        to[mp[t]].push_back(i);
        ++from[i];
        ++e[i];
    }
    stack<int> st;
    for (int i=1;i<=m;++i)
        if (from[i]==0)
        {
            st.push(i);
            done[i]=1;
        }
    while (!st.empty())
    {
        x=st.top();
        st.pop();
        if (x>n)
        {
            if (e[x]==0)
                dp[x]=1;
            for (int i : to[x])
            {
                if (dp[x]==-1)
                    dp[i]=1;
                else if (dp[i]==0)
                    dp[i]=-1;
                if ((--from[i]==0||dp[i]==1)&&!done[i])
                {
                    done[i]=1;
                    st.push(i);  
                }
            }
        }
        else
        {
            for (int i : to[x])
            {
                if (dp[x]==-1)
                    dp[i]=-1;
                else if (dp[i]==0)
                    dp[i]=1;
                if ((--from[i]==0||dp[i]==-1)&&!done[i])
                {
                    done[i]=1;
                    st.push(i);  
                }
            }
        }
        //cout<<x<<": "<<dp[x]<<"\n";
    }
    for (int i=1;i<=n;++i)
    {
        if (dp[i]==-1)
            cout<<"Takahashi\n";
        else if (dp[i]==1)
            cout<<"Aoki\n";
        else
            cout<<"Draw\n";
    }
    return 0;
}