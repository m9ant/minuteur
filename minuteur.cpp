#include <iostream>
#include <unistd.h>
using namespace std;

struct Instant {
int hr, min, sec;
};

void saisie(Instant & inst){
  inst.hr = -1;
  inst.min = -1;
  inst.sec = -1;
  
  while(!(inst.hr>=0 && inst.hr<60)){
    cout<<"Saisir heure: ";
    cin>>inst.hr;
  }
  while(!(inst.min<60 && inst.min>=0)){
    cout<<"Saisir minute: ";
    cin>>inst.min;
  }
  while(!(inst.sec<60 && inst.sec>=0)){
    cout<<"Saisir seconde: ";
    cin>>inst.sec;
  }
  
}
//decrementation

void decrease(Instant ins){
  while(ins.sec!=0 || ins.min!=0 || ins.hr!=0){
  if(ins.sec==0){
    if(ins.min==0){
      if(ins.hr==0){
        cout<<"Fin du temps saisi";
      }
      ins.hr-=1; ins.min = 59;
      cout<<ins.hr<<":"<<ins.min<<":"<<ins.sec<<endl;
    }
    ins.min-=1; ins.sec = 59;
    cout<<ins.hr<<":"<<ins.min<<":"<<ins.sec<<endl;
  }else{
    sleep(1);
    ins.sec-=1;
    cout<<ins.hr<<":"<<ins.min<<":"<<ins.sec<<endl;
  }

  }
  
}


int main(){
  Instant TEST;
  saisie(TEST);
  decrease(TEST);
}