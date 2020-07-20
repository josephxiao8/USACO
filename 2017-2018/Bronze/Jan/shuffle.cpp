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

ofstream cout ("lifeguards.out");
ifstream cin ("lifeguards.in");

int n;
cin>>n;

vpi time;
for(int i=0; i<n; i++){
	int s,e;
	cin>>s>>e;
	time.pb(mp(s,e));
}

int ans=INT_MIN;
for(int j=0; j<n; j++){
	vi temp(1000,0);
	for(int i=0; i<n; i++){
		if(i==j) continue;
		for(int t=time[i].f; t<time[i].s; t++) temp[t]++;
	}
	int counter=0;
	for(int t=0; t<1000; t++) if(temp[t]>0) counter++;
	ans=max(ans,counter);
}

cout<<ans<<endl;
return 0;
}
