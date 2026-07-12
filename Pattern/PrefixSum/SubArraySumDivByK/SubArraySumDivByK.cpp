class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> umap;
        int sum = 0;
        int rem = 0;
        umap[rem] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            // if (rem > 0) {
            //     umap[rem]++;
            // } else {
            //     rem = rem + k;
            //     umap[rem]++;
            // }

            // if (umap[rem] > 1) {
            //     cnt++;
            //     umap[rem]--;
            // }

            if(rem < 0){
                rem = rem + k;
            }
            if(umap.find(rem)!=umap.end()){
               cnt=cnt+umap[rem];
            }
            
            umap[rem]++; 

        }

        return cnt;
    }
};