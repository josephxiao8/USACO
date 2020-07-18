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

ofstream cout ("crossroad.out");
ifstream cin ("crossroad.in");

vpi v(10);
for(int i=0; i<10; i++){
	v[i]=mp(-1,0);
}

int n;
cin>>n;

for(int i=0; i<n; i++){
	int cow,side;
	cin>>cow>>side;
	if(v[cow-1].f==-1){
		v[cow-1].f=side;
	}
	
	else if(v[cow-1].f!=side){
		v[cow-1].f=side;
		v[cow-1].s++;
	}
}

int counter=0;
for(auto x:v) counter+=x.s;
cout<<counter<<endl;
return 0;	
}
