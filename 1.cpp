#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class RBAC{
	private:
		multimap <string,string> userRoleMap;
		struct user{
			string name;
			string role;
		};
		struct action{
			string action;
			string object;
		};
		fstream f;
		fstream g;
	public:
			RBAC(){}
			void loadFiles(){
			f.open("PRA.txt", ios::in);
			if(!f){
				cout << "PRA.txt file not found"; exit(1);
			}
			while(!f.eof()){
				f >> user.name;
				f >> user.role;
			}
			g.open("URA.txt", ios::in);
			if(!g){
				cout << "URA.txt - file not found "; exit(1);
			}
			
			
		}
		void assignRoles(){
		    userRoleMap.insert(pair<string,string>("Kevin", "Ninja"));
		    userRoleMap.insert(pair<string,string>("Alberto", "Jedi"));
		    userRoleMap.insert(pair<string,string>("Cesar", "Alien"));
		    
		}
		void printRoles(){
			/**
	 		* Get a pair of iterators (basically a fancy pointers)
	 		* to the beginning and end of the list of role strings
	 		* associated with user Joe.
			 */ 	
			pair<multimap<string,string>::iterator, multimap<string,string>::iterator> iterPair = userRoleMap.equal_range("Kevin");
	
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
			mapIt != userRoleMap.end(); ++mapIt){
				cout << mapIt->first << " assigned to role " << mapIt->second << endl;
			}	
		}
		~RBAC(){}

};

int main(void){
	RBAC A;
	A.loadFiles();
	A.assignRoles();
	A.printRoles();
	
	return(0);
}