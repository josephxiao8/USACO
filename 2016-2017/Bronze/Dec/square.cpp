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

ofstream cout ("square.out");
ifstream cin ("square.in");

int r,l,u,d;
int x1,y1,x2,y2;
cin>>x1>>y1>>x2>>y2;
r=max(x1,x2);
l=min(x1,x2);
u=min(y1,y2);
d=max(y1,y2);
cin>>x1>>y1>>x2>>y2;
r=max(r,max(x1,x2));
l=min(l,min(x1,x2));
u=min(u,min(y1,y2));
d=max(d,max(y1,y2));

int s=max((r-l),(d-u));
cout<<s*s<<endl;

return 0;
}
