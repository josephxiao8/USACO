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

ofstream cout ("cownomics.out");
ifstream cin ("cownomics.in");

int n,m;
cin>>n>>m;
vector<string>v(2*n);
for(int i=0; i<2*n; i++) cin>>v[i];

int counter=0;
for(int i=0; i<m; i++){
	set<char> spot;
	set<char> plain;
	
	for(int j=0; j<n; j++){
		spot.insert(v[j][i]);
	}
	
	for(int j=n; j<2*n; j++){
		plain.insert(v[j][i]);
	}
	
	bool good=true;
	for(auto x:spot){
		if(plain.count(x)){
			good=false;
			break;	
		}
	}
	if(good) counter++;
}

cout<<counter<<endl;
return 0;
}
