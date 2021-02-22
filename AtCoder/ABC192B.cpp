#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0;i<n;++i)
    {
        if (i&1)
        {
            if ('a'<=s[i]&&s[i]<='z')
            {
                cout<<"No";
                return 0;
            }
        }
        else
        {
            if ('A'<=s[i]&&s[i]<='Z')
            {
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes";
    return 0;
}