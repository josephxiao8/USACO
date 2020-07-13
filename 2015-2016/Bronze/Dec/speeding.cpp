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

ofstream cout ("speeding.out");
ifstream cin ("speeding.in");

int n,m;
cin>>n>>m;

vi road(100);
vi bessie(100);

int total_dis=0;
for(int i=0; i<n; i++){
	int dis, speed;
	cin>>dis>>speed;
	for(int j=total_dis; j<total_dis+dis; j++) road[j]=speed;
	total_dis+=dis;
}

total_dis=0;
for(int i=0; i<m; i++){
	int dis, speed;
	cin>>dis>>speed;
	for(int j=total_dis; j<total_dis+dis; j++) bessie[j]=speed;
	total_dis+=dis;
}

int maxx=0;
for(int i=0; i<100; i++)maxx=max(maxx,bessie[i]-road[i]);
cout<<maxx<<endl;

return 0;
}
