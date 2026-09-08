#include <iostream>
#include <vector>
using namespace std;
vector<int> findAllIndices(const vector<int>& arr, int key) {
    vector<int> indices;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }
    return indices;
}
int main() {
    vector<int> arr = {};
    int key = 100;
    vector<int> result = findAllIndices(arr, key);
    cout << "Indices: ";

    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}