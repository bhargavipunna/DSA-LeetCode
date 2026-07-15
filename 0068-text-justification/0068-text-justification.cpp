class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0, n = words.size();
        
        while (i < n) {
            // Find how many words fit in current line
            int j = i;
            int currentLength = words[j].length();
            
            while (j + 1 < n && currentLength + 1 + words[j + 1].length() <= maxWidth) {
                j++;
                currentLength += 1 + words[j].length();
            }
            
            // Calculate spaces needed
            int numWords = j - i + 1;
            int totalChars = 0;
            for (int k = i; k <= j; k++) {
                totalChars += words[k].length();
            }
            
            int totalSpaces = maxWidth - totalChars;
            
            string line = "";
            
            // Last line or single word: left-justified
            if (j == n - 1 || numWords == 1) {
                for (int k = i; k <= j; k++) {
                    line += words[k];
                    if (k < j) line += " ";
                }
                // Pad remaining spaces
                while (line.length() < maxWidth) {
                    line += " ";
                }
            } else {
                // Fully justified
                int spacesBetween = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);
                
                for (int k = i; k <= j; k++) {
                    line += words[k];
                    if (k < j) {
                        int spaces = spacesBetween + (k - i < extraSpaces ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j + 1;
        }
        
        return result;
    }
};