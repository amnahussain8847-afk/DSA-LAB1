#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generatePascal(int n) {
    vector<vector<int>> triangle;
    for (int i = 0; i < n; i++) {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}
void printTriangle(const vector<vector<int>>& triangle) {
    for (const vector<int>& row : triangle) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}
int main() {
    // Test Case 1: n = 0
    cout << "Test Case 1: n = 0" << endl;
    vector<vector<int>> result0 = generatePascal(0);
    printTriangle(result0);
    cout << endl;
    // Test Case 2: n = 1
    cout << "Test Case 2: n = 1" << endl;
    vector<vector<int>> result1 = generatePascal(1);
    printTriangle(result1);
    cout << endl;
    // Test Case 3: n = 5
    cout << "Test Case 3: n = 5" << endl;
    vector<vector<int>> result5 = generatePascal(5);
    printTriangle(result5);
    cout << endl;
    // Verify row5
    cout << "Row 5: ";
    if (result5.size() >= 5) {
        for (int value : result5[4]) {
            cout << value << " ";
        }
    }
    cout << endl;
    return 0;
}