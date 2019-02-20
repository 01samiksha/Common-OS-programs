#include<iostream>
#include<cstdlib>
using namespace std;


class ReadersWriters
{
	int wrt, mutex;		//Semaphores
	int readcount, flagr, flagw; //flag tells if the process is waiting

	public:

	ReadersWriters()
	{
		wrt = 1;
		mutex = 1;
		readcount = 0;
		flagr = flagw = 0;
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

	void readersEntry()
	{
 		
        mutex = wait(mutex, &flagr);		//mutex only in readers case, as reading can be done concurrently
 		readcount++;

 		if(readcount == 1)
 		{
 			if (wait(wrt, &flagr) == -1)
	 			return;
 			wrt = wait(wrt, &flagr);
 		}
 		mutex = signal(mutex);

		cout<<"\nReader is reading now";        
        cout<<"\nReaders at this moment: "<<readcount;

	}

	void readersExit()
	{
		mutex = wait(mutex, &flagr);

		if(readcount == 0)
		{
			cout<<"0 readers in critical section";
			return;
		}

		readcount--;
		cout<<"Readers at this moment: "<<readcount;

		if (readcount == 0)
		{
			wrt = signal(wrt);
			if(flagw == 1)
			{
				cout<<"\n\nReading process is done. Writer was waiting earlier.\n";
				writers();
				flagw = 0;
			}
		}

		mutex = signal(mutex);

	}

	void writers()
	{
		if (wait(wrt, &flagw) == -1)
			return;

     	wrt = wait(wrt, &flagw);
		cout<<"\nwrt is "<<wrt;
		cout<<"\nWriter is writing now";
		wrt = signal(wrt);
		
		if(flagr == 1)
		{
			cout<<"\n\nWriting process is done. Reader was waiting earlier.\n";
			readersEntry();
			flagw = 0;

		}

	}

};

int main()
{

	ReadersWriters b;

	char ch;
	int r;

	do
	{
		cout << "\n1. Begin writing\n2. Begin reading\n3. End reading\n4. Exit";
		cout << "\nEnter your choice: ";
		cin >> r;
		switch(r)
		{
			case 1:
			b.writers(); break;

			case 2: 
			b.readersEntry(); break;

			case 3:
			b.readersExit(); break;

			case 4:
			exit(0);
		}

		cout << "\nDo you want to continue? ";
		cin >> ch;

	}while(ch == 'y');

	//b.producer();
	//b.consumer();
}


