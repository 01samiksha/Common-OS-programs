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
	process a[] = {{1,0,7}, {2,2,4}, {3,4,1}, {4,5,4}};
	int i, n = 4, total = 0;
	float t = a[0].at, awt=0, atat=0;
	int k=0, index, count = 1;


	sort(a);

	for (i = 0; i < 4; ++i)
	{
		a[i].tl = a[i].bt;
		total += a[i].bt;
	}

	int gantt[total]; 
	
	cout<<"\n";

	for (i = 0; i < total; ++i)
	{
		int j = 0, small = 1000;
		while(j < 4)
		{
			if( (a[j].at <= i) && (a[j].tl != 0) )
			{

				if(a[j].tl < small)
				{
					index = j;
					small = a[j].tl;
				}
			}
			j++;
		}

		gantt[i] = a[index].pno;
		a[index].tl--;
		a[index].tat = i+1;

		if( (gantt[i] != gantt[i-1]) && i!=0) 
			count++;
	
	}

	for(i = 0; i < n; i++)
	{
		a[i].tat -= a[i].at;
		a[i].wt = (a[i].tat - a[i].bt);
		
		awt += a[i].wt;
		atat += a[i].tat;

	}

	awt = awt/n;
	atat = atat/n;

	cout<<"P\tAT\tBT\tWT\tTAT"<<endl;
	for (i = 0; i < n; ++i)
	{
		cout<<a[i].pno<<"\t"<<a[i].at<<"\t"<<a[i].bt<<"\t"<<a[i].wt<<"\t"<<a[i].tat<<endl;
	}

	cout<<"\nAverage Waiting Time     : "<<awt;
	cout<<"\nAverage Turn Around Time : "<<atat<<"\n";
	

	cout<<endl<<"Gantt chart: \n";


	for (i = 0; i < count; ++i)
	  cout<<"=========";

	cout<<endl<<"|  ";
	
	for (i = 0; i < total; ++i)
	{
		cout<<"P"<<gantt[i]<<"   |   ";
		while(gantt[i] == gantt[i+1])
			i++;
	}

	cout<<endl<<"";

	for (i = 0; i < count; ++i)
		cout<<"=========";

	cout<<endl;
	
	for (i = 0; i < total; ++i)
	{
		cout<<i<<setw(9);
		while(gantt[i] == gantt[i+1])
			i++;
	}
	cout<<i<<endl;
}