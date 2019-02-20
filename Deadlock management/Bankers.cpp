#include<iostream>
using namespace std;

const int resources = 3;
int avail[resources] = {3, 3, 2};

struct process
{
	int pno;
	int allocation[resources];
	int max[resources];
	int need[resources];
	bool finish;
};

//--------------SAFETY ALGORITHM-------------------
void safety(process a[], int n )
{
	int work[resources], k, flag = -1, l = 0, s[n], m;
	process p[n];
			int i; 

	cout<<endl;
	
	//----------------Printing of table-----------------------
	cout<<"Process\t\tAllocation\tMax\tAvailable\tNeed"<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"P"<<i<<"\t\t";

		for (int j = 0; j < resources; ++j)
			cout<<a[i].allocation[j]<<" ";
		
		cout<<"\t\t";
		
		for (int j = 0; j < resources; ++j)
			cout<<a[i].max[j]<<" ";

		cout<<"\t  ";

		if(i == 0)
		for (int j = 0; j < resources; ++j)
			cout<<avail[j]<<" ";
		
		if(i == 0)
			cout<<"\t";
		else
			cout<<"\t\t";

		for (int j = 0; j < resources; ++j)
			cout<<a[i].max[j] - a[i].allocation[j]<<" ";

		cout<<endl;
	}

	//-----------s[i] stores the seq. of process followed in safe state---------
	for (i = 0; i < n; ++i)
		s[i] = -1;
	
	
	for (k = 0; k < n; ++k)
	{
		for (l = 0; l < n; ++l)
			p[l] = a[l]; 
	

		for (l = 0; l < n; ++l)
		for (int j = 0; j < resources; ++j)
			p[l].need[j] = p[l].max[j] - p[l].allocation[j];

		i = k;
		for (l = 0; l < resources; ++l)
	  		work[l] = avail[l];

		for (l = 0; l < n; ++l)
			p[l].finish = false; 


	l = 0;
	int h = 0;

	while(l < 15)
	{
		if(p[i].finish == false)
		{
			flag = 1;	// 1 means inner condition is satisfied 
			for(int j = 0; j < resources; j++)
				if(p[i].need[j] > work[j])
				flag = 0;

			if(flag == 1)
			{
				for (int j = 0; j < resources; ++j)
					work[j] += p[i].allocation[j];
						
				p[i].finish = true;
				s[h] = p[i].pno;
				h++;
			}

		}

		i = (i+1)%n;

		for (m= 0; m < n; ++m)
			if(p[m].finish == false)
				break;

	 	if(m == n)
			break;
		l++;
	}

	if(l != n*n-1)
	{	
		cout<<"System is in safe state if we start with P"<<s[0]<<endl;;

		for (int l = 0; l < n; ++l)
			cout<<"P"<<s[l]<<" ";
		
		break;
	}

}

	if(k == n)
	cout<<"System is in unsafe state. ";
cout<<"\n____________________________"<<endl;

}

void resource_request(process p[], int n, int request[], int i)
{
	for (int j = 0; j < resources; ++j)
		if(request[j] > avail[j])
		{
			cout<<"\nYou will have to wait\n";
			return;
	    }
	
	
	for (int j = 0; j < resources; ++j)
	{
		avail[j] -= request[j];
		p[i].allocation[j] += request[j];
		p[i].need[j] -= request[j];
	}

	safety(p,n);
	
}

int main()
{
	int n = 5;
	process p[n] = { {0, {0,1,0}, {7,5,3}},
					 {1, {2,0,0}, {3,2,2}},
					 {2, {3,0,2}, {9,0,2}},
					 {3, {2,1,1}, {2,2,2}},
					 {4, {0,0,2}, {4,3,3}}
	} ;

	int request[resources] = {1,0,2}, j = 1;   
	safety(p,n);

	cout<<"\nRequesting to allocate ";

	for (int i = 0; i < resources; ++i)
		cout<<request[i]<<" ";

	cout<<"to P"<<j<<endl;
	
	resource_request(p, n , request, j);
}




