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
typedef priority_queue<pl,vector<pl>,greater<pl>> pqg;
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

	ofstream cout ("cbarn.out");
	ifstream cin ("cbarn.in");
	
	int n;
	cin>>n;
	vi v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	
	int start=-1;
	for(int i=0; i<2*n && start==-1; i++){
		int sum=v[i%n]-1;
		int jump=i;
		for(int j=i+1; j<2*n && sum>=0; j++){
			sum+=v[j%n]-1;
			jump=j;
			if((jump+1)%n==i){
				start=i;
				break;
			}
		}
		i=jump;
	}
	
	ll ans=0;
	queue<int> q; 
	for(int i=start; i<start+n; i++){
		while(v[i%n]--) q.push(i);
		if(q.empty()) continue;
		int front=q.front(); q.pop();
		ans+=(ll(i)-ll(front))*(ll(i)-ll(front)); 
	}
	
	cout<<ans<<"\n";
	return 0;
}
