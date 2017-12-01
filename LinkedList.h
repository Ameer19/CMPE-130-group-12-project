/*
 * LinkedList.h
 *
 *  Created on: Nov 19, 2017
 *      Author: Ameer
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;



struct task
{
	int ID;		//Task Number
	int load; 	//hours for task
	task *next;	//task will have pointers solely to make AdjList work they DO NOT represent EDGES
	task()
	{
		ID=0;
		load=0;
		next=NULL;
	}
	void operator=(const task& obj)
	{
		ID=obj.ID;
		load=obj.load;
	}

};


class Adjlist
{
private:
	int tcount;	//how many tasks in list
	int stress; //how much burden is the worker on
	string name;
	task* head;
public:
	Adjlist()
{
		tcount=0;
		stress=0;
		head=NULL;
}
	int gettcount();
	int getstress();
	void setname(string title);


	bool findtask(const task &find);
	void insert(const task& obj);
    void printlist();
    void destroylist();

	string getname();	//get info from header worker

};


//head
//Worker------>task 	works just fine if its one to one between Worker and task
//						but if the number of tasks is greater then workers or if we have
//						more workers then tasks how is matching going to work?

//head
//Worker------>task		Our list will work like this with a head worker node pointing to any number of task nodes
//		|				An Adjlist represents all the nodes adjacent TO the head node they are not necessarily adjacent to each other
//		|______>task
//		|
//		|
//		|______>task



#endif
