#include<iostream>
#include<cstdlib>
#include<unistd.h>

using namespace std;

class Timer {

  public:
    int   hours;
    int   minutes;
    int   seconds;

  public:
            Timer(void);
    int     GetHours(void);
    int     GetMinutes(void);
    int     GetSeconds(void);
    void    SetHours(int);
    void    SetMinutes(int);
    void    SetSeconds(int);
    friend  void  StartTimer(Timer);
};

Timer::Timer() {

  hours         =   0;
  minutes       =   0;
  seconds       =   0;
}

int Timer::GetHours() {

  return hours;
}

int Timer::GetMinutes() {

  return minutes;
}

int Timer::GetSeconds() {

  return seconds;
}

void Timer::SetHours(int h) {

  hours = h;
}

void Timer::SetMinutes(int m) {

  minutes = m;
}

void Timer::SetSeconds(int s) {

  seconds = s;
}

void StartTimer(Timer *t) {

  int total = t->seconds + (t->minutes * 60) + (t->hours * 3600);
  total++;

  system("clear");
  cout<<total;

  while(total) {
    total--;
    system("clear");
    cout<<"\tH: "<<(total / 3600)<<" M: "<<((total % 3600) / 60)<<" S: "<<((total % 3600) % 60);
    usleep(1000000);
  }
}

int main() {

  Timer *T = new Timer();

  T->SetSeconds(5);
  T->SetMinutes(0);
  T->SetHours(0);

  StartTimer(T);
}
