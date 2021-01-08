#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    map<string,bool> m1,m2;
    string s;
    while (n--)
    {
        cin>>s;
        if (s[0]=='!')
        {
            if (m1[s])
            {
                for (int i=1;i<sz(s);++i)
                    cout<<s[i];
                return 0;
            }
            m2[s]=1;
        }
        else
        {
            if (m2["!"+s])
            {
                cout<<s;
                return 0;
            }
            m1["!"+s]=1;
        }
    }
    cout<<"satisfiable";
    return 0;
}