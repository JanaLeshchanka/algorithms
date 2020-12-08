#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <deque>

using namespace std;

bool canBeEuler(int** l, int n)
{
    for(int i = 0; i < n; i++)
    {
        int sumi = 0;
        int sumj = 0;
        for(int j = 0; j < n; j++)
        {
            sumi += l[i][j];
            sumj += l[j][i];
        }
        if(sumi != sumj)
        {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<string> word(n, "");
    deque<string> dq;
    vector<deque<string>> vdq(26, dq);
    vector<vector<deque<string>>> words(26, vdq);
    for(int i = 0; i < n; i++)
    {
        cin >> word[i];
    }
    int** graph = new int*[26];
    for(int i = 0; i < 26; i++)
    {
        graph[i] = new int[26];
        for(int j = 0; j < 26; j++)
            graph[i][j] = 0;
    }
    for(int i = 0; i < n; i++)
    {

        int a = (int)word.at(i).at(0) - 97;
        int b = (int)word.at(i).at(word.at(i).length() - 1) - 97;
        words[a][b].push_back(word[i]);
        graph[a][b]++;
    }

    if(!canBeEuler(graph, 26))
    {
        cout << "No";
        return 0;
    }

    vector<int> res;
    stack<char> s;
    s.push(word[0][0]);
    vector<string> final;
    while(!s.empty()) {
        int w = (int)s.top() - 97;
        bool isRib = false;
        for(int i = 0; i < 26; i++)
        {
            if(graph[w][i] != 0)
            {
                s.push((char)(i + 97));
                graph[w][i]--;
                isRib = true;
                break;
            }
        }
        if(!isRib)
        {
            s.pop();
            res.push_back(w);
            if(res.size() > 1)
            {
                deque<string>::iterator it = words[*(res.end() - 1)][*(res.end() - 2)].end() - 1;
                final.push_back(*it);
                words[*(res.end() - 1)][*(res.end() - 2)].erase(it);
            }
        }
    }

    if(final.at(n - 1).at(0) != final[0][final[0].size() - 1])
    {
        cout << "No";
        return 0;
    }

    cout << "Yes" << endl;
    for(int i = final.size() - 1; i >= 0; i--)
    {
        cout << final.at(i);
        if(i != 0)
            cout << endl;
    }

    return 0;
}