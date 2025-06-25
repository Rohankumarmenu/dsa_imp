
class Solution {
    public:
    vector<int>ans;
    void recurse(vector<int>& arr,int i,int sum){
        
        int n=arr.size();
        if(i==n){
            ans.push_back(sum);
            return;
            
        }
        recurse(arr,i+1,sum+arr[i]);
        recurse(arr,i+1,sum);
    }
    
      vector<int> subsetSums(vector<int>& arr) {
          // code here
          int sum;
          recurse(arr,0,0);
          return ans;
      }
  };