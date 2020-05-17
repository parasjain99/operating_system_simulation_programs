#include<bits/stdc++.h>
using namespace std;

class process{
	public:
	int at,bt,tat,ct,wt,rbt;	
	void get(){
		cin>>at>>bt;
		rbt=bt;
	}
	void time(int t){
		ct = t;
		tat = ct-at;
		wt = tat-bt;
	}
};

int main(){
	int n,rj,pos,t,tq,clk,temp;
	float atat,awt;
	queue<int> q;
	vector<int> order;
	cout<<"Enter number of jobs and time quanta: ";
	cin>>n>>tq;
	process list[n];
	for(int i=0;i<n;i++){
		cout<<"Enter arrival time and burst time of the process "<<i<<" : ";
		list[i].get();
	}
	t=0;
	rj = n;
	clk=0;
	temp=-1;
	while(rj){
		pos = -1;
		for(int i=0;i<n;i++){
			if(list[i].at==t){
				q.push(i);
			}	
		}
		if (temp != -1)
		{
			q.push(temp);
			temp = -1;
		}
		if(!q.empty()){
			pos=q.front();
			t++;
			clk++;
			list[pos].rbt--;
			order.push_back(pos);
			if(list[pos].rbt==0){
				clk = 0;
				rj--;
				q.pop();
				list[pos].time(t);
			}
			else if(clk==tq){
				clk = 0;
				q.pop();
				temp = pos;
			}
			
		}
		else{
			order.push_back(-1);
			t++;
		}
	}
	atat=0;
	awt=0;
	for(int i=0;i<order.size();i++){
		cout<<"->"<<order[i]+1;
	}
	cout<<endl<<"ct\t"<<"tat\t"<<"wt\n";
	for(int i=0;i<n;i++){
		cout<<list[i].ct<<"\t"<<list[i].tat<<"\t"<<list[i].wt<<"\n";
		atat+=list[i].tat;
		awt+=list[i].wt;
	}
	atat/=n;
	awt/=n;
	cout<<"avg tat = "<<atat<<"\navg wt = "<<awt;
}
