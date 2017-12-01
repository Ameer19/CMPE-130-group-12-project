/*
 * LinkedList.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: Ameer
 */

#include "LinkedList.h"
void Adjlist::setname(string title)
{
	name=title;
}
int Adjlist::gettcount()
{
	return tcount;
}

int Adjlist::getstress()
{
	return stress;
}
string Adjlist::getname()
{
	return name;
}

bool Adjlist::findtask(const task &find)
{
		//pointer to traverse the list
	task *current;
	bool found= false;

	current=head;
	 	//move current one over

	while (current != NULL && !found) //search the list
	if (current->ID==find.ID && current->load==find.load) //searchItem is found
	{
		found = true;
	}
	else
	{
		current = current->next;
	} //make current point to the next node

	return found;
}

void Adjlist::insert(const task& obj)
{
	task *newNode;	//pointer to the new node
	newNode= new task;	//create this new node
	newNode->ID=obj.ID;	//stroe the info
	newNode->load=obj.load;
	newNode->next=head;
	head=newNode;
	tcount++;
	stress=stress+obj.load;

}

void Adjlist::printlist()
{
	task *current;
	cout<<name<<" has the following tasks"<<endl;

	current=head;
	if(head==NULL)	// worker has no work
		{
			cout<<"No work yet"<<endl;
		}
	else
	{
		while(current !=NULL)	//move through this list until you run to the end
			{
				cout<<"Task "<<current->ID <<" Taking "<<current->load<<" hour(s) to complete \n"<<endl;
				current=current->next;
			}
	}
}
void Adjlist::destroylist()
{
	task *temp;

	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		delete temp;
	}
	tcount=0;
	stress=0;
}

