class Solution {
public:
      static bool compare(vector<int> &a,vector<int> &b){
            return a[1] < b[1];
        }
    int scheduleCourse(vector<vector<int>>& courses) {
      sort(courses.begin(),courses.end(),compare);
        priority_queue<int> maxD;
        int t = 0;
        for (auto course : courses){
            if (t + course[0] <= course[1]){
                t += course[0];
                maxD.push(course[0]);
            }
            else if (!maxD.empty() && maxD.top() >= course[0]){
                t = t - maxD.top() + course[0]; 
                maxD.pop();                           
                maxD.push(course[0]);                
            }
        }
        return maxD.size();
    }
};