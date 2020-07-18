#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long ul;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("circlecross.out");
ifstream cin ("circlecross.in");

string s;
cin>>s;

map<char, pi> mapp;
int counter=0;
for(int i=0; i<52; i++){
	mapp[s[i]].f++;
	if(mapp[s[i]].f==1) mapp[s[i]].s=i;
	else{  //mapp[s[i]].f==2
		for(auto x:mapp){
			if(x.f==s[i]) continue;
			else if(x.s.f==1) {
				if(x.s.s>mapp[s[i]].s)counter++;
			}
		}
	}
}

cout<<counter<<endl;	
return 0;
}
