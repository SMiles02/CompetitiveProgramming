#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
  string s;
  map<string,int> words;
  map<string,int>::iterator it;
  for (int i=0;i<n;i++)
  {
  	cin>>s;
  	it = words.find(s);
  	if (it == words.end())
  	{
  		cout<<"OK\n";
  		words[s]=1;
  	}
  	else
  	{
  		cout<<s<<words[s]<<"\n";
  		++words[s];
  	}
  }
  return 0;
}