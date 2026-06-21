
class Data{
    public:
    int value,arrayPos,valuePos;
    Data(int val,int aPos,int vPos){
        value =val;
        arrayPos=aPos;
        valuePos=vPos;
    }
};

struct custComp{
    
    bool operator()(Data &d1,Data &d2){
        return d1.value>d2.value;
    }
};


class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        vector<int>ans;
        int k=mat.size();
         priority_queue<Data,vector<Data>,custComp>pq;
        
        for(int i=0;i<k;i++){
            Data d(mat[i][0],i,0);
            pq.push(d);
        }
        
        while(!pq.empty()){
            
            Data curr=pq.top();
            pq.pop();
            ans.push_back(curr.value);
            
            int ap=curr.arrayPos;
            int vp=curr.valuePos;
            if(vp+1<mat[ap].size()){
                Data d(mat[ap][vp+1],ap,vp+1);
                pq.push(d);
            }
            
             
        }
        return ans;
        
    }
};



