


class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>>intervals;
        intervals=occupiedIntervals;

int m= occupiedIntervals[0].size();     
        vector<vector<int>> ans;
        vector<vector<int>> ans2;

        int n=intervals.size(); 
        sort(intervals.begin(),intervals.end());
        vector<int>temp;
        temp=intervals[0];
        for(auto it:intervals){
            if(freeStart)
            if(it[0]<=temp[1] ){
                temp[1]=max(it[1],temp[1]);
            }
            else{
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);

        for(auto it:ans){
           int start=it[0];
            int end=it[1];
            if(end<freeStart || start>freeEnd){
                ans2.push_back({start,end});
                continue;
            }

            if(start<freeStart){
                ans2.push_back({start,freeStart-1});
            }

            if(end>freeEnd){
                ans2.push_back({freeEnd+1,end});
            }
        }

        return ans2;
    }
};©leetcode