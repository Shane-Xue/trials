#include <iostream>
using namespace std;

class b{
public:
  b(){
    cout<<"in b constructor"<<endl;
    }
  ~b(){
    cout<<"in b destructor"<<endl;
    }
  void hey(){
    cout<<"hey there!"<<endl;
    }
};

int main(){
  //b::hey();
  b boy;
  boy.hey();
  return 0;
  }
