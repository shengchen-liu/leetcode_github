class Solution {
public:
    int lengthLongestPath(string input) {
        int depth = 0, sum = 0, token = 0, maxlen = 0;
        bool newline = true, isfile = false;
        stack<int> dirStack;
        
        for (int i = 0; i <= input.length(); ++i) {
            char c = input.c_str()[i];
            
            if (c == '\n' || c == '\0') {
                if (isfile) {
                    maxlen = max(maxlen, sum);
                    sum -= token; // remove filename from sum
                } else {
                    token++, sum++; // account for / at end of dir
                    dirStack.push(token);
                }
                token = 0;
                depth = 0;
                isfile = false;
                newline = true;
                continue;
            }
            
            if (c == '\t') {
                depth++;
                continue;
            }
            
            // All characters past this point count towards the next line length, we've
            // counted the depth (tabs) leading up to this, if we aren't as deep as our
            // stack was on the prior line, subtract & pop directory lengths from the  
            // stack until we are 
            if (newline) {
                newline = false;
                while (depth < dirStack.size()) {
                    sum -= dirStack.top();
                    dirStack.pop();
                }
            }
            
            if (c == '.') isfile = true;
            token++;
            sum++;
        }
        
        return maxlen;
    }
};