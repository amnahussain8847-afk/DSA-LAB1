#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> findPattern(const string& text, const string& pattern) {
    vector<int> indices;
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {         
           j++;
        }
        if (j == m) {
            indices.push_back(i);
        }
    }
    return indices;
}
int main() {
    string text = "JSSJWIQB";
    string pattern = " ";
    vector<int> result = findPattern(text, pattern);
    cout << "Pattern found at indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}