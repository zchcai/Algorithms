class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int min = 256, max, mode;
        int mode_num = 0;
        
        long long sum = 0;
        int num = 0;
        int n = count.size();
        for(int i = 0; i < n; i ++){
            if(count[i] != 0){
                if(min > 255) min = i;
                max = i;
                num += count[i];
                sum += count[i] * i;
                if(count[i] > mode_num) {
                    mode = i;
                    mode_num = count[i];
                }
            }
        }

        double medium;
        if(num % 2){
            int m_id = 1 + num / 2;
            int end_num = 0;
            for(int i = 0; i < n; i ++){
                end_num += count[i];
                if(end_num >= m_id){
                    medium = double(i);
                    break;
                }
            }
        }
        else{
            int m_x = num / 2;
            int end_num = 0;
            for(int i = 0; i < n; i ++){
                end_num += count[i];
                if(end_num >= m_x){
                    medium = double(i);
                    if(end_num < m_x + 1){
                        i ++; while(count[i] == 0) {i ++;}
                        medium = (medium + double(i)) / 2.0; 
                    }
                    break;
                }
            }
        }
        vector<double> ret{double(min), double(max), (double)sum / double(num), medium, double(mode)};
        return ret;
    }
};