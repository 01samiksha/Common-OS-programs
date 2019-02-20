#include<iostream>
using namespace std;

#define RANGE 10
int c[3] = {-1,-1,-1};

struct page_array
{
	int page;
	bool valid;

};

void FCFS(page_array *p, int n)
{
	int j, page_faults = 0;

	for (int i = 0; i < n; ++i)
	{
		if(p[i].valid == false)
			cout<<"\nPage is invalid as its valid bit is OFF.";

		else
		{
			for (j = 0; j < 3; ++j)
			{
			
				if(p[i].page == c[j])
					break;
			}

			if(j == 3)
			{
				for(int k = 0; k < 2; k++)
					c[k] = c[k+1];

				c[2] = p[i].page;
				page_faults++;

			}	


			cout << endl;
			for(int k = 0; k < 3; k++)
				cout << c[k]<<" ";
		}
	} 

	cout << "\n" << page_faults <<" page faults occured in FIFO method" <<endl;
}

int main()
{
	int n;
	cout << "Enter the number of pages you want to load from memory: ";
	cin >> n;
	page_array *p = new page_array [n];

	cout << "\nEnter the page values ";

	for (int i = 0; i < n; ++i)
		cin >> p[i].page;
	

	for (int i = 0; i < n; ++i)
	{
		if( (p[i].page >= 0) && (p[i].page <= RANGE) )
			p[i].valid = true;
	
		else
			p[i].valid = false;
	}

	FCFS(p, n);

	return 0;
}