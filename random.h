#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include "automaton.h"
using namespace std;

class Timer {

chrono::system_clock::time_point m_start;

public:
Timer(){
  m_start = chrono::system_clock::now();
}
float get_duration(){
  auto end = chrono::system_clock::now();
  chrono::duration<float, milli> duration = end - m_start;
  float duration_ = duration.count();
  cout << duration.count() << " ms" << endl;
  return duration_;
}
};

string ASCII(){
  string ASCII_;
  
  /* for(char i = '!' ; i <= '~' ; ++i){
    ASCII_.push_back(i);
  } */
  
  for(char i = 'A' ; i <= 'Z' ; ++i){ // solo el alfabeto
    ASCII_.push_back(i);
  }
  return ASCII_;
}


string alfabeto(string ASCII_){
    
  srand(time(NULL));
    
  int size_A = (std::rand() % ASCII_.length());
  string A; 
  
  for(int i = 0 ; i < size_A ; ++i){
    char C = ASCII_[(std::rand() % ASCII_.length()-1)];
    A.push_back(C);
  }

  cout << "Alfabeto: " << endl;
  for(int i = 0 ; i < size_A ; i++){
    cout << A[i] << ((i % 16 == 15) ? '\n' : ' ');
  }
    cout<<endl<<endl;

    return A;
  }
DoubleList<string> cadenas(string alfab, int cnt_max_long_cdns, int cant_cadenas){
  
  cout << "Cantidad de cadenas = " << cant_cadenas <<  endl << endl;

  DoubleList<string> T; 
  for(int i = 0 ; i < cant_cadenas ; ++i){
    
    int size_of_each_string = ((std::rand() % cnt_max_long_cdns)+1);
    string temp;
    
    for(int j = 0 ; j < size_of_each_string ; j++){
      temp.push_back(alfab[(std::rand() % alfab.size())]);
    }
    
    T.push_back(temp);
    temp = "";
    
    
    cout << "cadena T" << i << " con tamanio " << size_of_each_string << ':' << endl;
    for(int x = 0 ; x < size_of_each_string ; x++){
      cout << T[i][x];
    }
    
    cout << endl << endl;
    
    
  }
  return T;
}
void p1_test_random(string alfab, int cant_cadenas, DoubleList<string> cadenas_){
    AFN afn = AFN(alfab, cant_cadenas);
    for(int g = 0 ; g < cant_cadenas ; g++){
      afn.set_tstr(cadenas_[g]);
    }
    afn.insert_states();
    afn.get_adjList();
}
float generador_random_1(int cant_cadenas){
  Timer Tr1;
  const int cnt_max_long_cdns = cant_cadenas;
  string ASCII_ = ASCII();
  string alfab = alfabeto(ASCII_); 
  // un subconjunto aleatorio de los valores ASCII
  DoubleList<string> cadenas_ = cadenas(alfab, cnt_max_long_cdns, cant_cadenas);

  p1_test_random(alfab, cant_cadenas, cadenas_);  
  return Tr1.get_duration();
}

DoubleList<string> S(DoubleList<string> cadenas_, string alfab, int cant_cadenas){
  DoubleList<string> S;
  string temp;
  for(int i = 0 ; i < cant_cadenas ; i++){
    int length_cadena = ((std::rand() % cant_cadenas)+1); 
    
    for(int j = 0 ; j < length_cadena ; j++){
      temp.push_back(alfab[(std::rand() % alfab.size())]);
      }
    S.push_back(temp);
    temp="";
    
   cout << "cadena S" << i << " con tamanio " << S[i].size() << ':' << endl;
    for(int x = 0 ; x < S[i].size() ; x++){
      cout << S[i][x];
    }
    
    cout << endl << endl;
    
  }
  return S;
}

void p2_test_random(string alfab, int cant_cadenas, DoubleList<string> cadenas_, DoubleList<string> S_){
    AFN afn = AFN(alfab, cant_cadenas);
    for(int g = 0 ; g < cant_cadenas ; g++){
      afn.set_tstr(cadenas_[g]);
    }
    afn.insert_states();
    //afn.get_adjList();
  
    for(int i = 0 ; i < S_.size() ; i++){
      afn.test_str(S_[i]);
    }
}

