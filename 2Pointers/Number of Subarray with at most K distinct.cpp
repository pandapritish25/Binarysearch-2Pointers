#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

int freq[100010];
void solve() {
    int n , x; cin >> n >> x;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];

    memset(freq , 0 , sizeof(freq));

    int head = -1 , tail = 0 , ans = 0 , distinct = 0;

    while (tail < n) {
        while(head + 1 < n && (distinct < x || freq[v[head + 1]] > 0)) {
            head ++; 
            if (freq[v[head]] == 0) distinct ++;
            freq[v[head]] ++;
        }
        ans = ans + (head - tail + 1);
        if (tail <= head) {
            freq[v[tail]] --;
            if (freq[v[tail]] == 0) distinct --;
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
            memset(freq , 0 , sizeof(freq));
        }
    }

    cout << ans << endl;
}                        
signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}