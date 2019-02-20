#include <iostream>
using namespace std;

struct process
{
	int pno;
	int at;
	int bt;
	int priority;
	int wt;
	int tat;
};


//Sort on the basis of arrival time
void sort(process p[])
{
	int n = 4;
	process t;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n-1-i; j++)
		{ 	
			if(p[j].at > p[j+1].at)
			{
				t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
			}
		}
}

int main()
{
	process p[] = {{0,0,0}, {1,0,7}, {2,2,4}, {3,4,1}, {4,5,4}};
	float awt = 0, atat = 0;
    sort(p);

	int n = 4, t=0;

	for (int i = 1; i <= n; ++i)
	{
		p[i].wt = t - p[i].at;
		t += p[i].bt;
		p[i].tat = t - p[i].at;
	}

	cout<<"P\tAT\tBT\tWT\tTAT"<<endl;
	for (int i = 1; i <= n; ++i)
	{
		cout<<p[i].pno<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].wt<<"\t"<<p[i].tat<<endl;
		awt += p[i].wt;
		atat += p[i].tat;
	}
	

	cout<<"\nGantt Chart:"<<endl;
	for (int i = 0; i < n; ++i)
		cout<<"========="; 
	cout<<endl<<"|   ";
	
	for (int i = 0; i < n; ++i)
	{
		cout<<"P"<<p[i].pno<<"   |   ";

	}

	cout<<endl;
	for (int i = 0; i < n; ++i)
		cout<<"========="; 
	cout<<endl;

	cout<<"\nAverage Waiting Time     : "<<awt/n;
	cout<<"\nAverage Turn Around Time : "<<atat/n<<"\n";
	return 0;

}