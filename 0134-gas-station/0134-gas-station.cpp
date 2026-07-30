class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int t_g=0,t_c=0;
        int cu_ga=0,start=0;
        for(int i=0;i<n;i++){
            t_g+=gas[i];
            t_c+=cost[i];
            cu_ga+=gas[i]-cost[i];
            if(cu_ga<0){
                start=i+1;
                cu_ga=0;
            }
        }
   return (t_g<t_c)?-1:start;
    }
};