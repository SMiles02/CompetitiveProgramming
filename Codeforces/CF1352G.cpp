#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
   	if (n<4)
   	{
   		cout<<"-1\n";
   		return;
   	}
   	if (n%2)
   	{
   		for (int i=n;i>0;i-=2)
   			cout<<i<<" ";
   		cout<<"4 2 ";
   		for (int i=6;i<=n;i+=2)
   			cout<<i<<" ";
   	}
   	else
   	{
   		for (int i=n-1;i>0;i-=2)
   			cout<<i<<" ";
   		cout<<"4 2 ";
   		for (int i=6;i<=n;i+=2)
   			cout<<i<<" ";
   	}
   	cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}