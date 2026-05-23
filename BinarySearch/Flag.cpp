#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bool check(string s) {
    int n = s.length();
    set<char> st;
    for (int i = 0; i < n; i++) st.insert(s[i]);

    return st.size() == 1;
}
// just a simple problem to complete 3 questions means that there is a flag you need to check 
// if each row has all chars same and coloums shouldnt have any value same
void solve() {  
    int n , m; cin >> n >> m;
    int ok = 1;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (!check(s)) {
            ok = 0;
            break;
        }
        v.push_back(s);
    }

    
    if (!ok) {
        cout << "NO\n";
        return;
    }


    for (int i = 0; i < n - 1; i++) {
        if (v[i][0] == v[i + 1][0]) ok = false;
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
