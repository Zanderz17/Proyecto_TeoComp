#include <iostream>
#include <string>
#include "automaton.h"
#include "read.h"
using namespace std;


void p1(){
    AFN afn = AFN("abcdefghijklmnopqrstuvwxyz", 2);
    string str1 = "web";
    string str2 = "ebay";
    afn.set_tstr(str1);
    afn.set_tstr(str2);
    afn.insert_states();
    afn.get_adjList();
}

void p2(){
    AFN afn = AFN("abcdefghijklmnopqrstuvwxyz", 2);
    string str1 = "web";
    string str2 = "ebay";
    afn.set_tstr(str1);
    afn.set_tstr(str2);
    afn.insert_states();
    afn.test_str("web");
    afn.test_str("quebay");
    afn.test_str("ffwegg");
}

int main() {
  test_files_afd("in1.txt");  
  return 0;
}