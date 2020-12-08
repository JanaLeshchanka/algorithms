#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int findSum(int** mat, int n, int j) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += mat[j][i];
    }
    return sum;
}

void trip(int** graphMat, int n) {

    int** paths = new int*[n];
    for(int i = 0; i < n; i++)
        paths[i] = new int[n];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            paths[i][j] = 0;
        }
    }
    int** fromWhere = new int*[n];
    for(int i = 0; i < n; i++)
    {
        fromWhere[i] = new int[n];
        for(int j = 0; j < n; j++)
            fromWhere[i][j] = -1;
    }

    paths[n - 1][n - 1] = 1;
       for(int i = n - 2; i >= 0; i--) {
           for(int j = n - 1; j >= i; j--) {
               if(i != j || i == 0) {
                   for(int k = n - 1; k > i; k--) {
                       if(graphMat[k][i] == 1) {
                           if ((k != j || j == n - 1) && paths[j][k] != 0 && paths[j][k]+ 1 > paths[i][j]) {
                               paths[j][i] = paths[i][j] = paths[k][j] + 1;
                           }
                       }
                   }
               }

           }
       }
       if(paths[0][0] == 0)
       {
           cout << "No solution";
           return;
       }
       cout << --paths[0][0];
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    pair<string, int> p;
    map<string, int> nodes; // в map каждому городу присваивается номер
    string temp;
    int n;
    int m;
    cin >> n >> m;
    int** graphMat = new int*[n];
    for(int i = 0; i < n; i++)
        graphMat[i] = new int[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            graphMat[i][j] = 0;
    for(int i = 0; i < n; i++) {
        cin >> p.first;
        p.second = i;
        nodes.insert(p);
    }
    for(int i = 0; i < m; i++) {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        int j = nodes.at(temp1);
        int k = nodes.at(temp2);
        graphMat[j][k] = 1;
        graphMat[k][j] = 1;
    }

    int sumFirst = 0;
    for(int i = 0; i < n; i++) {
        sumFirst += graphMat[0][i];
    }

    if(sumFirst < 2 && graphMat[0][n - 1] != 1) { // проверка: если городов больше двух, то если из первого города
        // можно попасть только в один, и он не последний,
        // то в этот город придётся ехать дважды
        cout << "No solution";
        return 0;
    }

    for(int i = n - 1; i >= 0; i--)
    {
        if(findSum(graphMat, n, i) == 0)
        {
            n--;
        }
    }

    int sumLast = 0;
    for(int i = 0; i < n; i++) {
        sumLast += graphMat[n - 1][i];
    }

    if(sumLast == 1 && graphMat[n - 1][0] == 0)
    {
        cout << "No solution";
        return 0;
    }
    trip(graphMat, n);
    return 0;
}
