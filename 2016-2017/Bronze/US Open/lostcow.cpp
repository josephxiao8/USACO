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

ofstream cout ("lostcow.out");
ifstream cin ("lostcow.in");

int x,y;
cin>>x>>y;

int pos_cur=x, pos_past=x, dis=1, ans=0;

while(!((pos_cur <=y && y<=x) || (x<=y && y<=pos_cur))){
	pos_past=pos_cur;
	pos_cur=x+dis;
	ans+=abs(pos_cur-pos_past);
	dis*=-2;
}

cout<<ans-abs(pos_cur-y)<<endl;

return 0;	
}
