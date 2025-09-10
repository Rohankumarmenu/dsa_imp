
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> store;
    bool check(string k, int l, int r) {
        while (l < r) {
            if (k[l] != k[r]) {
                return 0;
            }
            l++;
            r--;
        }
        return 1;
    }
    void recur(int ind, string& s) {
        if (ind == s.size()) {
            ans.push_back(store);
            return;
        }
        for (int i = ind; i < s.size(); i++) {
            // string p = s.substr()
            if (check(s, ind, i)) {
                store.push_back(s.substr(ind, i - ind + 1));
                recur(i + 1, s);
                store.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        recur(0, s);
        return ans;
    }
};