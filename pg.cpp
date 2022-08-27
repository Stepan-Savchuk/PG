#include<iostream>
#include<fstream>

using namespace std;

/*TODO:
 * Encrypting of file with password by a password
 * option to create multiple passwords with the same options
 * ability to exclude special characters
 * ability to choose between *.csv(non-encrypted) and *.pw(encrypted) file formats
*/


int getRandomNumber(int min, int max);

void writeStringVariable(string& var);

void writeIntVariable(int& var);

bool writeEncryptedFile(string title, string password);

bool readFile(string path);


int main(){
  //initialize values
  int seed = 636766;
  int length = 16;
  string path = "password.csv";

  bool usingStandart;
  bool answered;
  string answer;
  
  //UI
  do {
    cout << "Do you want set your own preferences of generating password (seed,\nlength of password=16,and path of saving the file=h.csv)?\nIf no, standart one will be using(y/n) ";
    getline(cin, answer);
    cout << answer << endl;
    if(answer == "y" || answer == "n"){
      answered = true;
      if(answer == "y"){
	usingStandart = false;
      } else{
	usingStandart = true;
      }
    }
  } while(!answered);

  if(!usingStandart){

    cout << "Please, enter preferred seed(only integer numbers): ";
    writeIntVariable(seed);
    cout << endl;

    cout << "Please, enter length of password(only integer numbers): ";
    writeIntVariable(length);
    cout << endl;

    cout << "Please, enter path where you want to save the file with password\npath/name.format(path is optional, without it, file will be saved in directory of generator): ";
    string tempPath;
    writeStringVariable(tempPath);
    path = (tempPath=="" || tempPath=="\n") ? path : tempPath;
    cout << endl;
  }
  
  //setting of seed
  srand(seed);

  //opening of file for writing the password
  ofstream out;
  out.open(path);

  string password = "";

  //generating of password
  for(int i=0; i < length; i++){
    password[i] = getRandomNumber(32, 126);

    if(out.is_open()){
      out << password[i];
    }
  }

  //Test of writeEncryptedPassword(temp)
  writeEncryptedFile("TestAxx", password);
  return 0;
}


int getRandomNumber(int min, int max){
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
  return static_cast<int>(rand() * fraction * (max - min - 1) + min);
}

void writeStringVariable(string& var){
	getline(cin, var);
}

void writeIntVariable(int& var){
	string temp;
	getline(cin, temp);
	var = stoi(temp);
}

bool writeEncryptedFile(string title, string password
){
	//start of some crypto-magic or smth
	int maxSymbolsCount = 100;
	int move = getRandomNumber(1, maxSymbolsCount);
	string newTitle;
	string newPassword;


	char moveSymbol = move;
	
	for(char c : title){
		newTitle += (c + move);
	}

	for(char c : password){
		newPassword += (c + move);
	}

	string fPath = title + "p.pw";//title in path name is temporary
        ofstream tout;
        tout.open(fPath);

	cout << "MS: " << moveSymbol << "NT: " << newTitle << "_" << newPassword; 


        tout << moveSymbol << newTitle << "_" << newPassword;

	//write byte by byte(or symbol by symbol) cypted password with a title(optional)
	return true;
}

bool readFile(string path){
	return true;
}
