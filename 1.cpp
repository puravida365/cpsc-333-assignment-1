#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

struct USER{
	string name;
	string role;
};
struct ACTION{
	string role;
	string action;
	string object;
};

class RBAC{
	private:
		fstream f;
		fstream g;
		string username;
		USER x[3];
		ACTION y[9];
		
	public:
			RBAC(){
				
			}
			void loadFiles(){
				
				f.open("URA.txt", ios::in);
				if(!f){ cout << "URA.txt file not found"; exit(1); }
				
				for(int i = 0; i < 3; ++i){
					f >> x[i].name;
					f >> x[i].role;
				}
				
				g.open("PRA.txt", ios::in);
				if(!g){ cout << "PRA.txt - file not found "; exit(1); }
				
				for(int i = 0; i < 3; ++i){
						g >> y[i].role;
						g >> y[i].action;
						g >> y[i].object;
				}

		}
		void userLogin()
		{
			string u1;
			
			cout << "Login: ";
			cin >> username;
			
			for(int i = 0; i < 3; ++i)
			{
				u1 = x[i].name;
				if( ( u1.compare(username) == 0 ))
				{
					cout << "Welcome " << username << "!\n"; 
				}
				else
				{
					cout << "Error user " << username << " is not in the database\n";
					break;
				}
			}
		}
		
		void printUserRoles(){
			cout << "Roles: " <<"\n";
			for(int i =0; i < 3; ++i){
				cout << x[i].role << "\n";
			}
		}
		void printUserNames(){
			cout << "Usernames: " <<"\n";
			for(int i = 0; i < 3; ++i){
				cout << x[i].name << "\n";
			}
		}
		void printActions(){
			cout << "Actions: " <<"\n";
			for(int i =0; i < 3; ++i){
				cout << y[i].action << "\n";
			}
		}
		void printObjects(){
			cout << "Objects: " <<"\n";
			for(int i =0; i < 3; ++i){
				cout << y[i].object << "\t";
			}
		}
};

int main(void){
	RBAC A;
	A.loadFiles();
	//A.userLogin();
	A.printUserRoles();
	A.printActions();
	A.printUserRoles();
	A.printUserNames();
	return(0);
}