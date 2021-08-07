#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
        if (s[i]=='1')
        {
            if (i&1)
                cout<<"Aoki";
            else
                cout<<"Takahashi";
            return 0;
        }
    return 0;
}