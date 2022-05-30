#include <iostream>
#include <string>
#include "automaton.h"
#include "random.h"
#include "read.h"
using namespace std;


void p1(){
    Timer tp1;
    AFN afn = AFN("abcdefghijklmnopqrstuvwxyz", 2);
    string str1 = "web";
    string str2 = "ebay";
    afn.set_tstr(str1);
    afn.set_tstr(str2);
    afn.insert_states();
    afn.get_adjList();
    tp1.get_duration();
}

void p2(){
    Timer tp2;
    AFN afn = AFN("abcdefghijklmnopqrstuvwxyz", 2);
    string str1 = "web";
    string str2 = "ebay";
    afn.set_tstr(str1);
    afn.set_tstr(str2);
    afn.insert_states();
    afn.test_str("web");
    afn.test_str("quebay");
    afn.test_str("ffwegg");
    tp2.get_duration();
}

void p3(){
    Timer tp3;
    AFN afn = AFN("abcdefghijklmnopqrstuvwxyz", 2);
    string str1 = "web";
    string str2 = "ebay";
    afn.set_tstr(str1);
    afn.set_tstr(str2);
    afn.insert_states();
    afn.test_str_afd("web");
    afn.test_str_afd("quebay");
    afn.test_str_afd("ffwegg");
    tp3.get_duration();
}

int main() {
  //test_files_afd("in1.txt");
    //tiempos1(10,5);
  tiempos2(100,100);
  
  //tiempos3(10,25);
  //tiempos3(10,75);
  //tiempos3(10,100);
  
  //tiempos3(50,10);
  //tiempos3(50,25);
  //tiempos3(50,50);
  //tiempos3(50,75);e called after
  //tiempos3(50,100);

  //tiempos3(75,10);
  //tiempos3(75,25);
  //tiempos3(75,50);
  //tiempos3(75,75);
  //tiempos3(75,100);

  //tiempos3(100,10);
  //tiempos3(100,25);
  //tiempos3(100,50);
  //tiempos3(100,75);
  //tiempos3(100,100);
  
  //generador_random_1(10);
  //generador_random_2(5);
  //generador_random_3(5);
  return 0;
}