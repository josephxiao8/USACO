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
 
typedef priority_queue<pair<int,string>> pq;
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

ofstream cout ("lineup.out");
ifstream cin ("lineup.in");

int n;
cin>>n;

vector<string> cows={"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

vector<pair<string,string> > v(n);
for(int j=0; j<n; j++){
	string s;
	for(int i=0; i<6; i++){
		cin>>s;
		if(i==0) v[j].f=s;
		if(i==5) v[j].s=s;
	}
}

do{
	bool good=true;
	for(auto x:v){
		for(int i=0; i<8; i++){
			if(cows[i]==x.f){
				if((i>0 && cows[i-1]==x.s) || (i<7 && cows[i+1]==x.s)) continue;
				else{
					good=false;
					break;
				}
			}
		}
		if(!good) break;
	}
	
	if(good){
		for(auto x:cows) cout<<x<<endl;
		return 0;
	}
	
}while(next_permutation(cows.begin(),cows.end()));

return 0;
}
