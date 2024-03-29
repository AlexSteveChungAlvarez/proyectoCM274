# proyectoCM274

Una de las ideas del proyecto es la de generar una función a partir de un conjunto de muestras.
Esto lo logramos a través de una red de perceptrones.

La primera parte, la de aprender, empieza ejecutando el archivo "Ap.r", el cual generará un conjunto de entradas aleatorias con sus respectivas salidas para una función dada, con el objetivo de generar una función que sea aproximadamente correcta. Las entradas son puntos en el plano, restringidos en un cuadrado.

Las muestras creadas se envían al programa en C "rn.c" (que es compilado resultando en "rn.so"), con la implementación de la red, y realizando el aprendizaje con el método de retropropagación. Los pesos asociados a las conexiones entre las neuronas son guardados en el archivo "rnW.txt". Este será sobreescrito cada vez que se ejecute el programa.

Entonces el programa "rnEval.c" podrá recuperar los pesos para ejecutar la red sin que se pierdan cuando se termine el programa.
El script "Ap2.r" da algunos ejemplos de la ejecución de la función para algunos puntos determinados, y "Ap3.r" genera entradas aleatorias para comparar las salidas de la función generada con las de la que se quiso replicar.

Al ejecutar los scripts varias veces y cambiando también las funciones objetivo (alterando el código) hemos observado que la función generada daba valores esperados incluso para valores que no salieron en las muestras. Para comparar mejor, hicimos un programa, "rnEval4.c", que muestra los valores obtenidos en una sección del plano.
Podemos decir que dado un punto aleatorio, es muy probable que obtengamos las salida esperada, o sea, el error para la función generada es bajo.
