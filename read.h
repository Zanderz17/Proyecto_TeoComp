#ifndef READ_H
#define READ_H
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include "double.h"
#include "tree.h"
#include "queue.h"
#include "automaton.h"
using namespace std;


void test_files_afn(string textname){
  ifstream someStream(textname);
  string line;

  getline( someStream, line );
  AFN afn;
  afn.set_alfa(line);
  int end_count;
  int end_count2;
  int counter = 2;

  while( !someStream.eof() ) {
    getline( someStream, line );
    if(counter==2){
      end_count= stoi(line);
    }
      
    else if(counter>2 &&  counter<=2+end_count){
      afn.set_tstr(line.substr(0, line.size() - 1)); 
    }
    else if(counter==3+end_count){
      afn.insert_states();
    }
      
    else if(counter>3+end_count){
      afn.test_str(line);
    }
    ++counter;    
  }
}


void test_files_afd(string textname){
  ifstream someStream(textname);
  string line;

  getline( someStream, line );
  AFN afn;
  afn.set_alfa(line);
  int end_count;
  int end_count2;
  int counter = 2;

  while( !someStream.eof() ) {
    getline( someStream, line );
    if(counter==2){
      end_count= stoi(line);
    }
      
    else if(counter>2 &&  counter<=2+end_count){
      afn.set_tstr(line.substr(0, line.size() - 1)); 
    }
    else if(counter==3+end_count){
      afn.insert_states();
    }
      
    else if(counter>3+end_count){
      afn.test_str_afd(line);
    }
    ++counter;    
  }
}
#endif