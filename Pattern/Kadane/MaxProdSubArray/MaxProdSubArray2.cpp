class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0],n=nums.size();
        int mini=nums[0],ans=nums[0];

        for(int i=1;i<n;i++){
            int temp=maxi;
            int num=nums[i]; //Using Kadane Algorithm to find the maximum product subarray
        maxi=max(num,max(mini*num,maxi*num));
        mini=min(num,min(temp*num,mini*num));

        ans=max(ans,maxi);
        }

      return ans;  
    }
};