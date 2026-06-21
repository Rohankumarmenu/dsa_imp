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

//Similar to "merge k sorted array" we can use the same logic here as well. 

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        

         // Code here
        vector<int>ans;
        int n=matrix.size();
         priority_queue<Data,vector<Data>,custComp>pq;
        
        for(int i=0;i<n;i++){
            Data d(matrix[i][0],i,0);
            pq.push(d);
        }
        int cnt=0;
        while(!pq.empty()){
            
            Data curr=pq.top();
            pq.pop();
            ans.push_back(curr.value);
            
            int ap=curr.arrayPos;
            int vp=curr.valuePos;
            if(vp+1<matrix[ap].size()){
                Data d(matrix[ap][vp+1],ap,vp+1);
                pq.push(d);
            }
            
             
        }
        return ans[k-1];

    }
};

