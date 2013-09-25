#include <iostream>
#include <map>
#include <string>

/** Compilation instructions: g++ multimap.cpp -o multimap
 * Running the program: ./multimap
 */ 

/**
 * Demonstrates how the multimap works
 */

using namespace std;

int main()
{
	/* Create a map that associates a string key
	 * with a set of strings
	 */
	multimap<string,string> userRoleMap;

	/**
 	 * Insert a pairs of strings 
	 */
	userRoleMap.insert(pair<string,string>("Joe", "Student"));
	userRoleMap.insert(pair<string,string>("Joe", "Grader"));
	userRoleMap.insert(pair<string,string>("John", "Professor"));
	userRoleMap.insert(pair<string,string>("Jane", "DeptChair"));
	
	/**
	 * Get a pair of iterators (basically a fancy pointers)
	 * to the beginning and end of the list of role strings
	 * associated with user Joe.
	 */ 	
	pair<multimap<string,string>::iterator, multimap<string,string>::iterator> iterPair = userRoleMap.equal_range("Joe");
	
	/* Print the roles of Joe */
	cout << "User " << iterPair.first->first << " is assigned to roles: ";
		
	/**
 	 * Print all the roles assigned to user "Joe"
	 */
	for(multimap<string,string>::iterator listIt = iterPair.first; 
		listIt != iterPair.second; ++listIt)
	{
		cout << listIt->second << " ";
	}		
	
	cout << endl << endl;
	
	/** Print all user role assignments **/
	cout << "**Here are all the user role assignments**" << endl;

	/* Go through all the entire map */
	for(multimap<string,string>::iterator mapIt = userRoleMap.begin();
		mapIt != userRoleMap.end(); ++mapIt)
	{
		cout << mapIt->first << " assigned to role " << mapIt->second << endl;
	}	
	
	return 0;
}
