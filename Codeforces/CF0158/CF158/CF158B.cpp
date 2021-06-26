#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,k,ans;
  cin>>n;
  int a[5] = {0};
  for (int i=1;i<=n;i++)
  {
  	cin>>k;
  	++a[k];
  }
  //cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<", and ans 0\n";
  k=min(a[1],a[3]);
  ans=a[4];
  a[4]=0;
  //cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<", and ans "<<ans<<"\n";
  ans+=k;
  a[1]-=k;
  a[3]-=k;
  //cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<", and ans "<<ans<<"\n";
  if (a[2]%2==1)
  {
  	ans+=(a[2]-1)/2;
  	a[2]=1;
  }
  else
  {
  	ans+=a[2]/2;
  	a[2]=0;
  }
  //cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<", and ans "<<ans<<"\n";
  k=min(a[2],a[1]/2);
  ans+=k;
  a[2]-=k;
  a[1]-=(2*k);
  //cout<<a[1]<<"\n";
  ans+=floor(a[1]/4);
  a[1]%=4;
  //cout<<a[1]<<"\n";
  a[1]=max(0,a[1]-(a[2]*2));
  //cout<<a[1]<<"\n";
  ans+=a[2];
  if (a[1]%4==0)
  {
  	ans+=a[1]/4;
  }
  else
  {
  	ans+=(a[1]/4)+1;
  }
  cout<<ans+a[3];
  return 0;
}