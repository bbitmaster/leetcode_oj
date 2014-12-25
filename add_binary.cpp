//Author: Ben Goodrich
//
//From:
// https://oj.leetcode.com/problems/add-binary/
//Problem:
// Given two binary strings, return their sum (also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100". 


#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string result;

        int max_length = a.length() < b.length() ? b.length() : a.length();
        
        int carry = 0;
        for(int i = 0;i < max_length;i++){
            //calculate offset into a
            int a_offset = a.length() - i - 1;
            int b_offset = b.length() - i - 1;
            int a_chr = 0;
            int b_chr = 0;
            if(a_offset >= 0)
                a_chr = a[a_offset] - '0';
            if(b_offset >= 0)
                b_chr = b[b_offset] - '0';
            
            //single digit adder with carry
            int res = a_chr + b_chr + carry;

            if(res > 1){
                carry = 1;
                res -= 2;
            } else {
                carry = 0;
            }

            result.insert(0,1,res + '0');
        }
        if(carry > 0)
            result.insert(0,1,carry + '0');
        
        return result;    
    }
};

int main(int argc,char *argv[]){
    Solution s;
    cout << "11    +   1 = " << s.addBinary("11","1") << endl;
    cout << "1100 + 0011 = " << s.addBinary("1100","0011") << endl;
    cout << "10   + 0110 = " << s.addBinary("10","0110") << endl;
    cout << "1111 + 1111 = " << s.addBinary("1111","1111") << endl;
    cout << "1101 + 1111 = " << s.addBinary("1101","1111") << endl;
    cout        << "1111111110111 + 11111111111 = " 
    << s.addBinary("1111111110111","11111111111") << endl;
    return 0;
}

