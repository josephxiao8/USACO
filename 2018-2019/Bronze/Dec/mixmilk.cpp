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

ofstream cout ("mixmilk.out");
ifstream cin ("mixmilk.in");

vpi milk(3);
for(int i=0; i<3; i++){
	int a,b;
	cin>>a>>b;
	milk[i]=mp(a,b);
}

for(int i=0; i<100; i++){
	int a=i%3, b=(i+1)%3;
	if(milk[a].s+milk[b].s>milk[b].f){
		milk[a].s-=milk[b].f-milk[b].s;
		milk[b].s=milk[b].f;
	}
	else{
		milk[b].s=milk[b].s+milk[a].s;
		milk[a].s=0;	
	}
}

for(auto x:milk) cout<<x.s<<endl;
return 0;	
}
