#include<iostream>
#include<fstream>

using namespace std;

int main(){
  srand(13646);

  string password = "";
  short c;

  string path = "D:\\h.txt";
  
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
