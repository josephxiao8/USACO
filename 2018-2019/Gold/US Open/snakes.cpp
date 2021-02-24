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

	ofstream cout ("snakes.out");
	ifstream cin ("snakes.in");
	
	int n,k;
	cin>>n>>k;
	vi v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	vector<vi> dp(k+2, vi(n,1e9+7));
	
	int maxxx=-(1e9+7);
	int summ=0;
	for(int i=n-1; i>=0; i--){
		maxxx=max(maxxx,v[i]);
		summ+=v[i];
		dp[1][i]=maxxx*(n-i)-summ;
	}
	
	for(int a=2; a<=k+1; a++){
		for(int i=0; i<n; i++){
			int maxx=-(1e9+7);
			int sum=0;
			for(int j=i; j<n-1; j++){
				maxx=max(maxx,v[j]);
				sum+=v[j];
				dp[a][i]=min(dp[a][i],maxx*(j-i+1)-sum+dp[a-1][j+1]);
			}
		}
	}
	
	cout<<dp[k+1][0]<<"\n";
	return 0;	
}
