# Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>
Diseña e implementa en forma <span style="text-decoration-line: underline;">forma individual</span>, las funciones que resuelvan los problemas que se describen a continuación.

En la parte superior del archivo coloca, en comentarios, tus datos. Por ejemplo:
```
// =========================================================
// File: activity.h
// Author:
// Date:
// =========================================================
```
Las funciones que debes implementar son:

 - ``` bool balancedBrackets(const string &expr)```
 Devuelve ```true``` si el string  ```expr``` que recibe como parámetro contiene una expresión en donde todos sus símbolos de agrupación (paréntesis ```()```, corchetes ```[]``` y llaves ```{}```) están correctamente anidados y balanceados. Devuelve ```false``` en caso contrario. Se debe ignorar cualquier carácter de ```expr``` que no sea paréntesis, corchetes o llaves.

<br> **Descripción del algoritmo:** Empieza con una pila vacía. Recorre cada uno de los caracteres de ```expr``` de izquierda a derecha:
 - Si encuentras un símbolo de apertura (```(```, ```[``` o ```{```) debes insertarlo en la pila.
 - Si encuentras un carácter de cierre (```)```, ```]``` o ```}```) debes remover el carácter del tope de la pila y verificar que ambos caracteres hagan pareja. Debes terminar el algoritmo con ```false``` si los respectivos caracteres no hacen pareja, o si la pila estaba vacía antes de intentar remover el elemento del tope.

<br> Si al final la pila está vacía debes devolver ```true```, de otra forma debes devolver ```false```.

2. ```string convertInfixToPostfix(const string &expr) ```
Recibe como parámetro un string,  ```expr```, que contiene una expresión aritmética en notación infija. Devuelve un string con la expresión equivalente en notación posfija. No realiza ningún tipo de validación respecto a la expresión de entrada.

<br>Para implementar este algoritmo, deberás emplear dos funciones auxiliares que **ya se encuentran implementadas**:

 - La función ```tokenize``` que recibe un string y lo separa en sus elementos básicos, colocándolos en una fila de strings. Por ejemplo, si la entrada es el string "123 34 7+*-", entonces devuelve una fila con los siguientes elementos: "123", "34", "7", "+", "*" y "-".
 - La función ```hasHigherPrecedence``` que determina si el elemento del tope de la pila tiene mayor precedencia que el operador op.

<br>**Descripción del algoritmo:** Empieza con una pila vacía y una fila resultante vacía. Toma los elementos de ```expr``` de la lista generada por ```tokenize``` y procesa dichos elementos en orden FIFO:

 - Si encuentras un número, insértalo en la fila resultante.
 - Si encuentras un paréntesis izquierdo ```(```, insértalo en la pila.
 - Si encuentras un operador ⊗ (donde ⊗ puede ser ```+```, ```-```, ```*``` o ```/)```, realiza lo siguiente:
    - Mientras que la pila no esté vacía y además el tope de la pila sea diferente al paréntesis izquierdo ```(```, realiza lo siguiente:
        - Si el elemento del tope de la pila tiene mayor precedencia que ⊗, entonces hay que sacar dicho elemento de la pila e insertarlo en la fila resultante. De lo contrario se debe terminar el ciclo «mientras» más anidado. Si el elemento del tope de la pila tiene mayor precedencia que ⊗, entonces hay que sacar dicho elemento de la pila e insertarlo en la fila resultante. De lo contrario se debe terminar el ciclo «mientras» más anidado.
    - Inserta ⊗ en la pila.
 - Si encuentras un paréntesis derecho ```)```, realiza lo siguiente:
     - Mientras que la pila no esté vacía y además el tope de la pila sea diferente al paréntesis izquierdo ```(```, realiza lo siguiente:
         - Saca el elemento del tope de la pila e insértalo en la fila resultante.
     - Si la pila no está vacía, remueve el paréntesis izquierdo ```(``` del tope de la pila.

<br>Si, al llegar a este punto, la pila no está vacía, remueve uno por uno todos elementos de la pila e insértalos en la fila resultante.

<br>Finalmente, devuelve una cadena conformada por la concatenación de todos los elementos de la fila resultante, usando un espacio en blanco como separador entre elementos.

<br>Todas las funcionalidades deberán de estar correctamente alineadas y documentadas.&nbsp; Recuerda que todas las funcionalidades deberán pasar exitosamente todas las pruebas. Como parte de la documentación deberá incluirse la complejidad de cada una de ellas.

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>

- **80%** - Para cada una de las funcionalidades se evaluará:

    - **Excelente (80%)** - pasa correctamente todos los casos de prueba.
    - **Muy Bien (60%)** - pasa correctamente el 75% de los casos de prueba.
    - **Bien (40%)** - pasa correctamente el 50% de los casos de prueba.
    - **Insuficiente (20%)** - pasa correctamente menos del 50% de los casos de prueba.


- **10%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación: <span class="instructure_file_holder link_holder">[liga_estándar_codificación](estandar.pdf)</span>
- **10%** - Se respetan los nombres de las funciones en la aplicación.

## <span style="color: rgb(26, 99, 169);">**¿Dónde la entrego?**</span>
Entrega los archivos correspondientes de la actividad, en el sitio de Github. Coloca la liga del repositorio en Canvas.
