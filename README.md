# CMPE-130-group-12-project
Task Allocation

User will be presnted with a menu giving them a number of options 

1. Enter a squad list of at most 10 workers 
2. Enter a squad list of at most 50 workers
3. Enter a list of Tasks for Squad 1 to complete
4. Enter a list of Tasks for squad 2 to complete
5. Assign Squad 1 to tasks
6. Assign Squad 2 to tasks
7. Display WorkForce 1
8. Display WorkForce 2
9. Exit

User can go through options 1-4 provided they have a valid file to give. 5 an 6 can not be completed until options 1-2 and 3-4 are
completed first repectivly. They will have relavent error messages if this order is skipped

We have four usable files for our demo the workforce of squad 1 represented by test1W.txt and tasks to complete represented by test1T.txt
Then the Workforce of squad 2 represented by test2W.txt and the tasks to complete represented by test2T.txt. For purposes of demo the user 
can use these files. You need only pick the appropriate option and supply the proper file. The user can define there own squad size and
the amount of tasks they need completed in the main, provided they create their own appropriate text files for reading.

For worker files each text file begins with the number of workers in the file and then every line after that represents a name.
For task files each text file begins with the number of tasks in the file and then every line after that will contain two coordinate 
numbers, the first one representing the ID number of the tasks in question and the estimated hours of work needed to complete it

Once all the relavent data has been entered, the user can assign tasks to a squad with options 5 and 6 and then display the graphs with 
options 7 and 8
