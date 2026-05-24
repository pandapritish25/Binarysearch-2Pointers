#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;


int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int n = points.size() , max1 = INT_MIN;
    priority_queue<pair<int,int>> pq;

    for (int i = 0; i < n; i++) {
        while(!pq.empty() && points[i][0] - pq.top().second > k) pq.pop();
        if (!pq.empty()) max1 = max(max1 , points[i][0] + points[i][1] + pq.top().first);
        pq.push({points[i][1] - points[i][0] , points[i][0]});
    }
    return max1;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> v;

    for (int i = 0; i < n; i++) {
        vector<int> x; 
        int a , b; cin >> a >> b;
        x.push_back(a); x.push_back(b);
        v.push_back(x);
    }

    int k; cin >> k;
    cout << findMaxValueOfEquation(v , k);
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