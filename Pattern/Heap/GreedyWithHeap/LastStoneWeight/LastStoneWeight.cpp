class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
  int k;
        // for(int i=0;i<stones.size();i++)
        while(pq.size()>1)
        {
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            k=x-y;
            if(x==y){
                continue;
            }
            pq.push(k);
        }
        if(pq.empty()){
            return 0;
        }
        else{
            return pq.top();
        }
    //  return pq.top();
    }
};