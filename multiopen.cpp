#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "omp.h"
using namespace std;

int main(){

srand(time(NULL));
int rand();
int c = 0;
int f = 0;
int d = 0;
int p = 0;
int suma;
int x;

cout << "Ingresar numero de filas de la primera matriz: " ;
cin >> f;
cout << "Ingresar numero de columnas de la primera matriz: " ;
cin >> c;

vector <vector<int>> array1(f,vector <int> (c));

for(int i = 0; i < f; i++){
  for (int j = 0; j < c; j++) {

    int num = (1+ rand()%10);
    array1[i][j] = num;
  }
}
cout << "Ingresar numero de filas de la segunda matriz: " ;
cin >> d;
cout << "Ingresar numero de columnas de la segunda matriz: " ;
cin >> p;

vector <vector<int>> array2(d, vector <int> (p));
vector <vector<int>> array3(f ,vector <int> (p));

if(c == d){
  cout << " Su matriz se puede multiplicar" << endl;
  for(int i = 0; i < d; i++){
    for (int j = 0; j < p; j++) {
      int num = (1 + rand()%10);
      array2[i][j] = num;
    }
  }

cout << "Ingrese numero de cores a utilizar (threads): ";
 cin >> x;
clock_t tStart = clock();
double wtime = omp_get_wtime();
#pragma omp parallel for num_threads(x)
  for(int i=0; i<f; i++){
          for(int j=0; j<p; j++){
            array3[i][j] = 0;
            for(int z=0; z<c; z++){
                array3[i][j] = array3[i][j]+(array1[i][z] * array2[z][j]);
            }
          }
  }
double time = (double(clock() - tStart)/(CLOCKS_PER_SEC));
wtime = omp_get_wtime() - wtime;
cout << "Tiempo total: " << time << " s"<<endl;
cout << "Tiempo real: " <<  wtime << " s" <<endl;

  /*cout<<"Matriz C: " << endl;
      for(int i=0; i<f; ++i){
          for(int j=0; j<p; ++j)
          cout<<array3[i][j]<<" ";
      } */

}
else{
  cout << "Su matriz no se puede multiplicar, dado que el numero de columnas de la matriz 1, es distinto al de filas de la matriz 2." <<endl;
}
return 0;
}
