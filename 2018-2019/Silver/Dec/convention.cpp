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


int n,m,c;
vi v;

bool possible(int k){
	int buses=0;
	for(int i=0; i<n; i++){
		int id;
		int cows=0;
		for(int j=i; j<n && v[j]-v[i]<=k && cows<c; j++){
			id=j;
			cows++;
		}
		buses++;
		i=id;
	}
	if(buses>m) return false;
	else return true;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("convention.out");
ifstream cin ("convention.in");

cin>>n>>m>>c;
v=vi(n);
for(int i=0; i<n; i++) cin>>v[i];
sort(v.begin(), v.end());

int k=-1;
for(int b=(v.back()-v.front())/2; b>=1; b/=2){
	while(k+b<=v.back()-v.front() && !possible(k+b)) k+=b;
}

cout<<k+1<<"\n";
return 0;	
}

