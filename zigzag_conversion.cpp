// Author: Ben Goodrich
// Link:
// https://oj.leetcode.com/problems/zigzag-conversion/
// Description:
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
// of rows like this:
// (you may want to display this pattern in a fixed font for better legibility)
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
// string convert(string text, int nRows);
//
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int DOWN = 0;
const int UP = 1;

string convert(string text,int nRows){
    vector<string> row;
    for(int i = 0;i < nRows;i++){
        row.push_back("");
    }

    int direction = DOWN;
    int rowcount = 0;
    for(int count = 0;count < text.length();count++){
        row[rowcount].push_back(text[count]);
        switch(direction){
            case DOWN :
                rowcount++;
                if(rowcount >= nRows-1)
                    direction = UP;
                break;
            case UP :
                rowcount--;
                if(rowcount <= 0)
                    direction = DOWN;
                break;
        }
    }

    string result = "";
    for(int count = 0;count < nRows;count++){
        result.append(row[count]);
    }
    return result;
}

int main(int argc,char *argv[]){
    cout << "PAYPALISHIRING, 2 : " << convert("PAYPALISHIRING",2) << endl;
    cout << "PAYPALISHIRING, 3 : " << convert("PAYPALISHIRING",3) << endl;
    cout << "PAYPALISHIRING, 4 : " << convert("PAYPALISHIRING",4) << endl;
    cout << "PAYPALISHIRING, 5 : " << convert("PAYPALISHIRING",5) << endl;
    cout << "PAYPALISHIRING, 6 : " << convert("PAYPALISHIRING",6) << endl;
    return 0;
}
