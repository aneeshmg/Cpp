#include<iostream>

using namespace std;

class HelloWorld {
  public:
    void SayHello(void);
};
void HelloWorld::SayHello() {

  cout<<"Hello World"<<endl;
}
int main() {

  HelloWorld *hw = new HelloWorld();

  hw->SayHello();
}
