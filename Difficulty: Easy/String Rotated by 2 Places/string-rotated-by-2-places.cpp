class Solution {
  public:
    // Clockwise rotation by 1
    void rotateClock(string& s){
        char c = s[s.size() - 1];
        int i = s.size() - 2;

        while (i >= 0) {
            s[i + 1] = s[i];
            i--;
        }
        s[0] = c;
    }

    // Anticlockwise rotation by 1
    void antiClock(string& s){
        char c = s[0];
        int i = 1;

        while (i < s.length()) {
            s[i - 1] = s[i];
            i++;
        }
        s[s.size() - 1] = c;
    }

    // Check if s2 is a rotation of s1 by exactly 2 places
    bool isRotated(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.size() <= 2) return s1 == s2;
        if (s1 == s2) return false;

        string clw = s1, aclw = s1;

        rotateClock(clw);
        rotateClock(clw);

        antiClock(aclw);
        antiClock(aclw);

        return (clw == s2 || aclw == s2);
    }
};

