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

ofstream cout ("promote.out");
ifstream cin ("promote.in");

ll b_i, b_f, s_i, s_f, g_i, g_f, p_i, p_f;
cin>>b_i>>b_f>>s_i>>s_f>> g_i>>g_f>>p_i>>p_f;

ll p_counter=0, g_counter=0, s_counter=0, joined;
joined=p_f+g_f+s_f+b_f-p_i-g_i-s_i-b_i;
b_i+=joined;
if(b_i>b_f) s_counter+=b_i-b_f;
s_i+=s_counter;
if(s_i>s_f) g_counter+=s_i-s_f;
g_i+=g_counter;
if(g_i>g_f) p_counter+=g_i-g_f;
p_i+=p_counter;

cout<<s_counter<<endl<<g_counter<<endl<<p_counter;

return 0;
}
