class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        deque<int>deq;
        int n=nums.size();
        vector<long long>CummSum(nums.size(),0);
        int ans=INT_MAX;
         int i=0;
        while(i<n){
           if(i==0){
            CummSum[i]=nums[i];
           }else{
             CummSum[i]=CummSum[i-1]+nums[i];
           }
           if(CummSum[i]>=k){
            ans=min(ans,i+1);
           }

           while(!deq.empty() && CummSum[i]-CummSum[deq.front()]>=k){
             ans=min(ans,i-deq.front());
             deq.pop_front();
           }
           while(!deq.empty() && CummSum[i]<=CummSum[deq.back()] ){
            deq.pop_back();
           }

           deq.push_back(i);
           i++;
        }
        return ans == INT_MAX? -1:ans;
    }
};