#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,tq,t,rj,pos,clk,temp;
    float atat,awt;
    queue<int> q;
    cout<<"Enter no of processes and time quanta";
    cin>>n>>tq;
    vector<int> at(n),bt(n),ct(n),tat(n),wt(n),rbt(n),order;
    for(int i=0;i<n;i++){
        cout<<"Enter at and bt: ";
        cin>>at[i]>>bt[i];
        rbt[i]=bt[i];
    }
    rj=n;
    t=0;
    clk=0;
    temp=-1;
    while(rj){
        pos=-1;
        for(int i=0;i<n;i++){
            if(at[i]==t){
                q.push(i);
            }
        }
        if(temp!=-1){
            q.push(temp);
            temp=-1;
        }
        if(!q.empty()){
            pos = q.front();
            rbt[pos]--;
            t++;
            clk++;
            order.push_back(pos);
            if(rbt[pos]==0){
                clk=0;
                rj--;
                q.pop();
                ct[pos]=t;
                tat[pos]=ct[pos]-at[pos];
                wt[pos]=tat[pos]-bt[pos];
            }
            else if(clk==tq){
                clk=0;
                q.pop();
                temp=pos;
                // q.push(pos);
            }
        }
        else{
            order.push_back(-1);
            t++;
        }
    }
    for(int x:order){
        cout<<"->"<<x;
    }
    atat=0;
    awt=0;
    cout<<"\npid\tat\tbt\tct\ttat\twt\n";
    for(int i=0;i<n;i++){
        cout<<i<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
        atat+=tat[i];
        awt+=wt[i];
    }
    atat/=n;
    awt/=n;
    cout<<"\natat: "<<atat<<"\nwt: "<<awt;

}