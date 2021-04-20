#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<char,int> m1;
map<int,char> m2;
const int mod = 1e9+7;
ll dp[2][18];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i='1';i<='9';++i)
    {
        m1[i]=(i-'0');
        m2[(i-'0')]=i;
    }
    m1['A']=10;
    m1['B']=11;
    m1['C']=12;
    m1['D']=13;
    m1['E']=14;
    m1['F']=15;
    m2[10]='A';
    m2[11]='B';
    m2[12]='C';
    m2[13]='D';
    m2[14]='E';
    m2[15]='F';
    string s;
    set<char> st;
    int k;
    cin>>s;
    cin>>k;
    int c=0;
    for (auto i : s)
        if (i=='0')
            ++c;
    if (c==sz(s))
    {
        if (k==sz(s))
            cout<<1;
        else
            cout<<0;
        return 0;
    }
    for (auto i : s)
    {
        for (int j=0;j<m1[i];++j)
            if (!(j==0&&((sz(st)==0)||((sz(st)==1&&s[0]=='0')))))
            {
                if (st.count(m2[j]))
                    ++dp[1][sz(st)];
                else
                    ++dp[1][sz(st)+1];
            }
        dp[1][0]=1;
        dp[1][1]=15;
        for (int j=1;j<=16;++j)
        {
            dp[1][j]+=(dp[0][j]*j);
            dp[1][j]%=mod;
            dp[1][j+1]+=dp[0][j]*(16-j);
            dp[1][j+1]%=mod;
        }
        for (int j=0;j<=16;++j)
        {
            dp[0][j]=dp[1][j];
            dp[1][j]=0;
            cout<<dp[0][j]<<" ";
        }
        st.insert(i);
        cout<<"\n";
    }
    ++dp[0][sz(st)];
    cout<<dp[0][k];
    return 0;
}