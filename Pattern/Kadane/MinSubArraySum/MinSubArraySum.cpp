class Solution {
  public:
    int smallestSumSubarray(vector<int>& arr) {
       
        int n=arr.size(),sum=0;
       int mini=INT_MAX;
       
        for(int i=0;i<n;i++){
            sum +=arr[i];
            mini = min(mini,sum);

            if(sum>0){
                 sum=0;
            }
        }

        return mini;
        
    }
};
