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

int main(){
  //initialize values
  int seed = 636766;
  int length = 16;
  string path = "password.csv";

  bool usingStandart;
  bool answered;
  char answer;
  
  //UI
  do {
    cout << "Do you want set your own preferences of generating password (seed,\nlength of password=16,and path of saving the file=h.csv)?\nIf no, standart one will be using(y/n) ";
    cin >> answer;
    cout << endl;
    if(answer == 'y' || answer == 'n'){
      answered = true;
      if(answer == 'y'){
	usingStandart = false;
      } else{
	usingStandart = true;
      }
    }
  } while(!answered);

  if(!usingStandart){

    cout << "Please, enter preferred seed(only integer numbers): ";
    cin >> seed;
    cout << endl;

    cout << "Please, enter length of password(only integer numbers): ";
    cin >> length;
    cout << endl;

    cout << "Please, enter path where you want to save the file with password\npath/name.format(path is optional, without it, file will be saved in directory of generator): ";
    string tempPath;
    getline(cin, tempPath);
    path = (tempPath=="") ? path : tempPath;
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
  return 0;
}


int getRandomNumber(int min, int max){
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
  return static_cast<int>(rand() * fraction * (max - min - 1) + min);
}
