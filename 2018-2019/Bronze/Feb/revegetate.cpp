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

ofstream cout ("revegetate.out");
ifstream cin ("revegetate.in");

int n,m;
cin>>n>>m;

vpi pairs;
for(int i=0; i<m; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	pairs.pb(mp(a,b));
}

vi seed(n,-1);
for(int j=0; j<n; j++){
	for(int i=1; i<=4; i++){
		bool good=true;
		for(auto x:pairs){
			int a,b;
			tie(a,b)=x;
			if(a==j){
				if(seed[b]==i){
					good=false;
					break;
				}
			}
			else if(b==j){
				if(seed[a]==i){
					good=false;
					break;
				}
			}
		}
		
		if(good) {
			seed[j]=i;
			break;
		}
	}
}

for(auto x:seed) cout<<x;
cout<<endl;
return 0;
}
