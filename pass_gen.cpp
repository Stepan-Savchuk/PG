#include<iostream>
#include<fstream>

using namespace std;

int main(){
  int seed = 13646;

  srand(seed);

  string password = "";
  short c;

  string path = "h.txt";
  
  ofstream out;
  out.open(path);
  int i=0;
  
  for(int i=0; i < 16; i++){
    int r = rand();
    password[i] = to_string(r)[0];
    if(r>=0 && r<=127 && c%2==0){
      char ch = r;
      password[i]=ch;
    }
    if(out.is_open()){
    out << password[i];
    }
    c++;
  }  
  return 0;
}
