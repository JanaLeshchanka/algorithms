#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int* t;
int n;

int sum (int l, int r)
{
    long long result = 0;
    while(r > 0)
    {
        result += t[r];
        r = (r & (r + 1)) - 1;
    }
    while(l > 0)
    {
        result -= t[l];
        l = (l & (l + 1)) - 1;
    }
    return result;
}

void inc (int i)
{
    for (; i <= 2 * n; i = i | (i + 1))
    {
        t[i]++;
    }
}

int main() {
    freopen("chords.in", "r", stdin);
    freopen("chords.out", "w", stdout);
    cin >> n;
    t = new int[2 * n + 1];
    for (int i = 1; i <= 2 *n; i++)
        t[i] = 0;
    int** chords = new int*[n];
    for(int i = 0; i < n; i++) {
        chords[i] = new int[2];
        cin >> chords[i][0] >> chords[i][1];
    }
    // создаём три массива размерности 2n + 1:
    // в одном хранятся левые концы отрезков,
    // причём их индексы соответствуют их правым концам
    int* right = new int[2 * n + 1];
    for(int i = 0; i < 2 * n + 1; i++)
        right[i] = 0;
    // происходит заполнение
    for(int i = 0; i < n; i++)
    {
        if(chords[i][0] < chords[i][1])
        {
            right[chords[i][0]] = chords[i][1];
        }
        else
        {
            right[chords[i][1]] = chords[i][0];
        }
    }

    long long chordCounter = 0;
    for(int i = 1; i <= 2 * n; i++) {
        if(right[i] != 0 && i != right[i] - 1)
        {
            inc(right[i]);
            chordCounter += sum(i, right[i] - 1);
        }
    }

    cout << abs(chordCounter);
    return 0;
}