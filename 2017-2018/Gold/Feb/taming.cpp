#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;
 
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
	
	ofstream cout ("taming.out");
	ifstream cin ("taming.in");
	
	int n;
	cin>>n;
	vi v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	
	vector<vector<vi>> dp(n, vector<vi>(n, vi(n+1, 1e9+7)));
	for(int size=0; size<n; size++){
		for(int i=0; i+size<n; i++){
			int cost=0;
			for(int j=0; j<=size; j++){
				if(v[i+j]!=j) cost++;
			}
			dp[i][i+size][1]=cost;
		}
	}
	
	for(int k=2; k<=n; k++){
		for(int size=k-1; size<n; size++){
			for(int i=0; i+size<n; i++){
				for(int j=i; j<i+size; j++){
					dp[i][i+size][k]=min(dp[i][i+size][k], dp[i][j][1]+dp[j+1][i+size][k-1]);
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++) cout<<dp[0][n-1][i]<<"\n";
	return 0;
}
