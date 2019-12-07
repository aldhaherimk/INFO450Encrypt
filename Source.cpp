#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void eFile(){
	string fname; char fileData ;
	fstream ef,etf;

	cout << "Enter file name with path to Encrypt" << endl;
	cout << endl;
	cin >> fname;
	
	ef.open(fname);
	if (!ef){
		cout << "ERROR ! file not found" << endl;
	}
	etf.open("..\\diskFile.txt");
	if (!etf)
		cout << "ERROR ! " << endl;

		while (!ef.eof())
		{
			ef >> fileData;
			fileData = fileData +100;
			etf << fileData;
		}
		ef.close();
		etf.close();

		ef.open(fname);
		etf.open("..\\diskFile.txt");
		while (etf.eof() == 0){
			etf >> fileData;
			ef << fileData;
		}
		cout << " Encryption successful " << endl;
		ef.close();
		etf.close();

	

}// end of function..
void dFile(){
	fstream df, dtf;char fileData;
	string fname;
	cout << "Enter file name with path to decrypt" << endl;
	cout << endl;
	cin >> fname;
	df.open(fname);
	dtf.open("..\\diskFile.txt");
	if (!df || !dtf)
		cout << "ERROR ! file not found" << endl;
	else{
		while (dtf.eof() == 0)
		{

			dtf >> fileData;
			fileData = fileData - 100;
			df << fileData;
			cout <<fileData <<endl;
		}

	}///end of else..
	df.close();
	dtf.close();
}
void main(){
	
	int input;
	cout << "Are you Ready to protect your data?"<< endl;
	do
	{
	
	cout << "Enter you option" << endl;
	cout << "1 for Encryption" << endl;
	cout << "2 for Decryption" << endl;
	cout << "3 for Exit "      << endl;
	cin >> input;
	cout << "You choose option " << input << endl;

	if (input == 1){
		eFile();
		/*fstream rf;
		string path = "c:\\users\\mehwish\\desktop\\new.txt";
		rf.open(path);
		while (!rf.eof()==0)
		{
			rf <<"hello i am mehwish" ;
		}
		rf.close();*/
		
	}
	
	else if (input == 2)
		dFile();
	else if (input!=3)
		cout << "Choose write option please" << endl;
	} while (!(input==3));
	cout << endl;

	system("pause");// wait for key press.

}// end of main function
