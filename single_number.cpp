// Author: Ben Goodrich
// Link:
// https://oj.leetcode.com/problems/single-number/
// Description:
// Given an array of integers, every element appears twice
// except for one. Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity.
// Could you implement it without using extra memory? 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
    int singleNumber(int A[],int n){
        int c = 0;
        for(int i = 0;i < n;i++){
            c = c ^ A[i];
        }
        return c;
    }
};

int main(int argc,char *argv[]){
    Solution s;
    int A[] = {1,1,2,2,3,3,4,4,5,6,6};
    cout << "11223344566: " << to_string(s.singleNumber(A,11)) << endl;
    int B[] = {-1,-1,2,2,-3,-3,4,4,-5,6,6};
    cout << "-1-122-3-344-566: " << to_string(s.singleNumber(B,11)) << endl;
    return 0;
}
