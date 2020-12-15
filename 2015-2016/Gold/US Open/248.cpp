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
	
	ofstream cout ("248.out");
	ifstream cin ("248.in");
	
	int n;
	cin>>n;
	vi v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	
	int ans=INT_MIN;
	vector<vi> dp(n, vi(n,INT_MIN));
	vector<vector<bool> > collapse(n, vector<bool>(n,false));
	
	for(int size=0; size<n; size++){
		for(int i=0; i+size<n; i++){
			if(size==0){
				collapse[i][i]=true;
				dp[i][i]=v[i];
			}
			else{
				for(int j=i; j<=i+size-1; j++){
					if(!(collapse[i][j] && collapse[j+1][i+size])) continue;
					if(dp[i][j]==dp[j+1][i+size]){
						collapse[i][i+size]=true;
						dp[i][i+size]=max(dp[i][i+size], dp[i][j]+1);
					}
				}
			}
			ans=max(ans, dp[i][i+size]);
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
