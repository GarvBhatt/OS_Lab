#include <bits/stdc++.h>

using namespace std;

class FCFS
{
public:
    void ct_t(int ct[], int bt[], int n)
    {
        ct[0] = bt[0];
        for (int i = 1; i < n; i++)
        {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    void tat_t(int ct[], int at[], int tat[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            tat[i] = ct[i] - at[i];
        }
    }

    void wt_t(int bt[], int tat[], int wt[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            wt[i] = tat[i] - bt[i];
        }
    }
};

int main()
{
    int n = 5;
    float awtm = 0.0;
    int bt[] = {4, 3, 1, 2, 5}, ct[n], tat[n], wt[n], at[n] = {0, 1, 2, 3, 4};

    FCFS O_0;
    O_0.ct_t(ct, bt, n);
    O_0.tat_t(ct, at, tat, n);
    O_0.wt_t(bt, tat, wt, n);

    cout << "ID"<< "|"<< "Arrival"<< "|"<< "Burst"<< "|"<< "completion"<< "|"<< "turnaround"<< "|"<< "waiting" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i << " |";
        cout << setw(2) << setfill('0') << at[i] << "     |";
        cout << setw(2) << setfill('0') << bt[i] << "   |";
        cout << setw(2) << setfill('0') << ct[i] << "        |";
        cout << setw(2) << setfill('0') << tat[i] << "        |";
        cout << setw(2) << setfill('0') << wt[i] << endl;
    }

    for (int i = 0; i < n; i++)
    {
        awtm = awtm + wt[i];
    }

    cout <<"\naverage waiting time = " << awtm / n;

    return 0;
}