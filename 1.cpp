#include <iostream>
#include <fstream>
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
				
				for(int i = 0; i < 6; ++i){
					g >> y[i].role;
					g >> y[i].action;
					g >> y[i].object;
				}

		}
		void userLogin(){
			cout << "Login: ";
			cin >> username;
			for(int i = 0; i < 3; ++i){
				if( (x[i].name) == username ){
					cout << "Welcome " << username << "!\n"; 
				}
				else{
					cout << "Error user " << username << " is not in the database\n";
					break;
				}
			}
		}
		void printUserRoles(){
			for(int i =0; i < 3; ++i){
				cout << x[i].name << "\t" << x[i].role << "\n";
			}
		}
		void printActions(){
			for(int i =0; i < 3; ++i){
				cout << y[i].role << "\t" << y[i].action << "\t" << y[i].object << "\n";
			}
		}
};

int main(void){
	RBAC A;
	A.loadFiles();
	A.userLogin();
	//A.printUserRoles();
	//A.printActions();
	//A.printRoles();
	
	return(0);
}