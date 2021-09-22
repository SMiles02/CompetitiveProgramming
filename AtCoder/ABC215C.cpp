//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

set<string> st;
string s;
int n,k;
bitset<10> b;

void rec(int t, string c)
{
    //cout<<t<<" "<<c<<"\n";
    if (t==n)
    {
        //cout<<c<<"\n";
        st.insert(c);
        return;
    }
    for (int i=0;i<n;++i)
        if (!b[i])
        {
            c+=s[i];
            b[i]=1;
            rec(t+1,c);
            c.pop_back();
            b[i]=0;
        }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s>>k;
    n=sz(s);
    rec(0,"");
    for (int i=1;i<k;++i)
        st.erase(st.begin());
    cout<<*st.begin();
    return 0;
}