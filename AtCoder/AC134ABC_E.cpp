#include <bits/stdc++.h>
#define ll long long
using namespace std;


vector<int> newVector(int k,vector<int> v)
{
  int n = v.size();
	for (int j=0;j<n;++j)
  	{
  		if (k>v[j])
  		{
  			v[j]=k;
        sort(v.begin(), v.end(), greater<int>());
  			return v;
  		}
  	}
  	v.push_back(k);
    sort(v.begin(), v.end(), greater<int>());
  	return v;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,k;
  cin>>n;
  vector<int> v;
  for (int i=0;i<n;++i)
  {
  	cin>>k;
  	v=newVector(k,v);
  }
  cout<<v.size();
  return 0;
}