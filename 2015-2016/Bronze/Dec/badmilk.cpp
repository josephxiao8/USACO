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

ofstream cout ("badmilk.out");
ifstream cin ("badmilk.in");

int n,m,d,s;
cin>>n>>m>>d>>s;
vector<vector<vi>> drink(n+1,vector<vi>(101)); //contains the milk m that person n drank from time 1-100
for(int i=0; i<d; i++){
	int p,m,t;
	cin>>p>>m>>t;
	drink[p][t].pb(m);
}

set<int> pot; //maintains a list of potential bad milks
set<int> sick; //maintains a list of sick people
vi time(n+1); //maintains a list of sick people and the time they got sick
for(int i=0; i<s; i++){
	int p,t;
	cin>>p>>t;
	sick.insert(p);
	time[p]=t;
	for(int j=1; j<t; j++)
	for(auto x:drink[p][j])
	pot.insert(x);
}

for(int j=1; j<=n; j++){
	set<int> never_drank;
	for(auto x:pot) never_drank.insert(x);
		if(sick.count(j)){
			for(int i=1; i<=100; i++){
				if(i<time[j]){
					for(auto x:drink[j][i]){
						if(pot.count(x)) never_drank.erase(x);		
					}
				}
				else{
					for(auto x:drink[j][i]){
						if(pot.count(x)) {
							pot.erase(x);
						}
					}
				}
		  }
		  for(auto x:never_drank) {
			if(pot.count(x))pot.erase(x);
		  }
		}
}

set<int> ans;
for(int j=1; j<=n; j++){
	for(int i=1; i<=100; i++){
		for(auto x:drink[j][i]) if(pot.count(x)) ans.insert(j);
	}
}


cout<<ans.size()<<endl;


return 0;
}
