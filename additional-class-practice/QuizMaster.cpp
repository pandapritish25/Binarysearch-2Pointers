#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

const int N = 100005;
vector<int> divisors[N + 100];
void spf() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) divisors[j].push_back(i);
    }
}
int distinct[N];
void solve() {
    memset(distinct , 0 , sizeof(distinct));

    int n , x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));

    int ans = -1 , head = -1 , tail = 0 , distinct1 = 0;
    int min1 = 1e18;

    // eat as many topics you can and then find the minimum element
    while (tail < n) {
        vector<int> ans;
        while(head + 1 < n && distinct1 < x) {
            vector<int> ans1 = divisors[v[head + 1]];
            for (int i = 0; i < ans1.size(); i++) {
                // checking if we can take this topic , in case greater make this small
                if (ans1[i] > x) continue;
                if (distinct[ans1[i]] == 0) distinct1 ++;
                distinct[ans1[i]] ++;
            }
            head = head + 1;
        }
        if (distinct1 >= x) min1 = min(min1 , v[head] - v[tail]);
        if (tail <= head) {
            vector<int> ans1 = divisors[v[tail]];
            for (int i = 0; i < ans1.size(); i++) {
                // only less than topics are included
                if (ans1[i] > x) continue;
                distinct[ans1[i]] --;
                if (distinct[ans1[i]] == 0) distinct1 --;
            }
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
        }
    }

    if (min1 == 1e18) {
        cout << -1 << endl; return;
    }

    cout << min1 << endl;
}   

signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    spf();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}