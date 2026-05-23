#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

int lengthOfLongestSubstring(string s) {
    int n = s.length(); int head = -1 , tail = 0 , distinct = 0;
    int ans = 0;
    int freq[256]; 
    for (int i = 0; i < 256; i++) freq[i] = 0;

    while (tail < n) {
        while(head + 1 < n && freq[s[head + 1]] == 0) {
            head ++; 
            freq[s[head]] ++;
        }
        ans = max(ans , head - tail + 1);
        if (tail <= head) {
            freq[s[tail]] --;
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
            for (int i = 0; i < 256; i++) freq[i] = 0;
        }
    }
    return ans;
}
void solve() {
    string s; cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
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