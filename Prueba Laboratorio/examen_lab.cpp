/** David Infante Casas - Prueba de laboratorio Estructuras de Datos*/

/**
   Dados dos conjuntos de enteros:

1.- Crea el conjunto resultante de la unión de ambos conjuntos.
2.- Crear el conjunto resultante de la diferencia simétrica de los dos conjuntos. (Aquellos elementos que están en A o en B)
3.- Construir un nuevo conjunto resultante de los 5 elementos más grandes de ambos conjuntos.
Ejemplo:

A = {1, 2, 3, 4, 5}               B = {2, 4, 7, 9}

       C = {1, 2, 3, 4, 5, 7, 9}
       C={1, 3, 5, 7, 9}
       C={3, 4, 5, 7, 9}
*/


#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator << (ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;
  
  for (i = c.begin(); i != c.end(); ++i)
      s << (*i) << " ";
  
  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}

set<int> Union(const set<int>& a, const set<int>& b){
   set<int> union_final;
   set<int>::iterator it;
   
   for (it = a.begin(); it != a.end(); ++it){
      union_final.insert(*it);
   }
   
   for (it = b.begin(); it != b.end(); ++it){
      if (!union_final.count(*it))
         union_final.insert(*it);
   }
   
   return union_final;
}

set<int> DiferenciaSimetrica(set<int>& a, set<int>& b){ 
   set<int> diferencia_final;
   set<int>::iterator it; 
   
   for (it = a.begin(); it != a.end(); ++it){
      if (!b.count(*it))
         diferencia_final.insert(*it);
   }
   
   for (it = b.begin(); it != b.end(); ++it){
      if (!diferencia_final.count(*it) && !a.count(*it))
         diferencia_final.insert(*it);
   }
   
   return diferencia_final; 
}

set<int> XMayores(set<int>& a, set<int>& b, int x_mayores){
   set<int> mayores_total;
   set<int> union_final;
   set<int>::iterator it;
   int i = 0;
   
   for (it = a.begin(); it != a.end(); ++it){
      union_final.insert(*it);
   }
   
   for (it = b.begin(); it != b.end(); ++it){
      if (!union_final.count(*it))
         union_final.insert(*it);
   }
   
   for (it = union_final.end(); it != union_final.begin(); --it){
      if (i < x_mayores)
         mayores_total.insert(*it);
      i++;
   }
   
   return mayores_total;
}


int main(){
  
  set<int> c1;
  set<int> c2;
  
  InicializarSemilla();
  
  cout << "David Infante Casas - Prueba de estructura de datos" << endl;
  cout << "_______________________________________________________________"<<endl;
  
  for (int i=0; i < 10; ++i)
    c1.insert(generaEntero(1,100));          //inserta un entero generado aleatoriamente en el rango 1-100
  cout << "El Conjunto 1 es: " << c1 << endl;

  for(int i = 0; i < 10; ++i)
    c2.insert(generaEntero(1,100));
  cout << "El Conjunto 2 es: " << c2 << endl;
  
  cout << "_______________________________________________________________" << endl;
  cout << "Solucion ejercicio 1: " << endl;
  cout << "Union entre 1 y 2: " << Union(c1, c2) << endl;
  
  cout << "_______________________________________________________________" << endl;
  cout << "Solucion ejercicio 2: " << endl;
  cout << "Diferencia simetrica de los conjuntos : " << DiferenciaSimetrica(c1, c2) << endl;

  cout << "_______________________________________________________________" << endl;
  cout << "Solucion ejercicio 3: " << endl;
  cout << "Muestra los 5 mayores de ambos conjuntos : " << XMayores(c1, c2, 5) << endl;

  system("pause");
}


