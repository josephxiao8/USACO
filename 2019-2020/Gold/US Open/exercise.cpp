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


vl p;
bool isPrime(ll x){
	for(auto u:p){
		if(u*u>x) return true;
		if(x%u==0) return false;
	}
	return true;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("exercise.out");
	ifstream cin ("exercise.in");
	
	ll n,m;
	cin>>n>>m;
	
	if(n>=2) p.pb(2);
	for(ll i=3; i<=n; i+=2){
		if(isPrime(i)) p.pb(i);
	}
	
	vector<vl> dp(p.size()+1, vl(n+1,0));
	dp[0][0]=1;
	
	for(ll j=0; j<p.size(); j++){
		dp[j+1]=dp[j];
		ll num=p[j];
		while(num<=n){
			for(ll i=num; i<=n; i++){
				dp[j+1][i]+=(dp[j][i-num]*num)%m;
				dp[j+1][i]%=m;
			}
			num*=p[j];
		}
	}
	
	ll ans=1;
	for(int i=1; i<=n; i++){
		ans+=dp[p.size()][i];
		ans%=m;
	}
	cout<<ans<<"\n";
	return 0;	
}
