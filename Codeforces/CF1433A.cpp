#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    string s;
    while (n--)
    {
        cin>>s;
        cout<<(s[0]-'0'-1)*10+(s.size()*(s.size()+1))/2<<"\n";
    }
    return 0;
}