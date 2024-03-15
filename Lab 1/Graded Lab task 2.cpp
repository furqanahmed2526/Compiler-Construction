#include <iostream>
#include <vector>

using namespace std;

void displayDataGridView(const vector<vector<string>>& data) {
    // Display column headers
    cout << "Data Grid View" << endl;
    cout << "-------------------------" << endl;
    cout << "Column1\tColumn2" << endl;
    cout << "-------------------------" << endl;

    // Display data
    for (const auto& row : data) {
        for (const auto& cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }
}

int main() {
    // Vector to hold data
    vector<vector<string>> dataGridView;

    // Insert values into DataGridView at runtime
    dataGridView.push_back({ "Value 1", "Value 2" });
    dataGridView.push_back({ "Value 3", "Value 4" });

    // Display DataGridView
    displayDataGridView(dataGridView);

    return 0;
}

