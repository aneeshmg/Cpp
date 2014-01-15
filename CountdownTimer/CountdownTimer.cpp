#include<iostream>
#include<cstdlib>
#include<unistd.h>

using namespace std;

class Timer {

  public:
    int   hours;
    int   minutes;
    int   seconds;
    int   milliseconds;

  public:
            Timer(void);
    int     GetHours(void);
    int     GetMinutes(void);
    int     GetSeconds(void);
    int     GetMilliseconds(void);
    void    SetHours(int);
    void    SetMinutes(int);
    void    SetSeconds(int);
    void    SetMilliseconds(int);
    friend  void  StartTimer(Timer);
};

Timer::Timer() {

  hours         =   0;
  minutes       =   0;
  seconds       =   0;
  milliseconds  =   0;
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

int Timer::GetMilliseconds() {

  return milliseconds;
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

void Timer::SetMilliseconds(int m) {

  milliseconds = m;
}

void StartTimer(Timer *t) {

  int total = t->milliseconds + (t->seconds * 1000) + (t->minutes * 60 * 1000) + (t->hours * 60 * 60 * 1000);
  total++;

  system("clear");

  while(total) {
    system("clear");
    cout<<"\t\n"<<"M: ";
    total--;
    usleep(1000);
  }
}

int main() {

  Timer *T = new Timer();

  T->SetMilliseconds(0);
  T->SetSeconds(0);
  T->SetMinutes(2);
  T->SetHours(0);

  StartTimer(T);
}
