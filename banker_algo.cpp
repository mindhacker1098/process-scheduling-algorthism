#include<iostream>
#include<queue>
using namespace std;
int main(){int A,B,C,n,i,a=0,b=0,c=0,av_a,av_b,av_c,damn=0,j=0;
cout<<"enter no of avalable A resourse"<<endl;
cin>>A;
cout<<"enter no of avalable B resourse "<<endl;
cin>>B;
cout<<"enter no of avalable C resourse "<<endl;
cin>>C;
cout<<"enter no of process"<<endl;
cin>>n;
int A_a[n],B_b[n],C_c[n],p_a[n],m_a[n],m_b[n],m_c[n],r_a[n],r_b[n],r_c[n];
queue<int> safe,store;

for (i=0;i<n;i++)
{
    cout<<"for no "<<i+1<<"process allocate A resourse"<<endl;
    cin>>A_a[i];
    a+=A_a[i];
    cout<<'B'<<endl;
    cin>>B_b[i];
    b+=B_b[i];
    cout<<"C"<<endl;
    cin>>C_c[i];
    c+=C_c[i];
    p_a[i]=i+1;
}
for (i=0;i<n;i++)
{
    cout<<"for no "<<p_a[i]<<"process allocate max need of A resourse "<<endl;
    cin>>m_a[i];
    r_a[i]=m_a[i]-A_a[i];
    cout<<"B"<<endl;
    cin>>m_b[i];
    r_b[i]=m_b[i]-B_b[i];
    cout<<"C"<<endl;
    cin>>m_c[i];
    r_c[i]=m_c[i]-C_c[i];

}
av_a=A-a;
av_b=B-b;
av_c=C-c;
i=0;
while (j<=n*(n+1)/2)
{
    if (av_a>=r_a[i] && av_b>=r_b[i] && av_c>=r_c[i])
    {
        safe.push(i);
        av_a+=A_a[i];
        av_b+=B_b[i];
        av_c+=C_c[i];
        if(safe.size()==n){damn=0;
        break;}
    }
    else{store.push(i);}
    if (damn==0)
    {
        i++;
    }
    if (i==n)
    {
        damn=1;
    }
    if (damn==1)
    {
        i=store.front();
        store.pop();
    }
    



j++;

}
if(damn==0){cout<<"our process is safe and safe sequency is:- ";
for (i=0;i<n;i++)
{
    cout<<p_a[safe.front()];
    if (i<n-1)
    {
        cout<<"-->";
    }
    
    safe.pop();
}
}
else{cout<<"process is not safe";}

return 0;
}
