# actividad-integradora-1
Actividad Integradora 1: Análisis de Transmisiones
Integrantes del Equipo
Jaime Esteban Ochoa De La Torre - A01643234

Edgardo Medina - A01614376

Patricio Blanco Rafols - A01642057

Descripción del Proyecto
Este proyecto es una herramienta de análisis de archivos de texto desarrollada en C++. El programa realiza tres tareas principales sobre archivos de transmisiones de datos:

Detección de Código Malicioso: Busca secuencias de código (definidas en archivos mcode) dentro de dos archivos de transmisión principales.

Búsqueda de Palíndromos: Identifica y reporta la posición del "código espejeado" (palíndromo) más largo dentro de cada archivo de transmisión.

Análisis de Similitud: Encuentra el substring común más largo entre los dos archivos de transmisión para determinar su grado de similitud.

¿Cómo Compilar y Ejecutar?
Requisitos
Un compilador de C++ (como g++).

Tener los 5 archivos de texto de entrada en la misma carpeta que el ejecutable.

Pasos para la Ejecución
Compilar el programa: Abre una terminal en el directorio del proyecto y ejecuta el siguiente comando:

g++ Actividad_Integradora_1.cpp -o analisis_transmisiones

Ejecutar el programa: Una vez compilado, ejecuta el programa con el siguiente comando:

./analisis_transmisiones

Archivos de Entrada Requeridos:
El programa buscará automáticamente los siguientes cinco archivos en el mismo directorio:

transmission1.txt

transmission2.txt

mcode1.txt

mcode2.txt

mcode3.txt