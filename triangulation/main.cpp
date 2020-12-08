#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double findLength(int** node, int i, int k, int n) {
    if(i == k || abs(i - k) == 1 || abs(i - k) == n - 1) {
        return 0.00;
    }
    return sqrt(pow(node[i][0] - node[k][0], 2) + pow(node[i][1] - node[k][1], 2));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    if(n <= 3) {
        cout << 0.00;
        return 0;
    }
    int** coord = new int* [n];
    for(int i = 0; i < n; i++)
        coord[i] = new int[2];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++)
            cin >> coord[i][j];
    }

    double** lengths = new double*[n];
    for(int i = 0; i < n; i++)
        lengths[i] =  new double[n];
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            lengths[i][j] = findLength(coord, i, j, n);
            lengths[j][i] = lengths[i][j];
        }
    }
    if(n == 4) {
        double res =  lengths[0][2] < lengths[1][3] ? lengths[0][2] : lengths[1][3];
        cout << setprecision(2) << fixed << res;
        return 0;
    }

    double** sums = new double*[n];
    for(int i = 0; i < n; i++)
        sums[i] = new double[n - 3];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 3; j++) {
            sums[i][j] = 0;
        }
    }

    for(int s = 4; s <= n; s++) {
        for(int i = n - 1; i >= 0; i--) {
            double* kArr = new double[s - 2];
            for(int k = 1; k < s - 1; k++)
                kArr[k - 1] = 0;
            int j = 0;
            for(int k = 1; k < s - 1; k++) {
                if(k > 2) {
                    kArr[j] += sums[i][k - 3];
                }
                if(s - k > 3) {
                    kArr[j] += sums[(i + k) % n][s - k - 4];
                }
                kArr[j] += lengths[i][(i + k) % n];
                kArr[j] += lengths[(i + k) % n][(s + i - 1) % n];
                j++;
            }

            double min = kArr[0];
            for(int k = 1; k < s - 2; k++) {
                if(min > kArr[k] && kArr[k] != 0) {
                    min = kArr[k];
                }
            }
            sums[i][s - 4] = min;
            delete[] kArr;
        }
    }
    double min = sums[0][n - 4];
    for(int i = 1; i < n; i++) {
        if(sums[i][n - 4] < min)
            min = sums[i][n - 4];
    }

    cout << setprecision(2) << fixed << min;

    for(int i = 0; i < n; i++)
        delete coord[i];
    delete[] coord;
    for(int i = 0; i < n; i++)
        delete lengths[i];
    delete[] lengths;
    return 0;
}