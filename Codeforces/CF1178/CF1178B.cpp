#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n,wCount,k,before;
  string s;
  cin>>s;
  n=s.length();
  wCount=0;
  map<ll,ll> oScores;
  vector<ll> oLocations;
  for (ll i=0;i<n-1;++i)
  {
  	if (s[i]=='o')
  	{
  		oLocations.push_back(i);
  		oScores[i]=wCount;
  	}
  	else if (s[i+1]=='v')
  	{
  		++wCount;
  	}
  }
  ll ans=0;
  k=oLocations.size();
  //cout<<"k: "<<k<<"\n";
  for (int i=0;i<k;++i)
  {
  	before=oScores[oLocations[i]];
  	ans+=(before*(wCount-before));
  }
  cout<<ans;
  return 0;
}