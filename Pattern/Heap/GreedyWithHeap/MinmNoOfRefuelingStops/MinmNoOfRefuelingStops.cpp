class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int k;
        int n = stations.size();
        priority_queue<int>pq;
        if (stations.size() == 0) {
            if (startFuel >= target) {
                return 0;
            }
            else{
                return -1;
            }
        }

        int newRefill = startFuel, i=0;

        for (k = 0; newRefill < target; k++) {
    

            while(i<n && stations[i][0]<=newRefill){
                pq.push(stations[i++][1]);
                
            }
            if(pq.empty()){
                return -1;
            }
            newRefill+=pq.top();
            pq.pop();
        }
        return k;
    }
};