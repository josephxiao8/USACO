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
typedef priority_queue<ti,vector<ti>,greater<ti>> pqg;
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
	
	ofstream cout ("cbarn2.out");
	ifstream cin ("cbarn2.in");
	
	ll n,k;
	cin>>n>>k;
	vl v(n);
	for(ll i=0; i<n; i++) cin>>v[i];
	
	vector<vector<vl>> dp(n+1, vector<vl>(n+1, vl(k+1,1e11)));
	
	ll ans=LONG_LONG_MAX;
	for(ll i=1; i<=n; i++){
		vector<vl> prefix(n+1, vl(n+1));
		for(int j=0; j<n; j++){
			for(int a=1; a+j<=n; a++){
				if(j==0) prefix[a][a]=0;
				else prefix[a][a+j]=prefix[a][a+j-1]+(j*v[a+j-1]);
			}
		}
		
		dp[i][1][1]=0;
		for(ll j=2; j<=n; j++){
			for(ll a=2; a<=min(k,j); a++){
				for(ll b=1; b<j; b++){
					dp[i][j][a]=min(dp[i][b][a-1]+prefix[b][j-1], dp[i][j][a]);
				}
			}
		}
		
		for(ll j=1; j<=n; j++) ans=min(ans,dp[i][j][k]+prefix[j][n]);
		rotate(v.begin(), v.begin()+1, v.end());
	}
	
	cout<<ans<<"\n";
	return 0;
}
