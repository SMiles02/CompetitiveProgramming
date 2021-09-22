#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,ans=0;
    bool last = 0;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;
    set<int> st;
    for (int i=0;i<n;++i)
    {
        st.insert(s[i]-'0');
        st.insert(t[i]-'0');
        if (st.size()==2)
        {
            ans+=2;
            st.clear();
            last=0;
        }
        else if (st.count(0))
        {
            ++ans;
            st.clear();
            last=1;
        }
        else if (last&&st.count(1))
        {
            ++ans;
            st.clear();
            last=0;
        }
    }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}