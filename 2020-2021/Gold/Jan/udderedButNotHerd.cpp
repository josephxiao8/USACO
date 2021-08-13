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
	
	string s;
	cin>>s;
	
	int n=s.size();
	vi mapp(2600,0);
	for(int i=0; i<n-1; i++){
		mapp[(s[i]-'a')*100+(s[i+1]-'a')]++;
	}
	
	vi freq(26,0);
	string str="";
	for(auto x:s){
		if(freq[x-'a']==0) str+=x;
		freq[x-'a']++;
	}
	
	n=str.size();
	vi dp(1<<n,1e5);
	dp[0]=0;
	for(int i=0; i<(1<<n); i++){
		for(int mask=0; mask<n; mask++){
			if(i&(1<<mask)){
				int cnt=0;
				for(int mask2=0; mask2<n; mask2++){
					if(i&(1<<mask2)){
						cnt+=mapp[(str[mask]-'a')*100+(str[mask2]-'a')];
					}
				}
				dp[i]=min(dp[i],dp[i^(1<<mask)]+cnt);
			}
		}
	}
	
	cout<<dp[(1<<n)-1]+1<<"\n";
	return 0;	
}
