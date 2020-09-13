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


int mod;

bool comp(int a, int b){
	return a%mod>b%mod;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("berries.out");
ifstream cin ("berries.in");

int n,k;
cin>>n>>k;

vi v(n);
int maxx=INT_MIN;
for(int i=0; i<n; i++) {
	cin>>v[i];
	maxx=max(maxx,v[i]);
}

int ans=0;
for(int i=1; i<maxx; i++){
	int counter=0;
	for(auto x:v) counter+=x/i;
	
	if(counter<k/2) break;
	else if(counter>=k) ans=max(ans,i*k/2);
	else{
		mod=i;
		sort(v.begin(), v.end(), comp);
		int tempans=i*(counter-k/2);
		for(int j=0; j<n && j<k-counter; j++) tempans+=v[j]%i;
		ans=max(ans,tempans);
	}
}

cout<<ans<<"\n";
return 0;	
}

