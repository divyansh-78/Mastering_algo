class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b)
{
    return a[1]<b[1];
}
int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), compare);
    priority_queue<int>pq;
    int timing;
    int deadline;
    int now= 0;
    int i= 0;
    for (i=0;i<courses.size();i++) {
        timing = courses[i][0];
        deadline = courses[i][1];
        if (now+timing <=deadline) {
            now += timing;
            pq.push(timing);
        }
        else if (!pq.empty() && pq.top() > timing) {
            now += timing- pq.top();
            pq.pop();
            pq.push(timing);
        }
    }
    return pq.size();
}
};
