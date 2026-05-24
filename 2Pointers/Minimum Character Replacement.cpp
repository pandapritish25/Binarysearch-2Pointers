#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;


int characterReplacement(string s, int k) {
    int tail = 0 , head = -1 , n = s.length();
    vector<int> freq(26 , 0); int max1 = 0;
    vector<int> rest = freq;

    while (tail < n) {
        while(head + 1 < n) {
            freq[s[head + 1] - 'A'] ++;
            int ans1 = *max_element(all(freq)); int length = head - tail + 2;
            int flips = length - ans1;

            if (flips <= k) {
                head ++;
            }
            else {
                freq[s[head + 1] - 'A'] --;
                break;
            }
        }
        max1 = max(max1 , head - tail + 1);
        if (tail <= head) {
            freq[s[tail] - 'A'] --;
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
            freq = rest;
        }
    }    
    return max1;
}
void solve() {    
    string s; cin >> s;
    int k; cin >> k;
    cout << characterReplacement(s , k) << endl;
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