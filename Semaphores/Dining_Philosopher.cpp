#include<iostream>
#include<cstdlib>
using namespace std;


class DiningPhilosopher
{
	int chopstick[5], flag[5], p[5]; //flag tells if the process is waiting

	public:

	DiningPhilosopher()
	{
		for (int i = 0; i < 5; ++i)
		{
			chopstick[i] = 1;
			flag[i] = 0;
			p[i] = 0;
		}
	}

	int wait(int S, int i)
	{
		if(S - 1 < 0)
		{
			flag[i] = 1;
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

	void eat(int i)
	{
		if (wait(chopstick[i], i) == -1)
			return;
		
		if (wait(chopstick[(i+1)%5], i ) == -1)
			return;        
     
     	chopstick[i] = wait(chopstick[i], i);
		chopstick[(i+1)%5] = wait(chopstick[(i+1)%5], i);
		cout<<"\n----EAT----";
		p[i] = 1;

		cout << endl;
		for (int j = 0; j < 5; ++j)
			if(p[j] == 1)
			cout << "P" << j+1 <<" ";
	}

	void think(int i)
	{
		chopstick[i] = signal(chopstick[i]);
		chopstick[ (i+1) % 5 ] = signal(chopstick[(i+1) % 5]);
		p[i] = 0;
		cout<<"\n----THINKING----";
		
		for (int j = 0; j < 5; ++j)
			if(flag[j] == 1)
			{
				cout<<"\n\nPhilosopher "<< j+1 <<" was waiting\n";
				flag[j] = 0;
				eat(j);
			}
	}

};

int main()
{
	DiningPhilosopher b;

	int r,i;

	do
	{
		cout << "\n1. Eat\n2.Think\n3.Exit";
		cout << "\nEnter your choice: ";
		cin >> r;
		cout << "\nChoose a philosopher: ";
		cin >> i;
		switch(r)
		{
			case 1:
			b.eat(i-1); break;

			case 2: 
			b.think(i-1); break;

			case 3:
			exit(0);
		}
	}while(1);

}


