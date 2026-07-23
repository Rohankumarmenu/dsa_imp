//
//Optimal OBSERVATION based solution
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans,n=nums.size(),prod=1 ,pref=1,suff=1;
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
              pref=pref*nums[i];
              suff=suff*nums[n-i-1];
              maxi=max(maxi,max(pref,suff));
              if(pref==0){
                pref=1;
              }

               if(suff==0){
                suff=1;
              }


        }
return maxi;
    }
};


//Kadane's algorithm based solution
