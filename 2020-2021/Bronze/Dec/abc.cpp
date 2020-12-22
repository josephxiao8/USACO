#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std; 
 
typedef long long ll;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	vl v(7);
	for(int i=0; i<7; i++) cin>>v[i];
	sort(v.begin(), v.end());
	
	while(next_permutation(v.begin(), v.end())){
		if(v[0]+v[1]==v[3] && v[1]+v[2]==v[4] && v[0]+v[2]==v[5] && v[0]+v[1]+v[2]==v[6]){
			vl ans;
			for(int i=0; i<3; i++) ans.pb(v[i]);
			sort(ans.begin(), ans.end());
			for(int i=0; i<3; i++){
				cout<<ans[i];
				if(i!=2) cout<<" ";
			}
			cout<<"\n";
			return 0;
		}
	}
	
	return 0;
}
