//https://leetcode.com/problems/valid-palindrome/description/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;
bool isPalindrome(string s) {
    int n = s.length(); string ans;
    for (int i = 0; i < n; i++) {
        if(isalpha(s[i])) ans.push_back(tolower(s[i]));
        if (isdigit(s[i])) ans.push_back((s[i]));
    }
    
    n = ans.length();
    for (int i = 0; i < n / 2; i++) {
        if (ans[i] != ans[n - i - 1]) return false;
    } 
    return true;
}
void solve() {
    string s; cin >> s;
    cout << isPalindrome(s);
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