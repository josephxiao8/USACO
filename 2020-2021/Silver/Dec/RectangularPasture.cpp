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
	
	int n;
	cin>>n;
	vpi v(n);
	for(int i=0; i<n; i++) cin>>v[i].f>>v[i].s;
	sort(v.begin(), v.end());
	
	vector<vpi> prefix(n, vpi(n)); //above, below
	vector<vpi> suffix(n, vpi(n)); //above, below
	
	for(int i=0; i<n; i++){
		int a=0, b=0;
		for(int j=0; j<n; j++){
			if(v[j].s>v[i].s) a++;
			else b++;
			prefix[i][j]=mp(a,b);
		}
	}
	
	for(int i=0; i<n; i++){
		int a=0, b=0;
		for(int j=n-1; j>=0; j--){
			if(v[j].s>v[i].s) a++;
			else b++;
			suffix[i][j]=mp(a,b);
		}
	}
	
	
	ll ans=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int below=1, above=1;
			if(v[i].s>v[j].s){
				above+=prefix[i][j].f-prefix[i][i].f;
				below+=suffix[j][i].s-suffix[j][j].s;
			}
			else{
				below+=prefix[i][j].s-prefix[i][i].s;
				above+=suffix[j][i].f-suffix[j][j].f;
			}
			ans+=below*above;
		}
	}
	
	cout<<ans+n+1<<"\n";
	return 0;
}

