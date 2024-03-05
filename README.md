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
`
P3

#Algún comentario acerca del archivo...
W H
M
r1(1,1) g1(1,1) b1(1,1) r1(2,1) g1(2,1) b1(2,1) ... r1(W,1) g1(W,1) b1(W,1)
r1(1,2) g1(1,2) b1(1,2) r1(2,2) g1(2,2) b1(2,2) ... r1(W,2) g1(W,2) b1(W,2)
...
r1(1,H) g1(1,H) b1(1,H) r1(2,H) g1(2,H) b1(2,H) ... r1(W,H) g1(W,H) b1(W,H)
`

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
