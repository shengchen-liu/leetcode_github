class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double low = 0, high = 1e8;
        while (high - low > 1e-6) {
            double mid = (low + high) / 2;
            if (possible(mid, stations, K))
                high = mid;
            else 
                low = mid;
        }
        return low;
    }
    
    bool possible(double D, vector<int>& stations, int K) {
        int used = 0;
        for (int i = 0; i < stations.size() - 1; ++i) {
            used += (int) ((stations[i + 1] - stations[i]) / D);
        }
        return used <= K;
    }
};