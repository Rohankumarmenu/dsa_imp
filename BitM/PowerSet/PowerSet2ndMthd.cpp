

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> jk;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < (1 << n); i++) {
            jk.clear();
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    jk.push_back(nums[j]);
                }
            }
            ans.push_back(jk);
        }
        return ans;
    }
};