float generador_random_2(int cant_cadenas){
  Timer Tr2;
  const int cnt_max_long_cdns = cant_cadenas; 
  // tamanio maximo de las cadenas
  string ASCII_ = ASCII();
  string alfab = alfabeto(ASCII_);
  // un subconjunto aleatorio de los valores ASCII
  DoubleList<string> cadenas_ = cadenas(alfab, cnt_max_long_cdns, cant_cadenas);
  DoubleList<string> S_ = S(cadenas_, alfab, cant_cadenas);

  p2_test_random(alfab, cant_cadenas, cadenas_, S_);  
  return Tr2.get_duration();
}

void p3_test_random(string alfab, int cant_cadenas, DoubleList<string> cadenas_, DoubleList<string> S_){
    AFN afn = AFN(alfab, cant_cadenas);
    for(int g = 0 ; g < cant_cadenas ; g++){
      afn.set_tstr(cadenas_[g]);
    }
    afn.insert_states();
    //afn.get_adjList();
  
    for(int i = 0 ; i < S_.size() ; i++){
      afn.test_str_afd(S_[i]);
    }
}

float generador_random_3(int cant_cadenas){
  Timer Tr3;
  const int cnt_max_long_cdns = cant_cadenas; 
  // tamanio maximo de las cadenas
  string ASCII_ = ASCII();
  string alfab = alfabeto(ASCII_);
  // un subconjunto aleatorio de los valores ASCII
  DoubleList<string> cadenas_ = cadenas(alfab, cnt_max_long_cdns, cant_cadenas);
  DoubleList<string> S_ = S(cadenas_, alfab, cant_cadenas);

  p3_test_random(alfab, cant_cadenas, cadenas_, S_);  
  return Tr3.get_duration();
}

//--------------------time-------------------------------

string alfabeto_t(string ASCII_){
    
  srand(time(NULL));
    
  int size_A = (std::rand() % ASCII_.length());
  string A; 
  
  for(int i = 0 ; i < size_A ; ++i){
    char C = ASCII_[(std::rand() % ASCII_.length()-1)];
    A.push_back(C);
  }
/*
  cout << "Alfabeto: " << endl;
  for(int i = 0 ; i < size_A ; i++){
    cout << A[i] << ((i % 16 == 15) ? '\n' : ' ');
  }
    cout<<endl<<endl;
*/
    return A;
  }
DoubleList<string> cadenas_t(string alfab, int cnt_max_long_cdns, int cant_cadenas){
  
  //cout << "Cantidad de cadenas = " << cant_cadenas <<  endl << endl;

  DoubleList<string> T; 
  for(int i = 0 ; i < cant_cadenas ; ++i){
    
    int size_of_each_string = ((std::rand() % cnt_max_long_cdns)+1);
    string temp;
    
    for(int j = 0 ; j < size_of_each_string ; j++){
      temp.push_back(alfab[(std::rand() % alfab.size())]);
    }
    
    T.push_back(temp);
    temp = "";
    
    /*
    cout << "cadena " << i << " con tamanio " << size_of_each_string << ':' << endl;
    for(int x = 0 ; x < size_of_each_string ; x++){
      cout << T[i][x];
    }
    
    cout << endl << endl;
    */
    
  }
  return T;
}
void p1_test_random_t(string alfab, int cant_cadenas, DoubleList<string> cadenas_){
    AFN afn = AFN(alfab, cant_cadenas);
    for(int g = 0 ; g < cant_cadenas ; g++){
      afn.set_tstr(cadenas_[g]);
    }
    afn.insert_states();
    //afn.get_adjList();
}
float generador_random_1_t(int cant_cadenas){
  Timer Tr1;
  const int cnt_max_long_cdns = cant_cadenas;
  string ASCII_ = ASCII();
  string alfab = alfabeto_t(ASCII_); 
  // un subconjunto aleatorio de los valores ASCII
  DoubleList<string> cadenas_ = cadenas_t(alfab, cnt_max_long_cdns, cant_cadenas);

  p1_test_random_t(alfab, cant_cadenas, cadenas_);  
  return Tr1.get_duration();
}

