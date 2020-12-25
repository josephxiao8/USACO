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
	
	ofstream cout ("nocross.out");
	ifstream cin ("nocross.in");
	
	int n;
	cin>>n;
	vi l(n+1);
	vi r(n+1);
	for(int i=1; i<=n; i++) cin>>l[i];
	for(int i=1; i<=n; i++) cin>>r[i];
	
	int ans=0;
	vector<vi> dp(n+1, vi(n+1, 0));
	for(int j=1; j<=n; j++){
		for(int i=1; i<=n; i++){
			if(abs(l[j]-r[i])<=4) dp[j][i]=dp[j-1][i-1]+1;
			else dp[j][i]=dp[j-1][i-1];
			dp[j][i]=max(dp[j][i], max(dp[j][i-1],dp[j-1][i]));
			ans=max(ans,dp[j][i]);
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
