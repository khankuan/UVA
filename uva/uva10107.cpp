#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<long> arr;
    long input;
    while(cin >> input){
        arr.push_back(input);
        long output;
        std:sort(arr.begin(),arr.end());
        //nth_element (arr.begin(), arr.begin()+arr.size()/2+2, arr.end());
        if (arr.size() % 2 == 1)
            output = arr[arr.size()/2];
        else
            output = (arr[arr.size()/2] + arr[arr.size()/2-1])/2;
        

        cout << output << endl;
    }
    
    return 0;
}
