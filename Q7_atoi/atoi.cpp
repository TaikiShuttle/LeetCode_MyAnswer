#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        vector<int> arr;
        // cout << arr.size() << endl;
        bool is_empty = true;
        bool is_negative = false;
        bool finish_read = false;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if(finish_read) {
                    break;
                }
                continue;
            }

            // should be +, - or numerical value, otherwise return 0
            if (s[i] == '-') {
                if (finish_read) {
                    break;
                }
                is_negative = true;
                finish_read = true;
                continue;
            }
            else if (s[i] == '+'){
                if (finish_read) {
                    break;
                }
                is_negative = false;
                finish_read = true;
                continue;
            }
            else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '.' || s[i] == '\n') {
                break;
            }
            else {
                finish_read = true;
                is_empty = false;
                arr.push_back(s[i] - '0');
            }
        }


        int sum = 0;
        for (int j = 0; j < arr.size(); j++) {
            if(sum > INT32_MAX / 10 && !is_negative) {
                return INT32_MAX;
            }
            else if (sum > INT32_MAX / 10 && is_negative) {
                return INT32_MIN;
            }
            else if (sum == INT32_MAX / 10 && arr[j] >= 7 && !is_negative) {
                return INT32_MAX;
            }
            else if (sum == INT32_MAX / 10 && arr[j] >= 8 && is_negative) {
                return INT32_MIN;
            }
            else{
                sum = sum * 10 + arr[j];
            }

        }


        if (is_negative) {
            return -sum;
        }
        else {
            return sum;
        }
    }
} sol;

int main() {
    string s;
    cin >> s;
    cout << sol.myAtoi(s) << endl;
}
