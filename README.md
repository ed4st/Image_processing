# Image_processing

# Descripción del proyecto
- El objetivo del presente proyecto es construir un sistema que incluya algunos componentes para el procesamiento de
  imágenes en escala de grises.
# Componentes del sistema
* Componente 1: Proyección de imágenes 3D
* Componente 2: Compresión de imágenes con árboles de Huffman
* Componente 3: Segmentación de imágenes con grafos.

## 1. Formato de imágenes

Las únicas entradas requeridas por el sistema son las imágenes a procesar. De acuerdo al componente, las entradas y salidas pueden ser una única imagen, o pueden ser varias imágenes. En cualquier caso, se utilizará siempre el formato PPM (Netpbm color image format)2 para almacenar las imágenes. El archivo de imagen corresponde a un archivo de texto (caracteres en formato ASCII), con la siguiente estructura:
```
P3

#Algún comentario acerca del archivo...
W H
M
r1(1,1) g1(1,1) b1(1,1) r1(2,1) g1(2,1) b1(2,1) ... r1(W,1) g1(W,1) b1(W,1)
r1(1,2) g1(1,2) b1(1,2) r1(2,2) g1(2,2) b1(2,2) ... r1(W,2) g1(W,2) b1(W,2)
...
r1(1,H) g1(1,H) b1(1,H) r1(2,H) g1(2,H) b1(2,H) ... r1(W,H) g1(W,H) b1(W,H)
```

Donde:
- P3 es un código (número mágico) que identifica el formato de la imagen (PPM en ASCII). En nuestro caso siempre utilizaremos el mismo código.
- Las líneas que empiezan con el carácter `#` son comentarios.
- W y H son números enteros positivos. Representan respectivamente el ancho y el alto de la imagen en pixeles.

- M es un número entero positivo. Representa el valor de píxel más grande de la imagen, es decir, la intensidad máxima presente en la imagen. Este valor no debería ser mayor a 255.

- r1(i,j) es el valor de rojo del píxel de la imagen ubicado en la coordenada bidimensional (i,j), donde 1≤i≤W y 1≤j≤H. Este valor debe estar en el rango 0 a 255.
- g1(i,j) es el valor de verde del píxel de la imagen ubicado en la coordenada bidimensional (i,j), donde 1≤i≤W y 1≤j≤H. Este valor debe estar en el rango 0 a 255.
- b1(i,j) es el valor de azul del píxel de la imagen ubicado en la coordenada bidimensional (i,j), donde 1≤i≤W y 1≤j≤H. Este valor debe estar en el rango 0 a 255.
## 2. Componentes del sistema

A continuación se describen los componentes individuales que conforman el presente proyecto:

### 2.1. Componente 1: Proyección de imágenes

### Objetivo: 
A partir de una serie ordenada de imágenes que conforman un volumen 3D, construir la proyección volumen hacha en un plano de acuerdo a una dirección y a un criterio de proyección.
La proyección de imágenes tridimensionales hace referencia a la generación de una representación planar (2D) de un objeto esencia 3D. Un tipo particular de proyección es comúnmente utilizado para la producción de radiografías. En este caso, el objeto a visualizar es bombardeado por una serie de rayos X, paralelos entre sí y perpendiculares a la superficie de captura. La cantidad de energía del rayo que alcanza a atravesar el objeto se refleja en la superficie de captura, donde queda plasmada la imagen de la proyección. Este proceso se ilustra en la Figura 3.

