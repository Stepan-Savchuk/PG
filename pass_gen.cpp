#include<iostream>
#include<fstream>

using namespace std;

int main(){
  // standart values
  int seed = 136766;
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

    cout << "Please, enter preferred seed(only integer numbers) ";
    cin >> seed;
    cout << endl;

    cout << "Please, enter length of password(only integer numbers) ";
    cin >> length;
    cout << endl;

    cout << "Please, enter path where you want to save the file with password\npath\\name.format(path is optional, without it, file will be saved in directory of generator) ";
    cin >> path;
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
    int r = rand();

    password[i] = to_string(r)[0];

    if(r>=0 && r<=127 && i%2==0){
      char ch = r;
      password[i]=ch;

    }

    if(out.is_open()){
      out << password[i] << "_";
    }
  }  
  return 0;
}
