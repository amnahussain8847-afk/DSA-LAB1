#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> findMode(const vector<int>& arr) {
    vector<int> modes;
    if (arr.empty()) {
        return modes;
    }
    unordered_map<int, int> frequency;
    for (int value : arr) {
        frequency[value]++;
    }
    int maxFrequency = 0;
    for (const auto& pair : frequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
        }
    }
    for (const auto& pair : frequency) {
        if (pair.second == maxFrequency) {
            modes.push_back(pair.first);
        }
    }
    return modes;
}
void printModes(const vector<int>& modes) {
    if (modes.empty()) {
        cout << "No mode (empty array)" << endl;
        return;
    }
    cout << "Mode(s): ";
    for (int mode : modes) {
        cout << mode << " ";
    }
    cout << endl;
}
int main() {
    // Test Case 1: Unique mode
    vector<int> arr1 = {2, 4, 2, 7, 2, 4};
    cout << "Test Case 1: Unique mode" << endl;
    printModes(findMode(arr1));
    cout << endl;
    // Test Case 2: Multiple modes
    vector<int> arr2 = {1, 2, 1, 2, 3, 3};
    cout << "Test Case 2: Multiple modes" << endl;
    printModes(findMode(arr2));
    cout << endl;
    // Test Case 3: Empty array
    vector<int> arr3 = {};
    cout << "Test Case 3: Empty array" << endl;
    printModes(findMode(arr3));
    return 0;
}