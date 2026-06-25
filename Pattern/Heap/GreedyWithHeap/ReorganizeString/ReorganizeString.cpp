class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        int n = s.size();
        unordered_map<char, int> umap;
        for (auto it : s) {
            umap[it]++;
        }

        for (auto it : umap) {
            if (it.second > (n + 1) / 2) {
                return "";
            }
            pq.push({it.second, it.first});
        }
        string ans;

        while (pq.size() > 1) {

            auto fir = pq.top();
            pq.pop();

            auto sec = pq.top();
            pq.pop();

            ans += fir.second;
            ans += sec.second;

            fir.first--;
            sec.first--;

            if (fir.first > 0) {
                pq.push(fir);
            }
            if (sec.first > 0) {
                pq.push(sec);
            }
        }

        if (!pq.empty()) {
            auto last= pq.top();
            pq.pop();
            ans+=last.second;
        }

      
        return ans;
    }
};