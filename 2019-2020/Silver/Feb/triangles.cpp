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
typedef priority_queue<pi,vector<pi>,greater<pi> > pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


const ll mod=1e9+7;

bool comp(pl a, pl b){
	return a.s<b.s;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("triangles.out");
ifstream cin ("triangles.in");

ll n;
cin>>n;
vpl v;
for(ll i=0; i<n; i++){
	ll a,b;
	cin>>a>>b;
	v.pb(mp(a,b));
}
sort(v.begin(), v.end());

vector<vl> prefix_x(100000);
map<ll,ll> mapp_x;
map<pl,ll> mapp_x2;
map<pl, pl> left_right_x;
ll counter=0;
for(ll i=0; i<n; i++){
	mapp_x[v[i].f]=counter;
	ll id;
	ll sum=0;
	vl temp;
	for(ll j=i; j<n && v[j].f==v[i].f; j++){
		id=j;
		temp.pb(v[j].s);
		sum+=v[j].s;
	}
	sort(temp.begin(), temp.end());
	
	ll counter2=0;
	ll left=0;
	ll right=ll(temp.size())-1;
	for(int j=0; j<ll(temp.size()); j++){
		mapp_x2[mp(v[i].f,temp[j])]=counter2;
		left_right_x[mp(v[i].f,temp[j])]=mp(left,right);
		sum-=temp[j];
		prefix_x[counter].pb(sum);
		sum-=temp[j];
		counter2++;
		left++;
		right--;
	}
	
	i=id;
	counter++;
}

sort(v.begin(), v.end(), comp);

vector<vl> prefix_y(100000);
map<ll,ll> mapp_y;
map<pl,ll> mapp_y2;
map<pl, pl> left_right_y;
counter=0;
for(ll i=0; i<n; i++){
	mapp_y[v[i].s]=counter;
	ll id;
	ll sum=0;
	vl temp;
	for(ll j=i; j<n && v[j].s==v[i].s; j++){
		id=j;
		temp.pb(v[j].f);
		sum+=v[j].f;
	}
	sort(temp.begin(), temp.end());
	
	ll counter2=0;
	ll left=0;
	ll right=int(temp.size())-1;
	for(ll j=0; j<ll(temp.size()); j++){
		mapp_y2[mp(temp[j],v[i].s)]=counter2;
		left_right_y[mp(temp[j],v[i].s)]=mp(left,right);
		sum-=temp[j];
		prefix_y[counter].pb(sum);
		sum-=temp[j];
		counter2++;
		left++;
		right--;
	}
	
	i=id;
	counter++;
}

sort(v.begin(), v.end());
ll ans=0;
for(auto x:v){
	ll a,b;
	tie(a,b)=x;
	ll x_id=mapp_x[a];
	ll x2_id=mapp_x2[x];
	ll y_id=mapp_y[b];
	ll y2_id=mapp_y2[x];
	
	ll left_x, right_x;
	tie(left_x, right_x)=left_right_x[x];
	ll left_y, right_y;
	tie(left_y, right_y)=left_right_y[x];
	
	ll temp=((prefix_x[x_id][x2_id]+((left_x-right_x)*b))%mod)*((prefix_y[y_id][y2_id] +((left_y-right_y)*a))%mod);
	ans = (ans + (temp%mod) )%mod;
}

cout<<ans<<"\n";
return 0;	
}

