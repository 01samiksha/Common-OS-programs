#include<iostream>
#include<cstdlib>
using namespace std;


class BoundedBuffer
{
	int full, empty, mutex, flagp, flagc; //flag tells if the process is waiting

	public:

	BoundedBuffer(int n)
	{
		full = 0;
		empty = n;
		mutex = 1;
		flagp = flagc = 0;
	}

	int wait(int S, int *flag)
	{
		if(S - 1 < 0)
		{
			*flag = 1;
			cout<<"\nWAIT\n";
			return -1;
		}

		else
			return --S;
	}

	int signal(int S)
	{
		return ++S;
	}

	void producer()
	{

		cout<<"\nItem produced by producer";
 			
 		if (wait(empty, &flagp) == -1)
 			return;
 		
 		empty = wait(empty, &flagp);
        mutex = wait(mutex, &flagp);
        cout<<"\nItem is added to buffer";
     	cout<<"\nEmpty buffers: "<<empty;
		mutex = signal(mutex);
		full = signal(full);

		if(flagc == 1)
		{
			cout<<"\n\nConsumer was waiting\n";
			consumer();
			flagc = 0;

		}
		

	}
	void consumer()
	{
		if (wait(full, &flagc) == -1)
			return;
     	
     	full = wait(full, &flagc);
        mutex = wait(mutex, &flagc);
		cout<<"\nItem is removed from buffer";
        cout<<"\nFull buffers: "<<full;
        cout<<"\nItem is consumed by consumer";        	
		mutex = signal(mutex);
		empty = signal(empty);
		
		if(flagp == 1)
		{
			cout<<"\n\nProducer was waiting\n";
			producer();
			flagc = 0;

		}

	}

};

int main()
{
	int n;
	cout << "Enter the number of buffers ";
	cin >> n;

	BoundedBuffer b(n);

	char ch;
	int r;

	do
	{
		cout << "\n1. Produce an item\n2.Consume an item\n3.Exit";
		cout << "\nEnter your choice: ";
		cin >> r;
		switch(r)
		{
			case 1:
			b.producer(); break;

			case 2: 
			b.consumer(); break;

			case 3:
			exit(0);
		}

		cout << "\nDo you want to continue? ";
		cin >> ch;

	}while(ch == 'y');

	//b.producer();
	//b.consumer();
}


