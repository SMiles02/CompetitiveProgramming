#include <bits/stdc++.h>
#define ll long long
using namespace std;

int alphaNum(char s)
{
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  for (int j=0;j<26;++j)
  {
  	if (s == alpha[j])
  	{
  		return j;
  	}
  }
  return -1;
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int cur,next,ans,n;
  string s;
  cin>>s;
  n=s.length();
  cur=0;
  ans=0;
  for (int i=0;i<n;++i)
  {
  	next=alphaNum(s[i]);
  	ans+=min({abs(next-cur),next+26-cur,cur+26-next});
  	//cout<<min({abs(next-cur),next+26-cur,cur+26-next})<<"\n";
  	//cout<<cur<<"\n";
  	//cout<<next<<"\n";
  	cur=next;
  }
  cout<<ans;
  return 0;
}