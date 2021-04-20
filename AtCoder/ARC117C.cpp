#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s,t;
    cin>>s;
    while (sz(s)>1)
    {
    	t="";
    	for (int i=1;i<sz(s);++i)
    	{
    		if (s[i-1]==s[i])
    			t+=s[i];
    		else
    			t+=('A'+(('R'-'A')+('B'-'A')+('W'-'A')-(s[i-1]-'A')-(s[i]-'A')));
    	}
    	s=t;
    }
    cout<<s;
    return 0;
}