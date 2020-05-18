#include<bits/stdc++.h>
using namespace std;

struct PCB{
    string pid;
    int atime,cputime,priority,rtime,comptime,tat,wt;
    };
PCB process[100];
vector <string> ready_queue,done_job;
int initial=0,n;
int tme=0,cnt=0;
map <string,int> mp;

void scheduler(int t)
{
    int i;
    for(i=initial;i<n;i++)
    {
        if(process[i].atime<=t)
            ready_queue.push_back(process[i].pid);
        if(process[i].atime>t)
            break;
    }
    initial=i;
}
void np()
{
    if(ready_queue.size()>0)
    {
        cnt++;
        int loc,temp_p=4,ptr;
        string name;
        for(int i=0;i<ready_queue.size();i++)
        {
            ptr=mp[ready_queue[i]];
            if(process[ptr].priority<temp_p)
            {
                temp_p=process[ptr].priority;
                loc=ptr;
                name=ready_queue[i];
            }
        }
        done_job.push_back(name);
        ready_queue.erase(std::find(ready_queue.begin(),ready_queue.end(),name));
        tme+=process[loc].cputime;
        process[loc].comptime=tme;
        process[loc].tat=tme-process[loc].atime;
        process[loc].wt=process[loc].tat-process[loc].cputime;
        cout<<name<<" \t\t"<<process[loc].comptime<<"\n";
    }
    else
        tme++;
}
void p()
{
    if(ready_queue.size()>0)
    {
        int loc,temp_p=4,ptr;
        string name;
        for(int i=0;i<ready_queue.size();i++)
        {
            ptr=mp[ready_queue[i]];
            if(process[ptr].priority<temp_p)
            {
                temp_p=process[ptr].priority;
                loc=ptr;
                name=ready_queue[i];
            }
        }
        done_job.push_back(name);
        process[loc].rtime--;
        tme++;
        cout<<"At time = "<<tme<<" :    "<< name<<"\t\t "<<process[loc].rtime<<"\n";
        if(process[loc].rtime==0)
        {
            process[loc].comptime=tme;
            ready_queue.erase(std::find(ready_queue.begin(),ready_queue.end(),name));
            cnt++;
            process[loc].tat=tme-process[loc].atime;
            process[loc].wt=process[loc].tat-process[loc].cputime;
        }
    }
    else
        tme++;
}
int main()
{
    cout<<"Enter no of processes\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>process[i].pid>>process[i].atime>>process[i].cputime>>process[i].priority;
        process[i].rtime=process[i].cputime;
        mp[process[i].pid]=i;
    }
    int choice;
    cout<<"Enter 1 for non-preemptive and 2 for preemptive\n";
    cin>>choice;

    if(choice==1)
        cout<<"\nNon-Preemptive Scheduling\nProcess Id     Remaining Time\n";

    if(choice==2)
        cout<<"\nPreemptive Scheduling\n            Process Id    Remaining Time \n";

    while(cnt<n)
    {
        scheduler(tme);
        if(choice==1)
            np();
        else
            p();
    }
    cout<<"\nGantt Chart\n";
    cout<<done_job[0]<<" ";
    for(int i=1;i<done_job.size();i++)
        if(done_job[i-1]!=done_job[i])
            cout<<done_job[i]<< " ";
    cout<<"\n\n";

    cout<<"ID      Arrival Time      CPU Time        Comp. Time      Waiting Time      Turn Around Time\n";
    for(int i=0;i<n;i++)
        cout<<process[i].pid<<"\t\t"<<process[i].atime<<"\t\t"<<process[i].cputime<<"\t\t"<<process[i].comptime<<"\t\t"<<process[i].wt<<"\t\t"<<process[i].tat<<"\n";

    float total_wt=0.0,total_tat=0.0;
    for(int i=0;i<n;i++)
    {
        total_wt+=process[i].wt;
        total_tat+=process[i].tat;
    }
    total_tat/=n;
    total_wt/=n;
    cout<<"Average waiting time is "<<total_wt<<"\n";
    cout<<"Average turn around time is "<<total_tat<<"\n";
}
/*
5
P1 0 10 1
P2 5 12 2
P3 10 5 3
P4 12 8 2
P5 14 4 1
*/
