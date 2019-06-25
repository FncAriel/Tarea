#include <iostream>
#include<stdlib.h>
#include <cstdlib>
using namespace std;

int main(){

int c = 0;
int f = 0;
int d = 0;
int p = 0;
int suma;

int array1[f][c];
int array2[d][p];
int array3[f][p];
cout << "Ingresar numero de filas de la primera matriz: " ;
cin >> f;
cout << "Ingresar numero de columnas de la primera matriz: " ;
cin >> c;
for(int i = 0; i < f; i++){
  for (int j = 0; j < c; j++) {
    int r = (rand() % 100) + 1;
    array2[i][j] = r;
    cout << r << endl;
  }
}
cout << "Ingresar numero de filas de la segunda matriz: " ;
cin >> d;
cout << "Ingresar numero de columnas de la segunda matriz: " ;
cin >> p;
if(c == d){
  cout << " Su matriz se puede multiplicar" << endl;
  for(int i = 0; i < d; i++){
    for (int j = 0; j < p; j++) {
      int t = (rand() % 100) + 1;
      array2[i][j] = t;
      cout << t << endl;
    }
  }

  for(int i=0; i<f; i++){
          for(int j=0; j<p; j++){
            array3[i][j] = 0;
            for(int z=0; z<p; z++){
                suma = (array1[i][z] * array2[z][j]);
                array3[i][j] = suma;
                }
          }
      }

  cout<<"Matriz C: " << endl;
      for(int i=0; i<f; ++i){
          for(int j=0; j<p; ++j){
          cout<<array3[i][j]<<" ";
          cout<<endl;
          }
      }
}
else{
  cout << "Su matriz no se puede multiplicar, dado que el numero de columnas de la matriz 1, es distinto al de filas de la matriz 2." <<endl;
}

return 0;
}
