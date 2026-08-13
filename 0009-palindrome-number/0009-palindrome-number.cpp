class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        // long long rev=0;
        // int n=x;
        // while(x>0){
        //     int d=x%10;
        //     if (rev > (INT_MAX / 10) || (rev == INT_MAX / 10 && d > 7))
        //         return 0; 
        //     rev=rev*10+d;
        //     x/=10;
        // }
        // return (n==static_cast<int>(rev));
        string o = to_string(x);
        string r = o;
        reverse(r.begin(),r.end());
        return o==r;
    }
};