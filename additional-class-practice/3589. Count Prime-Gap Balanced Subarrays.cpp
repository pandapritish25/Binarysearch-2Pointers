#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()


bool isPrime(int n) {
    if (n <= 1)return false;
    if (n == 2 || n == 3)return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false;
    return true;
}
// basically what needs to be done here is basically you need to take the intersection for both the arrays
// n=4 v=2 3 5 7 k=3

// the ans is 1 2 3 -1  2 2 3 3  and then we need to take the intersection and thus after taking the intersection , we would be having the ans;
// and then while taking the intersection , we need to find     for (int i = 0; i < n; i++) {if (ans1[i] == -1 || ans1[i] > ans2[i]) continue;sum += (ans2[i] - ans1[i] + 1);} and then return the sum which would give us the ans

int primeSubarray(vector<int>& v, int k) {
    int n = v.size();
    int head1 = -1 , tail = 0;
    int count = 0;
    vector<int> ans1(n , -1) , ans2(n , -1);

    while (tail < n) {
        while(head1 + 1 < n && count < 2) {
            if (isPrime(v[head1 + 1])) count ++;
            head1 ++;
        }
        if (count >= 2) ans1[tail] = head1;
        if (tail <= head1) {
            if (isPrime(v[tail])) count --;
            tail ++;
        }
        else {
            tail ++; head1 = tail - 1;
        }
    }
    
    tail = 0; head1 = -1; multiset<int> st;
    while(tail < n) {
        while(head1 + 1 < n) {
            if (isPrime(v[head1 + 1])) st.insert(v[head1 + 1]);
            if (!st.empty() && *st.rbegin() - *st.begin() > k) {
                st.erase(st.find(v[head1 + 1]));
                break; 
            }
            head1 ++;
        }
        if (!st.empty() && *st.rbegin() - *st.begin() <= k) ans2[tail] = head1;
        if (tail <= head1) {
            if (isPrime(v[tail])) st.erase(st.find(v[tail]));
            tail ++;
        }
        else {
            tail ++; head1 = tail - 1;
        }
    }
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (ans1[i] == -1 || ans1[i] > ans2[i]) continue;
        sum += (ans2[i] - ans1[i] + 1);
    }
    return sum;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int k; cin >> k;
    int ans = primeSubarray(v , k);
    cout << ans;
}   

signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}