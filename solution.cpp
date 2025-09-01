#include <iostream>
#include <string>
#include <map>
#include <regex>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long toDecimal(string val, int base) {
    long long num = 0;
    for (char c : val) {
        num = num * base + (c - '0');
    }
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string input, line;
    while (getline(cin, line)) {
        input += line;
    }


    int n, k;
    size_t posN = input.find("\"n\"");
    size_t posK = input.find("\"k\"");
    n = stoi(input.substr(input.find(":", posN) + 1));
    k = stoi(input.substr(input.find(":", posK) + 1));


    map<int, pair<int, string>> data; 
    regex rgx("\"(\\d+)\":\\s*\\{[^}]*\"base\":\\s*\"(\\d+)\"[^}]*\"value\":\\s*\"(\\d+)\"");
    smatch match;
    string s = input;

    while (regex_search(s, match, rgx)) {
        int idx = stoi(match[1]);
        int base = stoi(match[2]);
        string value = match[3];
        data[idx] = {base, value};
        s = match.suffix();
    }

    
    vector<vector<double>> A;
    vector<double> B;

    int count = 0;
    for (auto &p : data) {
        if (count >= k) break;
        int x = p.first;
        long long y = toDecimal(p.second.second, p.second.first);

        vector<double> row;
        for (int j = 0; j < k; j++) {
            row.push_back(pow(x, j));
        }
        A.push_back(row);
        B.push_back(y);
        count++;
    }

    
    int m = k;
    for (int i = 0; i < m; i++) {
        // Pivot
        int pivot = i;
        for (int j = i + 1; j < m; j++) {
            if (fabs(A[j][i]) > fabs(A[pivot][i]))
                pivot = j;
        }
        swap(A[i], A[pivot]);
        swap(B[i], B[pivot]);

        
        double div = A[i][i];
        for (int j = 0; j < m; j++) A[i][j] /= div;
        B[i] /= div;

    
        for (int j = 0; j < m; j++) {
            if (i != j) {
                double factor = A[j][i];
                for (int k2 = 0; k2 < m; k2++)
                    A[j][k2] -= factor * A[i][k2];
                B[j] -= factor * B[i];
            }
        }
    }

    
    cout << "Polynomial coefficients (lowest degree to highest):\n";
    for (double c : B) {
        cout << round(c) << " ";
    }
    cout << "\n";

    return 0;
}
