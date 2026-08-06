class Solution {
    int i = 0;
     public String decodeString(String s) {
        i = 0;
        return helper(s);
    }
    private String helper(String s) {
        int m = 0;
        StringBuilder ans = new StringBuilder();
        while(i<s.length()){
        char c = s.charAt(i);
        if(Character.isDigit(c)){
            m = m*10+(c-'0');
            i++;
        }
        else if(c=='['){
            i++;
            String inside = helper(s);
            for(int k=0;k<m;k++){
                ans.append(inside);
            }
            m = 0;
        }
        else if(c==']'){
            i++;
            return ans.toString();
        }
        else{
            ans.append(c);
            i++;
        }

        }
            return ans.toString();

    }
   
}