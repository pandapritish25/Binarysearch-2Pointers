#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

int longestValidSubstring(string word, vector<string>& forbidden) {
    unordered_set<string> s; for (auto x : forbidden) s.insert(x);
    // having the right pointer into place 
    int n = word.length(); int l = 0 , ans = 0;

    for (int r = 0; r < n; r++) {
        // checking the length for 10 length only
        for (int len = 1; len <= 10; len ++) {
            // then checking for the start that if thius is r - len _ 1 and if that would cross left pointer then no way
            int start = r - len + 1;
            if (start < l) break;
            // find each stubstring of length 10
            string temp = word.substr(start , len);
            // if there is there then break
            if (s.count(temp)) {
                l = start + 1; break;
            }
        }
        // max length
        ans = max(ans , r - l + 1);
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    string word; cin >> word;
    vector<string> forbidden(n);
    for (int i = 0; i < n; i++) cin >> forbidden[i];

    cout << longestValidSubstring(word , forbidden) << endl;
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