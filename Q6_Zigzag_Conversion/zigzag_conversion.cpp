#include <iostream>
using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            // use a flag to indicate that whether we are currently going down
            bool down_flag = true;
            int counter = 0;
            // consider special situation where there is only one row
            if (numRows == 1) {
                return s;
            }

            // create an array of strings, each represents a line
            string * arr = new string [numRows];

            for (int i = 0; i != s.size(); i++) {
                // if we goes down
                if (down_flag) {
                    (arr + counter)->append(s.substr(i, 1));
                    counter++;

                    // if the we reach the numRows, then we start going up
                    if (counter == numRows) {
                        down_flag = !down_flag;
                        counter -= 2; 
                    }
                }
                // if we goes up
                else {
                    (arr + counter)->append(s.substr(i, 1));

                    if (counter == 0) {
                        down_flag = !down_flag;
                        counter ++;
                    }
                    else {
                        counter --;
                    }
                }
            }

            string result;
            for (int i = 0; i < numRows; i++) {
                result.append(*(arr + i));
            }
            delete [] arr;
            return result;
        }
}sol;


int main() {
    string a = "PAYPALISHIRING";
    string answer = sol.convert(a, 4);
    cout<< answer << endl;
}