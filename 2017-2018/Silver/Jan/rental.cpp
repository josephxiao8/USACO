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


bool comp(pl a, pl b){
	if(a.s==b.s) return a.f>b.f;
	else return a.s>b.s;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("rental.out");
ifstream cin ("rental.in");

ll n,m,r;
cin>>n>>m>>r;

vl cows(n);
for(ll i=0; i<n; i++) cin>>cows[i];
sort(cows.rbegin(), cows.rend());

vl prefix_cows(n+1); //use to determine how much milk can be produced from x cows
prefix_cows[0]=0;
for(ll i=1; i<=n; i++) prefix_cows[i]=prefix_cows[i-1]+cows[i-1];

vpl buy(m);
for(ll i=0; i<m; i++) cin>>buy[i].f>>buy[i].s;
sort(buy.begin(), buy.end(), comp);

vl prefix_buy(m+1); //use to determine how much money can be earned from selling to x buyers
prefix_buy[0]=0;
for(ll i=1; i<=m; i++) prefix_buy[i]=prefix_buy[i-1]+(buy[i-1].f*buy[i-1].s);

vl prefix_milk(m+1);//use to determine how much milk is needed in total from x buyers
prefix_milk[0]=0;
for(ll i=1; i<=m; i++) prefix_milk[i]=prefix_milk[i-1]+buy[i-1].f; 

vl rent(r);
for(ll i=0; i<r; i++) cin>>rent[i];
sort(rent.rbegin(), rent.rend());

vl prefix_rent(r+1);//use to determne how much money will be earned from renting x cows
prefix_rent[0]=0;
for(ll i=1; i<=r; i++) prefix_rent[i]=prefix_rent[i-1]+rent[i-1];

ll ans=0;
for(ll i=0; i<=min(n,m+r); i++){ //i is the number of cows he is going to sell
	ll j=min(n,m+r)-i; // j is the number of cows he is going to rent
	if(i>m || j>r) continue;
	ll counter=0;
	
	//buy
	ll have=prefix_cows[i]; //amount of milk available
	auto it=ub(prefix_milk.begin(), prefix_milk.end(), have);
	it--;
	counter+=prefix_buy[it-prefix_milk.begin()];
	have-=prefix_milk[it-prefix_milk.begin()];
	if(it!=(--prefix_milk.end())) counter+=have*buy[(it-prefix_milk.begin())].s;
	
	//rent
	counter+=prefix_rent[j];
	ans=max(ans,counter);
	
}

cout<<ans<<"\n";
return 0;	
}

