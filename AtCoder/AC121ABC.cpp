#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,c,ans,k,current;
  cin>>n>>m>>c;
  int b[m];
  ans=0;
  for (int i = 0; i < m; i++)
  {
  	cin>>b[i];
  }
  for (int i = 0; i < n; i++)
  {
  	current = c;
  	for (int j = 0; j < m; j++)
  	{
  		cin>>k;
  		current += k * b[j];
  	}
  	if (current > 0)
  	{
  		ans++;
  	}
  }
  cout<<ans;
  return 0;
}