DoubleList<string> S_t(DoubleList<string> cadenas_, string alfab, int cant_cadenas){
  DoubleList<string> S;
  string temp;
  for(int i = 0 ; i < cant_cadenas ; i++){
    int length_cadena = (std::rand() % cant_cadenas); 
    
    for(int j = 0 ; j < length_cadena ; j++){
      temp.push_back(alfab[(std::rand() % alfab.size())]);
      }
    S.push_back(temp);
    temp="";
    
    //cout << "cadena S" << i << " con tamanio " << S[i].size() << ':' << endl;
    //for(int x = 0 ; x < S[i].size() ; x++){
    //  cout << S[i][x];
    //}
    
    //cout << endl << endl;
    
  }
  return S;
}

void p2_test_random_t(string alfab, int cant_cadenas, DoubleList<string> cadenas_, DoubleList<string> S_){
    AFN afn = AFN(alfab, cant_cadenas);
    for(int g = 0 ; g < cant_cadenas ; g++){
      afn.set_tstr(cadenas_[g]);
    }
    afn.insert_states();
    //afn.get_adjList();
  
    for(int i = 0 ; i < S_.size() ; i++){
      afn.test_str(S_[i]);
    }
}

float generador_random_2_t(int cant_cadenas){
  Timer Tr2;
  const int cnt_max_long_cdns = cant_cadenas; 
  // tamanio maximo de las cadenas
  string ASCII_ = ASCII();
  string alfab = alfabeto_t(ASCII_);
  // un subconjunto aleatorio de los valores ASCII
  DoubleList<string> cadenas_ = cadenas_t(alfab, cnt_max_long_cdns, cant_cadenas);
  DoubleList<string> S_ = S_t(cadenas_, alfab, cant_cadenas);

  p2_test_random_t(alfab, cant_cadenas, cadenas_, S_);  
  return Tr2.get_duration();
}

void p3_test_random_t(string alfab, int cant_cadenas, DoubleList<string> cadenas_, DoubleList<string> S_){
    AFN afn = AFN(alfab, cant_cadenas);
    for(int g = 0 ; g < cant_cadenas ; g++){
      afn.set_tstr(cadenas_[g]);
    }
    afn.insert_states();
    //afn.get_adjList();
  
    for(int i = 0 ; i < S_.size() ; i++){
      afn.test_str_afd(S_[i]);
    }
}

double generador_random_3_t(int cant_cadenas){
  Timer Tr3;
  const int cnt_max_long_cdns = cant_cadenas; 
  // tamanio maximo de las cadenas
  string ASCII_ = ASCII();
  string alfab = alfabeto_t(ASCII_);
  // un subconjunto aleatorio de los valores ASCII
  DoubleList<string> cadenas_ = cadenas_t(alfab, cnt_max_long_cdns, cant_cadenas);
  DoubleList<string> S_ = S_t(cadenas_, alfab, cant_cadenas);

  p3_test_random_t(alfab, cant_cadenas, cadenas_, S_);  
  return Tr3.get_duration();
}

void mean_(DoubleList<double> mean, int rep){
  float sum = 0;
  for(int j = 0 ; j < mean.size() ; j++){  
    sum = sum + mean[j];
  }
  //return sum/rep;
  cout << endl << "promedio: " << sum/rep << " ms";
}

void tiempos1(int tam, int rep){
  DoubleList<double> mean;
  for(int i = 0 ; i < rep ; i++){
    mean.push_back(generador_random_1_t(tam));
  }
  mean_(mean, tam);
}

void tiempos2(int tam, int rep){
  DoubleList<double> mean;
  for(int i = 0 ; i < rep ; i++){
    mean.push_back(generador_random_2_t(tam));
  }
  mean_(mean, tam);
}

void tiempos3(int tam, int rep){
  DoubleList<double> mean;
  for(int i = 0 ; i < rep ; i++){
    mean.push_back(generador_random_3_t(tam));
  }
  mean_(mean, tam);
}

#endif