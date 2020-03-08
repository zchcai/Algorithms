class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> change;
        for (auto& trip: trips) {
            change[trip[1]] += trip[0]; 
            change[trip[2]] -= trip[0]; 
        }
        int count = 0;
        for (auto& entry: change) {
            count += entry.second;
            if (count > capacity) {
                return false;
            }
        } 
        return true;
    }
};

/*
class mycomparison {
public:
  bool operator() (const vector<int>& a, const vector<int>&b) const {
    return (a[2] > b[2]);
  }
};

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return (a[1] < b[1]);
    }
    bool carPooling(vector<vector<int>>& trips, int c) {
        int n = trips.size();     
        sort(trips.begin(), trips.end(), cmp);
        int current_num = 0;
        priority_queue<vector<int>, vector<vector<int> >, mycomparison> cur;
        for(int i = 0; i < n; i ++){
            while(!cur.empty()){
                if(trips[i][1] < cur.top()[2]){
                    break;
                }
                current_num -= cur.top()[0];
                cur.pop();
            }
            cur.push(trips[i]);
            current_num += trips[i][0];
            if(current_num > c) return false;
            else continue;   
        }
        return true;
    }
};
*/