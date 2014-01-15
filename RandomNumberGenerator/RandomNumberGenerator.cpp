#include<iostream>
#include<unistd.h>
#include<sys/time.h>
#include<ctime>
#include<string.h>

#define N   256
#define M   100000
#define Pi  3.141592653589793

using namespace std;

class Random {

  private:
    int     numI;
    float   numF;
    int     seed;
    char    text[N];
    string  str;
    struct  timeval now;

  public:
          Random(void);
          Random(float);
    int   GenerateInt(void);
    int   GenerateInt(int,int);
    float GenerateFloat(void);
    string  GenerateText(int);
    float test(void);
};

Random::Random(void) {

  numI    =   0;
  numF    =   0.0000000000;
  seed    =   time(0) % 10;
}

int Random::GenerateInt(int i, int r) {

  gettimeofday(&now, NULL);
  seed += (int)i * now.tv_usec  % 10;
  i == 0?17:i;
  numI = i + seed;

  switch(seed) {
    case 1  :   numI *= 677;
                numI *= i;
      break;
    case 2  :   numI *= 347;
                numI *= i;
      break;
    case 3  :   numI *= 331;
                numI *= i;
      break;
    case 4  :   numI *= 881;
                numI *= i;
      break;
    case 5  :   numI = numI * 983;
      break;
    case 6  :   numI = numI * 229;
      break;
    case 7  :   numI = seed * 709;
      break;
    case 8  :   numI = seed * 103;
      break;
    case 9  :   numI = numI * seed + 2013;
                numI *= i;
      break;
    default :   numI = numI * seed + 17097;
                numI *= i;
  }

  return numI % r;
}

int Random::GenerateInt() {

  gettimeofday(&now, NULL);
  seed =  now.tv_usec % 10;
  seed == 0?9:seed;
  numI = time(0) % N;

  switch(seed) {
    case 1  :   numI *= 677;
                numI *= seed;
      break;
    case 2  :   numI *= 331;
                numI *= seed;
      break;
    case 3  :   numI *= 347;
                numI *= seed;
      break;
    case 4  :   numI *= 881;
                numI *= seed;
      break;
    case 5  :   numI *= 983;
      break;
    case 6  :   numI *= 709;
      break;
    case 7  :   numI = seed * 103;
      break;
    case 8  :   numI = seed * 229;
      break;
    case 9  :   numI = numI * seed + 2569;
                numI *= seed;
      break;
    default :   numI = numI * seed + 1907;
                numI *= seed;
  }

  return numI;
}

float Random::GenerateFloat() {

  gettimeofday(&now, NULL);
  seed = now.tv_usec % 10;
  seed == 0?9:seed;
  numF = now.tv_usec / M;

  switch(seed) {
    case 1:     numF += 709 / Pi;
      break;
    case 2:     numF += 669;
      break;
    case 3:     numF *= 841 / (seed * 100);
      break;
    case 4:     numF *= 192;
      break;
    case 5:     numF *= 991 / (seed * now.tv_sec);
      break;
    case 6:     numF *= 347;
      break;
    case 7:     numF *= 331 / now.tv_usec;
      break;
    case 8:     numF += 661;
      break;
    case 9:     numF *= 541 / Pi;
      break;
    default:    numF /= (seed * (now.tv_usec % 1000));
  }

  return numF == 0.00?(now.tv_usec / M):numF;
}

string Random::GenerateText(int length) {

  //text.assign("it works");
  gettimeofday(&now, NULL);
  static const char txt[] =  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  for(int i = 0; i < length; i++) {
    text[i] = txt[now.tv_usec % (sizeof(txt) - 1)];
  }
  string n(text);
  return n;
}
float Random::test(void) {
  gettimeofday(&now, NULL);
  cout<<"Sec: "<<now.tv_sec<<"\t"<<"microsec: "<<now.tv_usec<<"\n";
}
int main() {

  Random *r = new Random();int i=10;
  while(i) {
    cout<<r->GenerateText(10)<<"\n";
    i--;
  }
}
