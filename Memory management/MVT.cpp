#include<iostream>
using namespace std;

struct page
{
	int no;
	int size;
};

void FirstFit(int n, page a[], page b[])
{

	cout << "\n---------------FIRST FIT--------------------";
	int i = 0;

	for (int k = 0; k < n; ++k)
	{
		if(i == n)
		{
			cout<<"\nBlock "<<b[k].no<<" cannot be allocated. Memory full";
			break;
		}

		// if(a[i].size - b[k].size > 0)
		// {
		// 	cout << "\nInternal Fragmentation of block"<<b[k].no;
		// }

		if((a[i].size - b[k].size) < 0)
		{

			if(i == n-1)
			{
				cout<<"\nBlock "<<b[k].no<<" cannot be allocated. Memory full";
				break;
			}

			cout<<"\nExternal fragmentation of block"<<b[k].no;
			b[k].size = b[k].size - a[i].size;
			a[i].size = 0;
			a[++i].size -= b[k].size;
		}

		else
			a[i].size -= b[k].size;
		i++;
	}

	cout<<"\nSpace left";	//\tSpace occupied";
	for (int j = 0; j < n; ++j)
	{
		cout<<"\n"<<a[j].no<<". "<<a[j].size;//<<"\t\t\t"<<b[j];
	}

}



//------------------------------BEST FIT---------------------------
void BestFit(int n, page a[], page b[])
{
	int internal = 0;

	cout << "\n---------------BEST FIT--------------------";
	int i = 0;

	//----sorting of b----

	for (i = 0; i < n; ++i)
		for (int j = 0; j < n - i- 1; ++j)
			if(b[i].size > b[i+1].size)
			{
				page t = b[i];
				b[i] = b[i+1];
				b[i+1] = t;
			}
	
	i = 0;
	for (int k = 0; k < n; ++k)
	{
		if(i == n)
		{
			cout<<"\nBlock "<<b[k].no<<" cannot be allocated. Memory full";
			break;
		}

		if(a[i].size - b[k].size > 0)
		{
			internal += a[i].size - b[k].size; 
		}

		if((a[i].size - b[k].size) < 0)
		{
			if(i == n-1)
			{
				cout<<"\nBlock "<<b[k].no<<" cannot be allocated. Memory full";
				break;
			}


			cout<<"\nExternal fragmentation of block"<<b[k].no;
			b[k].size = b[k].size - a[i].size;
			a[i].size = 0;
			i++;
			//a[++i].size -= b[k].size;
		}

		//else
			//a[i].size -= b[k].size;
			cout<<"\nBlock "<<b[k].no<<" allocated";
		i++;
	}

}


//----------------------------MVT--------------------------
void MVT()
{
	int n;
	cout<<"Enter the number of blocks you want to enter: ";
	cin>>n;

	page a[n], c[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].size;
		a[i].no = i+1;
	}
	
	page b[n], d[n];
	for (int i = 0; i < n; ++i)
	{
			b[i].no = a[i].no;
			c[i].size = a[i].size;
			c[i].no = a[i].no;
			cout<<"\nBlock "<<i+1<<" allocated";
	}


	cout<<"\n\nProgram has been executed. Therefore, all the blocks are empty now. Enter again\n";

	for (int i = 0; i < n; ++i)
	{
		cin >> b[i].size;
		d[i].size = b[i].size;
		d[i].no = b[i].no;
	//	f[i].no = b[i].no;
	}

	BestFit(n, a, b);
	FirstFit(n, c, d);
	//WorstFit(n, e, f);
}

int main()
{
	MVT();
	cout<<endl;
}