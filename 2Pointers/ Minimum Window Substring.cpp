#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

bool check(map<char,int> &mp) {
    for (auto x : mp) if (x.second > 0) return false;
    return true;
}
string minWindow(string s, string t) {
    map<char , int> mp;
    for (int i = 0; i < t.length(); i++) mp[t[i]] ++;

    if (t.length() > s.length()) return "";

    int tail = 0 , head = -1 , n = s.length();
    int ans = 1e9; int l_index = 0 , f_index = 0;

    while (tail < n) {
        while (head + 1 < n && check(mp) == false) {
            head ++;
            if (mp.find(s[head]) != mp.end()) {
                mp[s[head]] --;
            }
        }
        if (check(mp) && (head - tail + 1 )< ans) {
            ans = head - tail + 1;
            f_index = head , l_index = tail;
        }
        if (tail <= head) {
            if (mp.find(s[tail]) != mp.end()) {
                mp[s[tail]] ++;
            }
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
        }
    }

    string st = s.substr(l_index , ans);
    return st;
}
void solve() {    
    string s, t; cin >> s >> t;
    cout << minWindow(s , t);
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