![image](https://github.com/ed4st/Image_processing/assets/61949882/629c3067-e530-4cb0-8543-f3d52f19c591)


De esta forma, el componente 1 del sistema corresponderá a una simulación del proceso de captura de radiografías. Para esto, se recibirá una serie ordenada de imágenes 2D, es decir, un conjunto de imágenes que juntas (en un orden específico) representan una escena 3D. Luego, se simulará el proceso de proyección analizando linealmente la información del volumen en una dirección específica, es decir, colapsando la información contenida en cada una de las filas del volumen en un solo pixel. Esto generará una proyección 2D de la imagen volumétrica en la dirección especificada. El componente se implementará en los siguientes comandos:

- **comando:** `cargar_volumen <nombre_base> <n_im>`
  - **salida en pantalla:**
    - (proceso satisfactorio) El volumen `<nombre_base>` ha sido cargado
    - (mensaje de error) El volumen `<nombre_base>` no ha podido ser cargado
  - **descripción:** El comando debe cargar en memoria (en la estructura más adecuada) la serie ordenada de imágenes identificada con el `<nombre_base>` y cuyo tamaño corresponde a `<n_im>` imágenes (la serie podrá tener máximo 99 imágenes). Todas las imágenes de la serie deben estar nombradas como `<nombre_base>xx.ppm`, donde xx corresponde a dos dígitos de identificación de la posición de la imagen en la serie (varía en el rango 01 - `<n_im>`). Una vez cargada toda la información en memoria, el comando debe mostrar el mensaje de carga satisfactoria. Si por alguna razón no es posible cargar completamente la serie ordenada de imágenes (nombre de base erróneo, cantidad de imágenes no corresponde, error en alguna imagen), el comando debe mostrar el mensaje de error.

- **comando:** `proyeccion2D <dirección> <criterio> <nombre_archivo.ppm>`
  - **salida en pantalla:**
    - (proceso satisfactorio) La proyección 2D del volumen en memoria ha sido generada
    - (mensaje de error) La proyección 2D del volumen en memoria no ha podido ser generada
  - **descripción:** El comando debe tomar la serie ordenada de imágenes (ya cargada en memoria), y de acuerdo a la dirección especificada por el usuario, debe recorrer cada posición en el plano perpendicular a la dirección dada, y para cada una debe colapsar toda la información existente en el volumen. La dirección puede ser una entre x (en dirección de las columnas), y (en dirección de las filas) o z (en dirección de la profundidad). El criterio puede ser uno entre mínimo (el valor mínimo de intensidad de cada canal de color), máximo (el valor máximo de intensidad de cada canal de color), promedio (el valor promedio de intensidad de cada canal de color) o mediana (el valor mediana de intensidad de cada canal de color). Una vez generada la proyección, debe guardarse como imagen en formato PPM como `<nombre_archivo.ppm>`. La Figura 4 ilustra el proceso de proyección en cada una de las posibles direcciones.

![image](https://github.com/ed4st/Image_processing/assets/61949882/539cc644-a430-4a25-8b8a-62eb64eaa35a)

## 2.2. Componente 2: Codificación de imágenes

### Objetivo
Utilizar el algoritmo de codificación de Huffman para comprimir y descomprimir imágenes.

Un principio muy importante alrededor de la compresión de datos es codificar cada símbolo de un mensaje usando la cantidad mínima posible de bits. Por ejemplo, si un mensaje estuviera escrito en lenguaje ASCII, el cual tiene 256 símbolos diferentes, la cantidad mínima de bits necesaria sería de 8. Otro principio esencial es que, aquellos símbolos que aparecen más frecuentemente en un mensaje, sería útil codificarlos con menos bits que aquellos menos frecuentes, de tal forma que el mensaje comprimido ocupe el menor espacio posible.

La codificación de Huffman[3] tiene en cuenta los dos principios anteriores. Provee una forma de representar cada símbolo de un mensaje con la menor cantidad posible de bits, y al mismo tiempo permite codificar cada símbolo con una cantidad variable de bits, dependiendo de su frecuencia de ocurrencia en el mensaje. Para realizar el proceso de codificación y decodificación, se utiliza un árbol de Huffman. Éste es un árbol binario que representa una codificación de un conjunto de símbolos óptima: el símbolo que tenga una frecuencia más alta (i.e. el que más se repita) se representa con un número pequeño de bits. Un símbolo poco frecuente se representa con más bits. Un ejemplo de un árbol de Huffman se muestra en la Figura 5.

![image](https://github.com/ed4st/Image_processing/assets/61949882/9ff16e58-f876-41c4-ae17-9ea4be7dcb37)

[3]: http://en.wikipedia.org/wiki/Huffman_coding
Por ejemplo, la siguiente matriz de datos (imagen donde cada fila empieza y termina con el símbolo '+'):

![image](https://github.com/ed4st/Image_processing/assets/61949882/1eedf4a9-4f4a-45e7-8dc9-fd9a6f6a58d2)


Tiene las siguientes características:

- Ancho de la imagen (W) = 36.
- Alto de la imagen (H) = 10.
- Valor (intensidad) máximo posible de la imagen (M) = 255.

Los caracteres (que hacen las veces de intensidades) y sus frecuencias son:

- ASCII = 32, caracter = ' ', frecuencia = 153
- ASCII = 33, caracter = '!', frecuencia = 1
- ASCII = 40, caracter = '(', frecuencia = 2
- ASCII = 41, caracter = ')', frecuencia = 3
- ASCII = 43, caracter = '+', frecuencia = 20
- ASCII = 45, caracter = '-', frecuencia = 105
- ASCII = 47, caracter = '/', frecuencia = 1
- ASCII = 60, caracter = '<', frecuencia = 1
- ASCII = 62, caracter = '>', frecuencia = 1
- ASCII = 83, caracter = 'S', frecuencia = 1
- ASCII = 92, caracter = '\\', frecuencia = 6
- ASCII = 94, caracter = '^', frecuencia = 2
- ASCII = 95, caracter = '_', frecuencia = 42
- ASCII = 97, caracter = 'a', frecuencia = 3
- ASCII = 99, caracter = 'c', frecuencia = 3
- ... (continúa la lista para todos los caracteres)
- ASCII = 124, caracter = '|', frecuencia = 7

El árbol asociado es (las hojas tiene asociado un valor "x:Fy", donde "X" es el código del símbolo y "Y" es su frecuencia):

![image](https://github.com/ed4st/Image_processing/assets/61949882/04a119c9-0113-4741-afd9-ef3901adad29)

El objetivo del componente 2 es implementar un árbol de Huffman para codificar y decodificar imágenes en escala de grises. En este contexto, el "mensaje" sería la imagen y los "símbolos" del mensaje serían los diferentes píxeles de la imagen, cada uno con un color (intensidad) específico. En el proceso de codificación, se tomará una imagen en formato PPM y se generará un archivo binario con la correspondiente codificación. El archivo binario tiene la siguiente estructura:

`W H M F0 F1 ... F255 bits...`


Donde:
- "W" y "H" son números enteros positivos de 2 bytes (`unsigned short`). Representan respectivamente el ancho y el alto de la imagen.
- "M" es un número entero positivo de 1 byte (`unsigned char`). Representa el valor de píxel más grande de la imagen, es decir, la intensidad máxima de la imagen.
- Los valores "Fi" son las frecuencias de cada dato posible en la imagen sin importar a cuál canal (color básico) pertenecen. Cada valor se representa con un entero positivo de 8 bytes (`unsigned long`).
- La secuencia "bits" son los bits asociados a la compresión de la imagen: los píxeles están ordenados de la misma forma que en el formato del archivo PPM (fila-columna rojo-verde-azul).

En el proceso de decodificación, se tomará un archivo binario con la imagen codificada (que sigue la estructura presentada anteriormente) y se decodificará, produciendo la correspondiente imagen PPM. De esta forma, el componente completo se implementará en los siguientes comandos:

- **comando:** `codificar_imagen <nombre_imagen.ppm> <nombre_archivo.huffman>`
  - **salida en pantalla:**
    - (proceso satisfactorio) La imagen `<nombre_imagen.ppm>` ha sido codificada exitosamente
    - (mensaje de error) La imagen `<nombre_imagen.ppm>` no ha podido ser codificada
  - **descripción:** El comando debe cargar en memoria (en la estructura más adecuada) la imagen identificada con `<nombre_imagen.ppm>` y luego debe generar el archivo de texto con la correspondiente codificación de Huffman, almacenándolo de esta forma en el nombre `<nombre_archivo.huffman>`.

- **comando:** `decodificar_archivo <nombre_archivo.huffman> <nombre_imagen.ppm>`
  - **salida en pantalla:**
    - (proceso satisfactorio) El archivo `<nombre_archivo.huffman>` ha sido decodificado exitosamente
    - (mensaje de error) El archivo `<nombre_archivo.huffman>` no ha podido ser decodificado
  - **descripción:** El comando debe cargar en memoria (en la estructura más adecuada) la información de decodificación contenida en el archivo `<nombre_archivo.huffman>` y luego debe generar la correspondiente imagen decodificada en formato PPM, almacenándola en disco bajo el nombre `<nombre_imagen.ppm>`.


## 2.3. Componente 3: Componentes conectados en imágenes

### Objetivo
Segmentar una imagen a partir de unas semillas dadas por el usuario. Un tipo particular de imágenes se conocen como etiquetadas, es decir, imágenes con diferentes regiones de color que representan información de interés, como los departamentos en un mapa geográfico o las regiones funcionales del cerebro.

La segmentación se realiza de la siguiente forma:

1. El usuario provee una imagen y una secuencia de semillas. Cada semilla se compone de tres datos: "x y l", donde "x" y "y" es la coordenada de un píxel en la imagen y "l" es un valor de etiqueta que tiene un valor entre 1 y 255.

2. La imagen se considera un grafo, donde cada píxel es un nodo del grafo; y cada nodo está conectado con sus vecinos de "arriba", "abajo", "izquierda" y "derecha".

3. A partir de cada semilla, se lanza una instancia del algoritmo de Dijkstra. El costo de cada arista está dado por la distancia euclidiana entre los colores. Por ejemplo, los píxeles [10,11] y [10,10] son vecinos, entonces el costo de su conexión es:
  - C([10,11], [10,10]) = √((r[10,11] − r[10,10])² + (g[10,11] − g[10,10])² + (b[10,11] − b[10,10])²)

4. La etiqueta final de un píxel es aquella asociada a la instancia del algoritmo de Dijkstra que lo alcance primero.

El componente 3 se encargará entonces de segmentar una imagen PPM a partir de un conjunto de semillas dadas por el usuario, esto se implementará con los siguientes comandos:

- **comando:** `segmentar <entrada_imagen.ppm> <salida_imagen.ppm> sx1 sy1 sl1 sx2 sy2 sl2 ...`
- **salida en pantalla:**
 - (proceso satisfactorio) La imagen en `<entrada_imagen.ppm>` fue segmentada correctamente y guardada en `<salida_imagen.ppm>`.

 - (mensaje de error) La imagen `<entrada_imagen.ppm>` no pudo ser segmentada.
- **descripción:** El comando debe cargar en memoria (en la estructura más adecuada) la imagen identificada con `<entrada_imagen.ppm>` y el conjunto de semillas correspondiente. La imagen con las etiquetas debe quedar guardada en `<salida_imagen.ppm>`.


