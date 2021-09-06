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


vi bit;
int n;

int sum(int k){
	int ret=0;
	while(k>=1){
		ret+=bit[k];
		k-=k&-k;
	}
	return ret;
}

void add(int k, int x){
	while(k<=n){
		bit[k]+=x;
		k+=k&-k;
	}
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	cin>>n;
	
	vi b(n);
	for(int i=0; i<n; i++) cin>>b[i];
	
	vi prev(n+1,-1);
	vi right(n,n-1);
	for(int i=0; i<n; i++){
		if(prev[b[i]]!=-1) right[prev[b[i]]]=i-1;
		prev[b[i]]=i;
	}
	
	prev=vi(n+1,-1);
	vi left(n, 0);
	for(int i=n-1; i>=0; i--){
		if(prev[b[i]]!=-1) left[prev[b[i]]]=i+1;
		prev[b[i]]=i;
	}
	
	vpi updates;
	for(int i=0; i<n; i++){
		updates.pb(mp(left[i],i));
	}
	sort(updates.begin(), updates.end());
	
	bit=vi(n+1,0);
	int idx=0;
	ll ans=0;
	for(int i=0; i<n; i++){
		while(idx<n && updates[idx].f<=i){
			add(updates[idx].s+1,1);
			idx++;
		}
		ans+=sum(right[i]+1)-sum(i+1);
	}
	
	cout<<ans<<"\n";
	return 0;	
}
