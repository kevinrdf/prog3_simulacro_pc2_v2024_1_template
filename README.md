# Task #SPC2: Simulacro Practica Calificada 2  
**course:** Programación III  
**unit:** 2 ,3 y 5  
**cmake project:** prog3_simulacro_pc2_v2024_1
## Instructions
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo cabecera (`.h`):
    - `find_max_triple_product.h`
    - `remove_duplicates.h`
- Adicionalmente, la **pregunta #2** podrá ser elaborada en el mismo archivo de la **pregunta #1**.
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.


### Template y Librería Standard – 7 puntos

Diseñar y desarrollar los template de función `remove_duplicates` y  `remove_duplicates_if` que permita remover los valores duplicados de un contenedor o utilizando un predicado (Callable). La función debe permitir el uso de iterators y predicados, de modo que se remueve duplicados siguiendo adicionalmente un criterio definido por el predicado. el template debe retornar el iterator que apunta al final de la secuencia resultante.

```cpp
#### Casos de uso:

```cpp
int n = 0;
cin >> n;
vector<int> v1(n);
for(auto& item: v1)
    cin >> item;
auto it1 = remove_duplicates(v1.begin(), v1.end());
v1.erase(it1, v1.end());
for(const auto& item: v1)
    cout << item << " ";
cout << endl;

vector<int> v2(n);
for(auto& item: v2)
    cin >> item;
auto it2 = remove_duplicates_if(v2.begin(), v2.end(), [](int a, int b) { return (a % 2 == 0) && (b % 2 == 0); });
v2.erase(it2, v2.end());
for(const auto& item: v2)
    cout << item << " ";
cout << endl;
```

#### Caso de uso #1
Entrada:
```
7
10 20 20 30 40 40 50
```
Salida:  
```
10 20 30 50
```

#### Caso de uso #2  
Entrada:
```
6
apple banana apple cherry banana cherry
```
Salida:
```
apple banana cherry
```

#### Caso de uso #3  
Entrada:  
```
10
3 6 9 7 12 15 18 21 24 11
```
Predicate: 
```
[](int a, int b) { return (a % 3 == 0) && (b % 3 == 0); }
```
Salida:
```
3 7 11
```

#### Caso de uso #4

```
struct Person {
    int id;
    string name;
};
```
Entrada:
```
6
1 Alice
2 Bob
1 Alice
3 Charlie
2 Bob
4 Dave
```
Predicate: 
```
[](const Person& a, const Person& b) { return a.id == b.id; }
```
Salida:
```
1 Alice
2 Bob
3 Charlie
4 Dave
```
### Complejidad Algoritmica – 6 puntos

Basado en la solución dada en la pregunta #1 calcular el Big O de la respuesta, elaborar su respuesta con los pasos necesarios. 

### Programación Concurrente – 7 puntos

Escribir la función template `find_max_triple_product` que reciba un contenedor secuencial genérico que procese de forma concurrente utilizando la mayor cantidad de hilos de hardware disponibles.

La función debe retornar el máximo valor obtenido por el producto de 3 de los valores contenidos en el contenedor. Si hubiese 3 o menos valores, la función debe retornar simplemente la multiplicación de todos. Para el caso de `std::list` sobrecargar la función template de modo que no sea concurrente.

#### Uso de la función:

```cpp
vector<long long int> vec;
int n;
while (cin >> n) vec.push_back(n);
auto result = find_max_triple_product(vec);
cout << result << endl;

list<long double> lst;
long double n;
while (cin >> n) lst.push_back(n);
auto result = find_max_triple_product(lst);
cout << fixed << setprecision(2) << result << endl;
```
