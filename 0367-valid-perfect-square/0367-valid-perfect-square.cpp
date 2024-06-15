class Solution {
public:
    bool isPerfectSquare(int num) {
        int root = sqrt(num);
        int temp = root;
        return(temp*temp==num) ? true : false;
    }
};