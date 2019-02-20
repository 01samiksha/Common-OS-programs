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
	int i, n = 4, total = 0;
	float t = a[0].at, awt=0, atat=0;
	int q, k=0, index;
	cout<<"\n";

	cout<<"Quantum: ";
	cin>>q;


	sort(a);

	for (i = 0; i < 4; ++i)
	{
		a[i].tl = a[i].bt;
		total += a[i].bt;
	}

	int gantt[total], time[total]; 
	time[0] = 0;

	int j = 0, count = 0;

	for (i = 0; i < total; i += q)
	{
		while(j < n)
       {
       		if( (a[j].at <= t) && (a[j].tl != 0) )
			{
				index = j;
				//cout<<"Current Quantum is : "<<j+1<<endl;
				j = (j+1)%n;
				break;
			}
			j = (j+1)%n;
		}

		if(a[index].tl < q)
		{
			t += (a[index].tl);
			i = i - (q- a[index].tl);    // i = i - 3 + 1 + 3
			a[index].tl = 0;
			
		}

		else
		{
			t += q;
			a[index].tl -= q;			
		}
		
		a[index].wt = i;		
		time[count + 1] = t;
		gantt[count++] = a[index].pno;	
		
		//cout<<"P"<<index<<" "<<i<<" "<<a[index].tl<<" "<<t<<endl;	
	}

	for(i = 0; i < n; i++)
	{
		a[i].tat = a[i].wt + q - a[i].at;
		a[i].wt = (a[i].wt - a[i].at - a[i].bt + q);
		
		awt += a[i].wt;
		atat += a[i].tat;
	}


	cout<<"\nP\tAT\tBT\tWT\tTAT"<<endl;
	for (i = 0; i < n; ++i)
	{
		cout<<a[i].pno<<"\t"<<a[i].at<<"\t"<<a[i].bt<<"\t"<<a[i].wt<<"\t"<<a[i].tat<<endl;
	}

	cout<<"\nAverage Waiting Time     : "<<(awt/n);
	cout<<"\nAverage Turn Around Time : "<<(atat/n)<<"\n";
	

	cout<<endl<<"Gantt chart: \n";


	for (i = 0; i < count; ++i)
	  cout<<"=========";

	cout<<endl<<"|  ";
	
	for (i = 0; i < count; ++i)
	{
		cout<<"P"<<gantt[i]<<"   |   ";
		//while(gantt[i] == gantt[i+1])
		//	i++;
	}

	cout<<endl<<"";

	for (i = 0; i < count; ++i)
		cout<<"=========";

	cout<<endl;
	
	for (i = 0; i <= count; ++i)
	{
		cout<<time[i]<<setw(9);
		
	}
	cout<<endl;
}