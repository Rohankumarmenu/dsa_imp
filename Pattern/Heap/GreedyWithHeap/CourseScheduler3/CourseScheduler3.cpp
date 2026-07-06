struct SortBySecondElement {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[1] < b[1];
    }
};

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        vector<pair<int, int>> store;
        int n = courses.size();
        int cnt = 0;
        int sum = 0;
        sort(courses.begin(), courses.end(), SortBySecondElement());
        sum = 0;
        for (int i = 0; i < n; i++) {

            sum = sum + courses[i][0];
            pq.push(courses[i][0]);

            if (sum > courses[i][1]) {
                int longer = pq.top();
                pq.pop();
                sum = sum - longer;


            }
        }
        return pq.size();
    }
};