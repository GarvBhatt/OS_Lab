#include <bits/stdc++.h>

using namespace std;

struct data
{
    int pid;
    int bt;
    int at;
    int wt;
    int tat;
};

bool cmp(data x, data y)
{
    return (x.bt < y.bt);
}

int main()
{
    data row[20];
    int n;
    float wtavg, tatavg;

    cout << "Enter the number of processes" << "\n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        row[i].pid = i;
        cout << "Enter arrival time" << "\n";
        cin >> row[i].at;
        cout << "Enter burst time " << "\n";
        cin >> row[i].bt;
    }

    sort(row, row + n, cmp);

    row[0].wt = 0;
    row[0].tat = row[0].bt;

    for (int i = 1; i < n; i++)
    {
        row[i].wt = row[i - 1].wt + row[i - 1].bt;
        row[i].tat = row[i - 1].tat + row[i].bt;
    }

    for (int i = 0; i < n; i++)
    {
        cout << row[i].pid << " " << row[i].bt << " " << row[i].wt << " " << row[i].tat << "\n";
    }

    return 0;
}