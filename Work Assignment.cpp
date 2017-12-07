//============================================================================
// Name        : Work.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
using namespace std;

class Workforce
{
public:
	Workforce(int W, int T)
{
		maxWorkers=W;
		maxTasks=T;
		wSize=0;
		tSize=0;
		gStress=0;
		graph= new Adjlist[W]; //each entry in this array is going to represent a worker so allocate space
							   //equal to the # of workers
		store= new task[T];	//Use this for temporary task storage
}

	void clearGraph();
	void createWorkers();
	void planTasks();
	void swap(int min, int index);
	void SortTasks();
	void printGraph();
	void printTasks();
	void assign_work();
private:
	int maxWorkers;	//max number of vertices for workers
	int maxTasks;	//max number of vertices for tasks
	int wSize;		//current number of workers
	int tSize;		//current number of tasks
	int gStress;	//Collective stress of all employess cannot exceed wSize * 8
	Adjlist *graph; //pointer to the array of Adjlists
	task *store;    //pointer for task container
};

void Workforce::clearGraph()
{
	for (int index=0; index < wSize;index++)
	{
		graph[index].destroylist();
	}
	gStress=0;
	tSize=0;
}
void Workforce::createWorkers()
{
	ifstream infile;
	char filename[50];
	string title;

	if (wSize!=0)	//always start fresh with an empty graph
	{
		clearGraph();
	}

	cout<<"Enter Todays Work force"<<endl;	//Prepare a file ahead of time that has all the workers for today
	cin>>filename;

	infile.open(filename, std::ifstream::in);

	if(!infile.is_open())
	{
		cout<<"File Could Not be Opened"<<endl;
		return;
	}
	infile>>wSize;	//Our files will always start with the number of workers/tasks in file
	getline(infile,title);	//discard extra \n

	if(wSize>maxWorkers)	//stop the user if they attempt to put in more workers then possible
	{
		cout<<"Not enough Shifts available today, reduce your Workforce"<<endl;
		return;
	}
	for(int index=0; index<wSize;index++)	//Now start getting the names for the array indexs
	{
		getline(infile, title);
		graph[index].setname(title);	//starting putting in workers
	}

	infile.close();
}

void Workforce::planTasks()
{
	ifstream infile;
	char filename[50];
	int tag,weight;

	cout<<"Enter Today's Tasks"<<endl;	//Prepare a file ahead of time that has all tasks for today
	cin>>filename;

	infile.open(filename, std::ifstream::in);
	if(!infile.is_open())
		{
			cout<<"File Could Not be Opened"<<endl;
			return;
		}
	infile>>tSize;	//Our files will always start with the number of tasks/workers in file
    if(tSize>maxTasks) //stop the user if they attempt to put in more tasks then possible
    {
    	cout<<"Not enough Resources for tasks, reduce your work load"<<endl;
    }
    for(int index=0; index<tSize;index++)
    {
    	infile>>tag;	//make each line be a coordinate pair %d %d and read it line by line
    	infile>>weight;
    	store[index].ID=tag;
    	store[index].load=weight;
    	gStress=gStress+weight;	//Keep on eye on the total stress of our workforce
    }
    infile.close();
}
void Workforce::swap(int max, int index)
{
	task temp;
	temp= store[index];
	store[index]=store[max];
	store[max]=temp;
}
void Workforce::SortTasks()
{
	int i, j, max_index;
	task temp;
	for(i=0;i<maxTasks-1;i++)
	{
		max_index=store[i].load;	//the current load of the first task
		for(j=i+1;j<maxTasks;j++)
		{
			if(store[i].load<store[j].load)
			{
				max_index=j;
				swap(max_index,i);
			}
		}
	}
}
void Workforce::printGraph()
{
	cout<<"Printing graph"<<endl;
	for(int index=0; index<wSize;index++)
	{
		cout<<"Worker "<<index+1<<endl;
		graph[index].printlist();

	}
}
void Workforce::printTasks()
{
	for(int index=0; index<tSize;index++)
	{
		cout<<"Task "<<store[index].ID<<": Taking "<<store[index].load<<"hours"<<endl;
	}
}

