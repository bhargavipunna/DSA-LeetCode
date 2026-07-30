class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int i=0,n = stations.size(),stops = 0,max_d = startFuel;
        while(max_d<target){
            while(i<n && stations[i][0]<=max_d){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()){
                return -1;
            }
            max_d += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};