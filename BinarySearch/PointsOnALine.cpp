#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// one of the good problems basically we know that the distance between a and c would be the maximum and thus we can be able to say that 
// in case we would be having the elements , we would be taking the value for the nearby index and then we would be having th eremaining indices
// and we would be able to choose 2 indexes from them
void solve() {  
    int n , k; cin >> n >> k;
    vector<int> v(n);
    int sum = 0;

    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        int curr_index = i + 1;
        int needed_index = upper_bound(v.begin() , v.end() , v[i] + k) - v.begin();
        int rem = needed_index - curr_index;

        sum += ((rem) * (rem - 1) * 1LL)/ 2;
    }

    cout << sum << endl;
    
}    


signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t --) {
        solve();
    }
}