void Workforce::assign_work()
{
	int check=wSize*8;
	int limit=9;	//assume 9 to 5 work days

	if(wSize==0)
	{
		cout<<"Please Provide this Squad some Workers"<<endl;
		return;
	}
	//1) Check to see if we have tasks to begin with
	if(tSize==0)
	{
		cout<<"You have no tasks to assign please load some in"<<endl;
		return;
	}
	//2) The global stress does not exceed our capacity
	if(gStress==check)
	{
		cout<<"Current task load is over capacity, please re-enter"<<endl;
		return;
	}
	//Now if we plan greedily we should assign tasks form order of most time consuming to least time consuming
	//to workers with the least stress to most stress
	//Sort the tasks in descending order
	SortTasks();
	for(int i=0; i<tSize; i++)
	{
		for(int j=0; j<wSize; j++)
		{
			if(graph[j].getstress()+store[i].load>=limit)
			{
				//do nothing

			}
			else
			{
				graph[j].insert(store[i]);
				break;	//end the loop early
			}
		}
	}
	if(maxWorkers<=10)
	{
		cout<<"Squad 1 is ready \n";
	}
	else
	{
		cout<<"Squad 2 is ready \n";
	}
}
int main() {
	Workforce test(10,20);
	Workforce test2(50,100);


cout<<" Group 12 WorkForce Allocation \n" ;
	int choice,a=0;

	    do
	    {

	                cout<<" 1. Enter a squad list of at most 10 workers \n";
	                cout<<" 2. Enter a squad list of at most 50 workers \n";
	                cout<<" 3. Enter a list of Tasks for Squad 1 to complete \n";
	                cout<<" 4. Enter a list of Tasks for squad 2 to complete \n";
	                cout<<" 5. Assign Squad 1 to tasks \n";
	                cout<<" 6. Assign Squad 2 to tasks \n";
	                cout<<" 7. Display WorkForce 1 \n";
	                cout<<" 8. Display WorkForce 2 \n";
	                cout<<" 9. Exit \n" ;
	                cout<<"Enter Your Choice: \n";
	                cin>>choice;

	                switch(choice)
			{
					  case 1 :
						  cout<<"Creating squad 1 \n";
						  test.createWorkers();
						  break;
					  case 2 :
						  cout<<"Creating squad 2 \n";
				          test2.createWorkers();
						  break;
					  case 3 :
						  test.planTasks();
						  cout<<"Tasks Entered \n";
						  break;
					  case 4 :
						  test2.planTasks();
						  cout<<"Tasks Entered \n";
						  break;
					  case 5 :
						  test.assign_work();
						  break;
					  case 6 :
						  test2.assign_work();
						  break;
					  case 7 :
						  test.printGraph();
						  break;
					  case 8 :
						  test2.printGraph();
						  break;
					  case 9:
						  cout<<"Logging off"<<endl;
						  a=1;
						  break;
					  default :
						  cout<<"\nEnter a Valid Choice.";
			}
			cout<<endl;


	    }while(a!=1);
	    return 0;
}
//Output
//Group 12 WorkForce Allocation
//1. Enter a squad list of at most 10 workers (Demo only)
//2. Enter a squad list of at most 50 workers
//3. Enter a list of Tasks for Squad 1 to complete
//4. Enter a list of Tasks for squad 2 to complete
//5. Assign Squad 1 to tasks
//6. Assign Squad 2 to tasks
//7. Display WorkForce 1
//8. Display WorkForce 2
//9. Exit
//Enter Your Choice:
//1
//Creating squad 1
//Enter Todays Work force
//test1W.txt
//
//1. Enter a squad list of at most 10 workers (Demo only)
//2. Enter a squad list of at most 50 workers
//3. Enter a list of Tasks for Squad 1 to complete
//4. Enter a list of Tasks for squad 2 to complete
//5. Assign Squad 1 to tasks
//6. Assign Squad 2 to tasks
//7. Display WorkForce 1
//8. Display WorkForce 2
//9. Exit
//Enter Your Choice:
//3
//Enter Today's Tasks
//test1T.txt
//Tasks Entered
//
//1. Enter a squad list of at most 10 workers (Demo only)
//2. Enter a squad list of at most 50 workers
//3. Enter a list of Tasks for Squad 1 to complete
//4. Enter a list of Tasks for squad 2 to complete
//5. Assign Squad 1 to tasks
//6. Assign Squad 2 to tasks
//7. Display WorkForce 1
//8. Display WorkForce 2
//9. Exit
//Enter Your Choice:
//5
//Squad 1 is ready
//
//1. Enter a squad list of at most 10 workers (Demo only)
//2. Enter a squad list of at most 50 workers
//3. Enter a list of Tasks for Squad 1 to complete
//4. Enter a list of Tasks for squad 2 to complete
//5. Assign Squad 1 to tasks
//6. Assign Squad 2 to tasks
//7. Display WorkForce 1
//8. Display WorkForce 2
//9. Exit
//Enter Your Choice:
//7
//Printing graph
//Worker 1
//Douglas has the following tasks
//Task 6 Taking 8 hour(s) to complete
//
//Worker 2
//Dustin has the following tasks
//Task 14 Taking 1 hour(s) to complete
//
//Task 4 Taking 7 hour(s) to complete
//
//Worker 3
//Mildred has the following tasks
//Task 12 Taking 1 hour(s) to complete
//
//Task 2 Taking 7 hour(s) to complete
//
//Worker 4
//Bryan has the following tasks
//Task 5 Taking 1 hour(s) to complete
//
//Task 18 Taking 7 hour(s) to complete
//
//Worker 5
//Reagan has the following tasks
//Task 17 Taking 2 hour(s) to complete
//
//Task 13 Taking 6 hour(s) to complete
//
//Worker 6
//Jerome has the following tasks
//Task 7 Taking 2 hour(s) to complete
//
//Task 3 Taking 6 hour(s) to complete
//
//Worker 7
//Jarrett has the following tasks
//Task 10 Taking 3 hour(s) to complete
//
//Task 15 Taking 5 hour(s) to complete
//
//Worker 8
//Lindsay has the following tasks
//Task 16 Taking 3 hour(s) to complete
//
//Task 19 Taking 5 hour(s) to complete
//
//Worker 9
//Beatrice has the following tasks
//Task 20 Taking 1 hour(s) to complete
//
//Task 1 Taking 3 hour(s) to complete
//
//Task 11 Taking 4 hour(s) to complete
//
//Worker 10
//Rolland has the following tasks
//Task 8 Taking 2 hour(s) to complete
//
//Task 9 Taking 3 hour(s) to complete
//
//
//1. Enter a squad list of at most 10 workers (Demo only)
//2. Enter a squad list of at most 50 workers
//3. Enter a list of Tasks for Squad 1 to complete
//4. Enter a list of Tasks for squad 2 to complete
//5. Assign Squad 1 to tasks
//6. Assign Squad 2 to tasks
//7. Display WorkForce 1
//8. Display WorkForce 2
//9. Exit
//Enter Your Choice:
//9
//Logging off

