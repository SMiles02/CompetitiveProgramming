#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,l,r,soFar;
  string s;
  cin>>s;
  n=s.length();
  int a[n+1];
  soFar=0;
  for (int i=0;i<n-1;++i)
  {
  	a[i+1]=soFar;
  	if (s[i]==s[i+1])
  	{
  		++soFar;
  	}
  	//cout<<"a["<<i+1<<"] = "<<a[i+1]<<"\n";
  }
  a[n]=soFar;
  cin>>m;
  for (int i=0;i<m;++i)
  {
  	cin>>l>>r;
	cout<<a[r]-a[l]<<"\n";
  }
  return 0;
}