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
 
typedef priority_queue<pair<int,string>> pq;
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

ofstream cout ("bcount.out");
ifstream cin ("bcount.in");

int n,q;
cin>>n>>q;

vector<tuple<int,int,int> > v(n+1);
v[0]=make_tuple(0,0,0);
int a=0, b=0, c=0;
for(int i=1; i<=n; i++){
	int temp;
	cin>>temp;
	if(temp==1) a++;
	else if(temp==2)b++;
	else c++;
	v[i]=make_tuple(a,b,c);
}

for(int i=0; i<q; i++){
	int a,b;
	cin>>a>>b;
	a--;
	int c,d,e,f,g,h;
	tie(c,d,e)=v[b];
	tie(f,g,h)=v[a];
	cout<<c-f<<" "<<d-g<<" "<<e-h<<"\n";
}

return 0;
}
