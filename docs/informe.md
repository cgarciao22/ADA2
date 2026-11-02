# Informe 

## Deducción de la identidad de Karatsuba
Para entender la ventaja algorítmica de Karatsuba en la multiplicación de numeros enteros grandes frente a la multiplicación clásica, primero se debe entender el método tradicional.

Para multiplicar dos numeros enteros  $x$ e $y$ de $n$ dígitos en base $B$ (en este caso $B$ = 10), se parten ambos numeros por la mitad ($m = n/2$). 
$x = x_1 \cdot B^m + x_0$ 
$y = y_1 \cdot B^m + y_0$
Siendo $x_1 y y_1$ las primeras mitades del entero y $x_0 y y_0$ las segundas mitades. 
Para multiplicar $x \cdot y$ usando Divide y Vencerás, se reemplaza cada número por su representación descompuesta:
$$x \cdot y = (x_1 \cdot B^m + x_0) \cdot (y_1 \cdot B^m + y_0)$$
De manera en que $x_1$ y $y_1$, al ser las priemeras mitades del número representado, se desplazan m posiciones hacia la izquierda (agregandole m ceros a la derecha) y devolverle su valor real, ya que $x != x_1 + x_0$ Ejemplo: $x = 5842$. $58 + 42 = 100$ pero $58 * 100 = 5800$ y entonces se logra una representación fiel al valor del número $58 + 42 = 5842$

Como resultado de aplicar la propiedad distributiva en la ecuación: $$x \cdot y = x_1 y_1 \cdot B^{2m} + (x_1 y_0 + x_0 y_1) \cdot B^m + x_0 y_0$$, se deben hacer 4 multiplicaciones independientes a los productos resultantes de tamaño $n/2$ para obtener la respuesta. 
1. $x_1 \cdot y_1$ 
2. $x_1 \cdot y_0$ 
3. $x_0 \cdot y_1$ 
4. $x_0 \cdot y_0$ 







