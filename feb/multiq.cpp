#include<bits/stdc++.h>
using namespace std;

class process{
	public:
	int at,bt,ct,wt,tat,rbt;
	char type;
	void get(){
		cout<<"Enter at,bt: ";
		cin>>at>>bt;
		cout<<"Enter type of process s or u: ";
		cin>>type;
		rbt=bt;
	}
	void time(int t){
		ct = t;
		tat = ct-at;
		wt = tat - bt;
	}
};

int main(){
	int n,rj,t=0,p;
	cout<<"Enter no. of process: ";
	cin>>n;
	vector<process> list(n);
	vector<int > order;
	queue<int > uq,sq;
	
	for(int i=0;i<n;i++){
		list[i].get();	
	}

	rj = n;
	while(rj){
		//cout<<rj<<endl;
		for(int i=0;i<n;i++){
			if(list[i].at == t && list[i].type == 's')
					sq.push(i);
			else if(list[i].at == t && list[i].type == 'u')
					uq.push(i);
				
		}
		if(!sq.empty()){
			p = sq.front();
			t++;
			list[p].rbt--;
			order.push_back(p);
			if(list[p].rbt==0){
				sq.pop();
				list[p].time(t);
				rj--;
					
			}
		}
		else if(!uq.empty()){
			p = uq.front();
			t++;
			list[p].rbt--;
			order.push_back(p);
			if(list[p].rbt==0){
				uq.pop();
				list[p].time(t);
				rj--;
			}	
		}
		else {	
			t++;
			order.push_back(-1);		
		}
	}
	cout<<"Gant chart\n";
	for(int i=0;i<order.size();i++){
		cout<<"->"<<order[i];	
	}
	float atat = 0, awt = 0;
	cout<<"\npid ptype ct tat wt\n";
	for(int i=0;i<n;i++){
	cout<<i<<" "<<list[i].type<<" "<<list[i].ct<<" "<<list[i].tat<<" "<<list[i].wt<<endl;
	atat+=list[i].tat;
	awt+=list[i].wt;	
	}
	atat/=n;
	awt/=n;
	cout<<"avg tat = "<<atat;
	cout<<"\navg wt = "<<awt;
}

/*
1 2
c
1 4
s
2 3
c
3 1
s
4 2
c
*/
