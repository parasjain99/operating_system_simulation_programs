#include<bits/stdc++.h>
using namespace std;

class process{
	public:
		int at,bt,ct,tat,wt,rbt,p;
		void get(){
			cin>>at>>bt>>p;
			rbt=bt;
		}
		void time(int t){
			ct=t;
			tat=ct-at;
			wt=tat-bt;
		}
};

int main(){
	int n,t,rj,pos;
	float atat,awt;
	cout<<"Enter number of processes : ";
	cin>>n;
	process list[n];
	vector<int> order;
	for(int i=0;i<n;i++){
		cout<<"Enter arrival time and burst time and priority of the process "<<i<<" : ";
		list[i].get();
	}
	rj=n;
	t=0;
	pos=-1;
	while(rj){
		pos=-1;
		for(int i=0;i<n;i++){
			if(list[i].at<=t&&list[i].rbt>0){
				if((pos==-1)||(list[i].p>list[pos].p)||((list[i].p==list[pos].p)&&(list[i].at<list[pos].at))){
					pos = i;
				}
			}
		}
		if(pos!=-1){
			t++;
			list[pos].rbt--;
			order.push_back(pos);
			if(list[pos].rbt==0){
				rj--;
				list[pos].time(t);
			}
		}
		else{
			t++;
			order.push_back(pos);	
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
