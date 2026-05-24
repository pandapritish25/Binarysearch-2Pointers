#include <bits/stdc++.h>
using namespace std;

using ll = long long;
bool check(vector<int> v) {
    for (int i = 0; i < 3; i++) if (v[i] == 0) return 0;
    return 1;
}
ll ceil_div(ll n) {
    if (n % 2 == 0) {
        ll ans1 = n / 2; ll ans2 = n + 1;
        ll ans = ans1 * ans2 * 1LL;
        return ans;
    }
    else if (n % 2 == 1) {
        ll ans1 = (n + 1) / 2; ll ans2 = n;
        ll ans = ans1 * ans2 * 1LL;
        return ans;
    }
    return 0;
}

int numberOfSubstrings(string s) {
    ll n = s.length(); int head = -1 , tail = 0;
    vector<int> freq(3 , 0); ll ans = 0;

    while (tail < n) {
        while(head + 1 < n) {
            freq[s[head + 1] - 'a'] ++;
            if (check(freq) == true) {
                freq[s[head + 1] - 'a'] --;
                break;
            }
            head ++;
        }
        ans = ans + (head - tail + 1);
        if (tail <= head) {
            freq[s[tail] - 'a'] --;
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
        }
    }
    ll no_of_subarrays = ceil_div(n);
    return no_of_subarrays - ans;
}


signed main() {
    string s; cin >> s;
    cout << numberOfSubstrings(s);
}