//fcfs starting
#include <iostream>
using namespace std;
int i;
void title()
{
    cout << "process No";
    cout << "\t";
    cout << "arrival time";
    cout << "\t";
    cout << "brust time";
    cout << "\t\t";
    if (i == 2)
    {
        cout << "priority";
        cout << "\t\t";
    }
    cout << "completion time";
    cout << "\t\t";
    cout << "turnaround time";
    cout << "\t\t";
    cout << "waiting time" << endl;
}
int main()
{
    int n, store, j, com = 0, i_d, k, small, big, s;
    i = 0;
    float avg_t = 0, avg_w = 0;
    float sjf_avg_t = 0, sjf_avg_w = 0, pri_avg_t = 0, pri_avg_w = 0;
    cout << "Enter no of process" << endl;
    cin >> n;
    int p_a[n];
    int a_t[n];
    int b_t[n];
    int c_t[n];
    int t_t[n];
    int w_t[n];
    int sjf_[n];
    int sjf_tt[n];
    int sjf_wt[n];
    int sjf_ct[n];
    int store_id[n];
    int p_i[n];
    int pri_ct[n];
    int pri_wt[n];
    int pri_tt[n];
    for (i; i < n; i++)
    {
        p_a[i] = i + 1;
        cout << "enter arival time for no " << i + 1 << " proces" << endl;
        cin >> a_t[i];
        cout << "enter brust time for no " << i + 1 << " proces" << endl;
        cin >> b_t[i];
        cout << "enter proirity for no " << i + 1 << " proces " << endl;
        cin >> p_i[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a_t[i] > a_t[j])
            {
                store = a_t[i];
                a_t[i] = a_t[j];
                a_t[j] = store;
                store = b_t[i];
                b_t[i] = b_t[j];
                b_t[j] = store;
                store = p_a[i];
                p_a[i] = p_a[j];
                p_a[j] = store;
                store = p_i[i];
                p_i[i] = p_i[j];
                p_i[j] = store;
            }
        }
    }
    i = 0;
    while (i < n)
    {
        if (a_t[i] <= com)
        {
            com += b_t[i];
            c_t[i] = com;
            t_t[i] = c_t[i] - a_t[i];
            avg_t += float(t_t[i]) / n;
            w_t[i] = t_t[i] - b_t[i];
            avg_w += float(w_t[i]) / n;
        }
        else
        {
            com = a_t[i];
            continue;
        }
        i++;
    }

    //shortest job first starting....
    com = 0;
    i = 0;
    store = 0;
    while (i < n)
    {
        if (a_t[i] <= com)
        {
            j = i, store = 0;
            while (a_t[j] <= com && j < n)
            {
                if (a_t[j] <= com)
                {
                    store += 1;

                    j++;
                }
            }
        }
        else
        {
            com = a_t[i];
            continue;
        }
        if (store == 1)
        {
            com += b_t[i];
            sjf_ct[i] = com;
        }
        else
        {
            k = i, small = b_t[i];
            i_d = k;
            for (k = i; k < j; k++)
            {
                if (b_t[k] < small)
                {
                    small = b_t[k];
                    i_d = k;
                }
            }
            com += b_t[i_d];
            sjf_ct[i] = com;
            store = a_t[i];
            a_t[i] = a_t[i_d];
            a_t[i_d] = store;
            store = b_t[i];
            b_t[i] = b_t[i_d];
            b_t[i_d] = store;
            store = p_a[i];
            p_a[i] = p_a[i_d];
            p_a[i_d] = store;
            store = p_i[i];
            p_i[i] = p_i[i_d];
            p_i[i_d] = store;

            store = c_t[i];
            c_t[i] = c_t[i_d];
            c_t[i_d] = store;
            store = t_t[i];
            t_t[i] = t_t[i_d];
            t_t[i_d] = store;
            store = w_t[i];
            w_t[i] = w_t[i_d];
            w_t[i_d] = store;
           
        }

        sjf_tt[i] = sjf_ct[i] - a_t[i];
        sjf_avg_t += float(sjf_tt[i]) / n;
        sjf_wt[i] = sjf_tt[i] - b_t[i];
        sjf_avg_w += float(sjf_wt[i]) / n;

        i++;
    }

    //priority starting....
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a_t[i] > a_t[j])
            {
                store = a_t[i];
                a_t[i] = a_t[j];
                a_t[j] = store;
                store = b_t[i];
                b_t[i] = b_t[j];
                b_t[j] = store;
                store = p_a[i];
                p_a[i] = p_a[j];
                p_a[j] = store;
                store = t_t[i];
                t_t[i] = t_t[j];
                t_t[j] = store;
                store = c_t[i];
                c_t[i] = c_t[j];
                c_t[j] = store;
                store = w_t[i];
                w_t[i] = w_t[j];
                w_t[j] = store;
                store = p_i[i];
                p_i[i] = p_i[j];
                p_i[j] = store;
                store = sjf_ct[i];
                sjf_ct[i] = sjf_ct[j];
                sjf_ct[j] = store;
                store = sjf_tt[i];
                sjf_tt[i] = sjf_tt[j];
                sjf_tt[j] = store;
                store = sjf_wt[i];
                sjf_wt[i] = sjf_wt[j];
                sjf_wt[j] = store;
            }
        }
    }
    com = 0;
    i = 0;
    store = 0;
    while (i < n)
    {
        if (a_t[i] <= com)
        {
            j = i, store = 0;
            while (a_t[j] <= com && j < n)
            {
                if (a_t[j] <= com)
                {
                    store += 1;

                    j++;
                }
            }
        }
        else
        {
            com = a_t[i];
            continue;
        }
        if (store == 1)
        {
            com += b_t[i];
            pri_ct[i] = com;
        }
        else
        {
            k = i, big = p_i[i];
            i_d = k;
            for (k = i; k < j; k++)
            {
                if (p_i[k] > big)
                {
                    big = p_i[k];
                    i_d = k;
                }
            }
            com += b_t[i_d];
            pri_ct[i] = com;
            store = a_t[i];
            a_t[i] = a_t[i_d];
            a_t[i_d] = store;
            store = b_t[i];
            b_t[i] = b_t[i_d];
            b_t[i_d] = store;
            store = p_a[i];
            p_a[i] = p_a[i_d];
            p_a[i_d] = store;
            store = p_i[i];
            p_i[i] = p_i[i_d];
            p_i[i_d] = store;

            store = c_t[i];
            c_t[i] = c_t[i_d];
            c_t[i_d] = store;
            store = t_t[i];
            t_t[i] = t_t[i_d];
            t_t[i_d] = store;
            store = w_t[i];
            w_t[i] = w_t[i_d];
            w_t[i_d] = store;
            store = sjf_ct[i];
            sjf_ct[i] = sjf_ct[i_d];
            sjf_ct[i_d] = store;
            store = sjf_tt[i];
            sjf_tt[i] = sjf_tt[i_d];
            sjf_tt[i_d] = store;
            store = sjf_wt[i];
            sjf_wt[i] = sjf_wt[i_d];
            sjf_wt[i_d] = store;

          
        }

        pri_tt[i] = pri_ct[i] - a_t[i];
        pri_avg_t += float(pri_tt[i]) / n;
        pri_wt[i] = pri_tt[i] - b_t[i];
        pri_avg_w += float(pri_wt[i]) / n;

        i++;
    }

    for (i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            cout << "first come first serve algorithm" << endl;
            title();
            for (s = 0; s < n; s++)
            {
                cout << p_a[s];
                cout << "\t\t";
                cout << a_t[s];
                cout << "\t\t";
                cout << b_t[s];
                cout << "\t\t\t";
                cout << c_t[s];
                cout << "\t\t\t";
                cout << t_t[s];
                cout << "\t\t\t";
                cout << w_t[s] << endl;
                if (s == n - 1)
                {
                    cout << "average turnaround time = " << avg_t << endl;
                    cout << "average waiting time = " << avg_w << endl
                         << endl;
                    cout << endl;
                }
            }
        }
        else if (i == 1)
        {
            cout << "shortest job first algorithm" << endl;
            title();
            for (s = 0; s < n; s++)
            {
                cout << p_a[s];
                cout << "\t\t";
                cout << a_t[s];
                cout << "\t\t";
                cout << b_t[s];
                cout << "\t\t\t";
                cout << sjf_ct[s];
                cout << "\t\t\t";
                cout << sjf_tt[s];
                cout << "\t\t\t";
                cout << sjf_wt[s] << endl;
                if (s == n - 1)
                {
                    cout << "average turnaround time = " << sjf_avg_t << endl;
                    cout << "average waiting time = " << sjf_avg_w << endl
                         << endl;
                    cout << endl;
                }
            }
        }
        else if (i == 2)
        {
            cout << "priority scheduling algorithm" << endl;
            title();
            for (s = 0; s < n; s++)
            {
                cout << p_a[s];
                cout << "\t\t";
                cout << a_t[s];
                cout << "\t\t";
                cout << b_t[s];
                cout << "\t\t\t";
                cout << p_i[s];
                cout << "\t\t\t";
                cout << pri_ct[s];
                cout << "\t\t\t";
                cout << pri_tt[s];
                cout << "\t\t\t";
                cout << pri_wt[s] << endl;
                if (s == n - 1)
                {
                    cout << "average turnaround time = " << pri_avg_t << endl;
                    cout << "average waiting time = " << pri_avg_w << endl
                         << endl;
                    cout << endl;
                }
            }
        }
    }

    return 0;
}
