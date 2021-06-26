#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int s,v1,v2,t1,t2,first,second;
  cin>>s>>v1>>v2>>t1>>t2;
  first=s*v1+2*t1;
  second=s*v2+2*t2;
  if (first<second)
  {
  	cout<<"First";
  }
  else if (second<first)
  {
  	cout<<"Second";
  }
  else
  {
  	cout<<"Friendship";
  }
  return 0;
}