
class Solution {
    public:
        vector<int> store;
        void recurse(vector<int>& nums, vector<vector<int>>& ans,
                     unordered_map<int, int>& umap, int cnt) {
    
            if (cnt == nums.size()) {
                ans.push_back(store);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (umap[nums[i]] == 0) {
                umap[nums[i] ]= 1;
                    store.push_back(nums[i]);
                    // cnt++;
                    recurse(nums, ans, umap,cnt+1);
                    store.pop_back();
                    umap[nums[i]] = 0;
    
                }
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            unordered_map<int, int> umap;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                umap[nums[i]] = 0;
            }
            recurse(nums, ans, umap, 0);
            return ans;
        }
    };