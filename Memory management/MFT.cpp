#include<iostream>
using namespace std;

int block = 450;

void MFT(int n)
{
	int a[2*n], b[n], i;

	cout<<"\nMaximum space of this block is "<<block;
	cout<<"\nEnter the size of the blocks: ";
	
	for (i = 0; i < 2*n; ++i)
		a[i] = block;

	for (i = 0; i < n; ++i)
		cin >> b[i];

	i = 0;

	for (int k = 0; k < n; ++k)
	{
		if(a[i] - b[k] > 0)
		{
			cout << "\nInternal Fragmentation of block"<<i+1;
		}

		if((a[i] - b[k]) < 0)
		{
			cout<<"\nExternal fragmentation of block"<<i+1;
			b[k] = b[k] - a[i];
			a[i] = 0;
			a[++i] -= b[k];
		}

		else
			a[i] -= b[k];
		i++;
	}

	cout<<"\nSpace left";	//\tSpace occupied";
	for (int j = 0; j < i; ++j)
	{
		cout<<"\n"<<j+1<<". "<<a[j]<<endl;//<<"\t\t\t"<<b[j];
	}

}

int main()
{
	int n;
	cout<<"------------MFT---------------\n";
	cout<<"Enter the number of blocks to be entered ";
	cin>>n;
	MFT(n);
	return 0;
}