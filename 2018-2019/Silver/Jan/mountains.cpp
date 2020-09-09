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


bool comp(pi a, pi b){
	if(a.f==b.f) return a.s>b.s;
	else return a.f<b.f;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("mountains.out");
ifstream cin ("mountains.in");

int n;
cin>>n;
vpi v(n);
for(int i=0; i<n; i++){
	int a,b;
	cin>>a>>b;
	v[i]=mp(a-b, a+b);
}
sort(v.begin(), v.end(), comp);

int ans=0;
for(int i=0; i<n; i++){
	int id;
	for(int j=i; j<n && v[j].s<=v[i].s; j++) id=j;
	ans++;
	i=id;
}

cout<<ans<<"\n";
return 0;
}
