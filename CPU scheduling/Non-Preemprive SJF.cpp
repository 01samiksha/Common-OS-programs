#include <iostream>
#include<iomanip>

using namespace std;

struct process
{
	int pno;
	int at;
	int bt;
	int priority;
	int wt;
	int tat;
	int tl; //time-left
};

//sort on the basis of arrival time
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
	process a[] = {{1,0,7,1}, {2,2,4,2}, {3,4,1,3}, {4,5,4,2}};
	int i, n = 4, total = 0, count = 1;
	float t = a[0].at, awt=0, atat=0;
	int k=0, index;
	cout<<"\n";

	sort(a);

	for (i = 0; i < n; ++i)
	{
		a[i].tl = a[i].bt;
		total += a[i].bt;
	}

	int gantt[n], time[n+1];
	time[0] = 0; 
	

	for (i = 0; i < n; ++i)
	{
		int j = 0, small = 1000;
		while(j < n)
		{
			if( (a[j].at <= t) && (a[j].tl != 0) )
			{

				if(a[j].bt < small)
				{
					index = j;
					small = a[j].bt;
				}
			}
			j++;
		}


		a[index].wt = t;
		t += a[index].bt;
		gantt[i] = a[index].pno;
		a[index].tl = 0;
		time[i+1] = t;		
	
	}

	for(i = 0; i < n; i++)
	{
		a[i].tat = a[i].wt + a[i].bt - a[i].at;
		a[i].wt = (a[i].wt - a[i].at);
		
		awt += a[i].wt;
		atat += a[i].tat;

	}


	cout<<"P\tAT\tBT\tWT\tTAT"<<endl;
	for (i = 0; i < n; ++i)
	{
		cout<<a[i].pno<<"\t"<<a[i].at<<"\t"<<a[i].bt<<"\t"<<a[i].wt<<"\t"<<a[i].tat<<endl;
	}

	cout<<endl<<"Gantt chart: \n";


	for (i = 0; i < n; ++i)
	  cout<<"=========";

	cout<<endl<<"|  ";
	
	for (i = 0; i < n; ++i)
	{
		cout<<"P"<<gantt[i]<<"   |   ";
		while(gantt[i] == gantt[i+1])
			i++;
	}

	cout<<endl<<"";

	for (i = 0; i < n; ++i)
		cout<<"=========";

	cout<<endl;
	
	for (i = 0; i <= n; ++i)
	{
		cout<<time[i]<<setw(9);
	}
	cout<<endl;

	cout<<"\nAverage Waiting Time     : "<<(awt/n);
	cout<<"\nAverage Turn Around Time : "<<(atat/n)<<"\n\n";
}