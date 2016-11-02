// Basic File I/O.
//
#include <iostream>
#include <fstream> // Include fstream

using namespace std;

int main() {
    ifstream infile; // An object that is bound to an input file
    ofstream outfile; // An object that is bound to an output file

    infile.open("4-fileio-myInputfile.txt");
    outfile.open("4-fileio-myOutputfile.txt");

    outfile << "Characters that are numbers:" << endl;

    char c;
    while(infile >> noskipws >> c) {
		if(c >= 32 && c <= 127) {
			// c is printable
			if(!(c >= '0' && c <= '9')) {
			// Skip output of number characters
			
			cout << c;
			}
			else {
			// Write number characters to outfile
			
			outfile << c << endl;
			}
		}
    }

    if(infile.eof()) {
	cout << endl << "((End of input file reached.))" << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
