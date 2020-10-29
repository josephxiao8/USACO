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

ofstream cout ("marathon.out");
ifstream cin ("marathon.in");

int n,k;
cin>>n>>k;
vpi v(n);
for(int i=0; i<n; i++) cin>>v[i].f>>v[i].s;

vector<vi> dp(n, vi(k+1,1e9+7));
//dp state: (checkpoint we are on, how many we have skipped already)
for(int i=0; i<=k; i++) dp[0][i]=0;
for(int j=1; j<n; j++){
	for(int i=0; i<=k; i++){ //how much we are planning to have skipped when we land to checkpoint j
		for(int a=0; a<=i; a++){ //how many we have skipped already prior to landing on checkpoint j
			if(j-(i-a)-1>=0) dp[j][i]=min(dp[j][i], dp[j-(i-a)-1][a]+abs(v[j-(i-a)-1].f-v[j].f)+abs(v[j-(i-a)-1].s-v[j].s)); 
		}
	}
}

int ans=1e9+7;
for(auto x:dp[n-1]) ans=min(ans,x);
cout<<ans<<"\n";

return 0;	
}

