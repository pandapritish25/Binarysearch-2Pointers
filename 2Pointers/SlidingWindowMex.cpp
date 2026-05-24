#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()


void solve() {
   int n , k; cin >> n >> k;
   vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];

   multiset<int> seen , unseen; 
   for (int i = 0; i < k + 1; i++) unseen.insert(i);

    for (int i = 0; i < k; i++) {
        seen.insert(v[i]);
        auto it1 = unseen.find(v[i]);
        if (it1 != unseen.end()) unseen.erase(it1); 
    }
    cout << *unseen.begin() << " ";

    for (int i = k; i < n; i++) {
        int del = v[i - k];
        if (seen.find(del) != seen.end()) seen.erase(seen.find(del));
        if (seen.find(del) == seen.end()) unseen.insert(del);

        seen.insert(v[i]); 
        auto it1 = unseen.find(v[i]);
        if (it1 != unseen.end()) unseen.erase(it1);
        cout << *unseen.begin() << " ";
    }
    cout << endl;
}                        
signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}