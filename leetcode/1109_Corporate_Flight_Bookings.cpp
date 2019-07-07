class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret; ret.resize(n);
        for(auto& book : bookings){
            ret[book[0] - 1] += book[2];
            if(book[1] < n) ret[book[1]] -= book[2];
        }
        for(int i = 1; i < ret.size(); i ++){
            ret[i] = ret[i] + ret[i - 1];
        }
        return ret;
    }
};