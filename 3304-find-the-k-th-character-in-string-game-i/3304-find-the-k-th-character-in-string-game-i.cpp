class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + _builtin_popcount(k-1);
    }
};