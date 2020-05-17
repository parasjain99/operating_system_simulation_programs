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
	int n,t=0,rj,pos;
	float atat=0,awt=0;
	vector<int> order;
	cout<<"Enter number of processes: ";
	cin>>n;
	process list[n];
	for(int i=0;i<n;i++){
		cout<<"Enter arrival time and burst time of the process "<<i<<" : ";
		list[i].get();
	}
	
	rj=n;
	while(rj){
		pos = -1;
		for(int i=0;i<n;i++){	
			if((list[i].at<=t)&&list[i].rbt>0){
				if((pos==-1)||(list[i].rbt<list[pos].rbt)||(list[i].rbt==list[pos].rbt&&list[i].at<list[pos].at)){
					pos = i;
				}
			}
		}
		
		if(pos!=-1){
			order.push_back(pos);
			list[pos].rbt--;
			t++;
			if(list[pos].rbt==0){
				list[pos].time(t);
				rj--;
			}		
		}
		else{
			t++;
			order.push_back(pos);	
		}
	}
	
	for(int i=0;i<order.size();i++){
		cout<<order[i]+1<<"->";
	}

	cout<<endl;
	cout<<"pid\t"<<"ct\t"<<"tat\t"<<"wt"<<endl;
	for(int i=0;i<n;i++){
		atat+=list[i].tat;
		awt+=list[i].wt;
		cout<<i<<"\t"<<list[i].ct<<"\t"<<list[i].tat<<"\t"<<list[i].wt<<endl;
	}
	atat/=n;
	awt/=n;
	cout<<endl<<"average tat = "<<atat<<endl<<"average wt = "<<awt;	
}

