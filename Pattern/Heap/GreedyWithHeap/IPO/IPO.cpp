class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        priority_queue<int> pq;
        vector<pair<int, int>> store;
        int n = profits.size();
        int m = capital.size();
        for (int i = 0; i < n; i++) {
            store.push_back({capital[i],profits[i]});
        }
        sort(store.begin(), store.end());

        int newCap = w;
        int i = 0;
        while (k > 0) {

            while (i < n &&  store[i].first<=newCap) {
                pq.push(store[i].second);
                i++;
            }
                if (pq.empty()) {
                break;
            }

            newCap += pq.top();
            pq.pop();

            k--;
        }
        return newCap;
    }
};