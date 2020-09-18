class Solution {
public:
    bool isRobotBounded(string instructions) {
        bool xp = false, xn = false, yp = true, yn = false;
        int xpos = 0, ypos = 0;
        for(char c : instructions) {
            if(c == 'G') {
                if(yp)    ypos++;
                else if(yn)    ypos--;
                else if(xp)    xpos++;
                else    xpos--;
            } else if(c == 'L') {
                if(xp) {
                    xp = false;
                    yp = true;
                } else if(xn) {
                    xn = false;
                    yn = true;
                } else if(yp) {
                    yp = false;
                    xn = true;
                } else {
                    yn = false;
                    xp = true;
                }
            } else {
                if(xp) {
                    xp = false;
                    yn = true;
                } else if(xn) {
                    xn = false;
                    yp = true;
                } else if(yp) {
                    yp = false;
                    xp = true;
                } else {
                    yn = false;
                    xn = true;
                }
            }
        }
        if(yp and (xpos or ypos))   return false;
        return true;
    }
};
