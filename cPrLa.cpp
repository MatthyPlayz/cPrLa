#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

bool kernel_enabled = true;
bool rndmsg_shown = false;
std::string kernel_name = "cPrLa";
std::string command_input;
std::string null = "";

using namespace std;

double eval( string expression );
double evalNC( string expression );

void command_parser(std::string x) {
	if(x.find_first_of("print ") == 0) {
		int ffof = x.find_first_of("print ") + 6; // find first of variable
		cout << x.substr(ffof, x.length()) << std::endl;
	} else if(!(x.find_first_of("+") >= 10000)) { // begin basic math stuff
		if(rndmsg_shown == false) {
			cout << "Warning: + or - or * or / rounds if the answer goes into decimals." << std::endl;
			rndmsg_shown = true;
		}
		eval(x);
	} else if(!(x.find_first_of("-") >= 10000)) {
		if(rndmsg_shown == false) {
			cout << "Warning: + or - or * or / rounds if the answer goes into decimals." << std::endl;
			rndmsg_shown = true;
		}
		eval(x);
	} else if(!(x.find_first_of("*") >= 10000)) {
		if(rndmsg_shown == false) {
			cout << "Warning: + or - or * or / rounds if the answer goes into decimals." << std::endl;
			rndmsg_shown = true;
		}
		eval(x);
	} else if(!(x.find_first_of("/") >= 10000)) {
		if(rndmsg_shown == false) {
			cout << "Warning: + or - or * or / rounds if the answer goes into decimals." << std::endl;
			rndmsg_shown = true;
		}
		eval(x); //end basic math stuff
	} else if(!(x.find_first_of("$") >= 10000)) {
		std::string substrthing = x.substr(1, x.length());
		evalNC(substrthing);
	} else {
	    cout << "NoCommand Error: No command matching " << x << std::endl;
	}
}
void command_operator() {
	getline(cin, command_input);
	command_parser(command_input);
}
int main() {
	cout << "cPrLa v1.0.0" << std::endl;
	
	while(kernel_enabled == true) {
	    command_operator();
	}
 }
   double evalNC( string expression )
{
    string program = "";
    program = program + "#include <cmath>\n";
    program = program + "#include <iostream>\n";
    program = program + "using namespace std;\n";
    program = program + "int main()\n";
    program = program + "{\n";
    program = program + expression + "\n";
    program = program + "}";


    ofstream out( "evalNC.cpp" );
    out << program;
    out.close();

    system( "g++ -o evalNC.exe evalNC.cpp" );
    system("evalNC");
}
 double eval( string expression )
{
    string program = "";
    program = program + "#include <cmath>\n";
    program = program + "#include <iostream>\n";
    program = program + "using namespace std;\n";
    program = program + "int main()\n";
    program = program + "{\n";
    program = program + "   cout << ";
    program = program + expression;
    program = program + " << endl;\n";
    program = program + "}";


    ofstream out( "eval.cpp" );
    out << program;
    out.close();

    system( "g++ -o eval.exe eval.cpp -c" );
    system("eval");
}
