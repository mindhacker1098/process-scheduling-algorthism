#include<iostream>
#include<queue>
#include<math.h>
#include<fstream>
using namespace std;
void title()
{
    cout << "process No";
    cout << "\t";
    cout << "arrival time";
    cout << "\t";
    cout << "brust time";
    cout << "\t\t";
    cout << "completion time";
    cout << "\t\t";
    cout << "turnaround time";
    cout << "\t\t";
    cout << "waiting time" << endl;
}

int main(){std::ofstream myFile("ducky.csv");
myFile<<"name,turn around,waiting time\n";
    int i=0,j,store,n,com;
    float aw[12],at[12];
cout<<"enter no of process"<<endl;
cin>>n;
int p_a[n],a_t[n],b_t[n],c_t[n],t_t[n],w_t[n],b_t1[n];
float avg_t,avg_w;
queue<int> q;
int s,damn;

  for (i; i < n; i++)
    {
        p_a[i] = i + 1;
        

        cout << "enter arival time for no " << i + 1 << " proces" << endl;
        cin >> a_t[i];
        
        cout << "enter brust time for no " << i + 1 << " proces" << endl;
        cin >> b_t[i];
    
        b_t1[i]=b_t[i];
        
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
                store = b_t1[i];
                b_t1[i] = b_t1[j];
                b_t1[j] = store;
                store = p_a[i];
                p_a[i] = p_a[j];
                p_a[j] = store;
                
               

            }
        }
    }
    for (damn=1;damn<=10;damn++)
    {
       for (i=0;i<n;i++)
       {
        b_t[i]=b_t1[i];
       }
        
    
    com=0;
    avg_t=0;
    avg_w=0;
    i = 0;
    while (1)
    {
        if (a_t[i] <= com || q.size()>0)
        {
          for(;i<=com && i<n;i++){
              q.push(i);
          }
          
        }
        else
        {
            com = a_t[i];
            continue;
        }
        s=q.front();
        q.pop();
        if(b_t[s]>=damn){


            com+=damn;
            b_t[s]=b_t[s]-damn;
        }
        else{
            com+=b_t[s];
            b_t[s]=0;
        }
        if(b_t[s]==0){
            c_t[s]=com;
             t_t[s] = c_t[s] - a_t[s];
        avg_t += float(t_t[s]) / n;
        w_t[s] = t_t[s] - b_t1[s];
        avg_w += float(w_t[s]) / n;

        }
        else{
            for (;a_t[i]<=com && i<n ;i++)
            {
            q.push(i);
            }
            if (b_t[s]!=0)
            {
                q.push(s);
            }
            
        }
        if(q.empty()&&i>=n){break;}
    }
    aw[damn]=avg_w;
    at[damn]=avg_t;
     cout << "round robin in time quantum "<<damn<< endl;
            title();
            for (s = 0; s < n; s++)
            {
                cout << p_a[s];
                cout << "\t\t";
                cout << a_t[s];
                cout << "\t\t";
                cout << b_t1[s];
                cout << "\t\t\t";
                cout << c_t[s];
                cout << "\t\t\t";
                cout << t_t[s];
                cout << "\t\t\t";
                cout << w_t[s] << endl;
                if (s == n - 1)
                {
                    cout << "average turnaround time = " << avg_t << endl;
                    cout << "average waiting time = " << avg_w<< endl
                    

                         << endl;
                    cout << endl;}}}                    myFile<<"1,"<<at[1]<<","<<aw[1]<<"\n";
     myFile<<"2,"<<at[2]<<","<<aw[2]<<"\n";
     myFile<<"3,"<<at[3]<<","<<aw[3]<<"\n";
     myFile<<"4,"<<at[4]<<","<<aw[4]<<"\n";
     myFile<<"5,"<<at[5]<<","<<aw[5]<<"\n";
     myFile<<"6,"<<at[6]<<","<<aw[6]<<"\n";
     myFile<<"7,"<<at[7]<<","<<aw[7]<<"\n";
     myFile<<"8,"<<at[8]<<","<<aw[8]<<"\n";
     myFile<<"9,"<<at[9]<<","<<aw[9]<<"\n";
     myFile<<"10,"<<at[10]<<","<<aw[10]<<"\n";
     
     
     
return 0;
}
