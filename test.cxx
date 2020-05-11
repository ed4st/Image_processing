#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm> 
#include "Img3d.h"
#include "Img2d.h"
#include "pixel.h"
#include "Graph.h"

int main() {
  
  
  
  
  std::vector<std::vector<int> > seeds_example;
  std::vector<int> seed1, seed2, seed3;// It can continue. Depends on what the teacher entry
  seed1.push_back(0);//here is the x coordinate of first seed
  seed1.push_back(0);//here is the y coordinate of first seed
  seed1.push_back(78);//here is the "hue" that assign the color of first seed

  seed2.push_back(30);//here is the x coodinate of second seed
  seed2.push_back(20);//here is the y coodinate of second seed
  seed2.push_back(128);//here is the "hue" that assign the color of second seed
  
  seed3.push_back(40);//here is the x coodinate of third seed
  seed3.push_back(40);//here is the y coodinate of third seed
  seed3.push_back(255);//here is the "hue" that assign the color of third seed

  //NOTE: the "hue" has been selected by me. You can check that 255 "hues" have been reduced to 8
  //they are: 
  

  seeds_example.push_back(seed1);
  seeds_example.push_back(seed2);
  seeds_example.push_back(seed3);
  //std::cout<<seeds_example.size();
  Img2d imagen;
  imagen.Set_nombre_basexx("cutimg01.ppm");
  imagen.cargarimg2d();
  imagen.segmentar("segmentada.ppm",seeds_example);
  
  
  
  
  
  
  
  
  
  
  /*
  std::string cadena;
  std::string nombre_base;
  std::string n_im;
  std::string direccion;
  std::string criterio;
  std::string nombre_archivo;
  unsigned short det_error = 0;
  unsigned short num_imagenes = 0;
  Img3d volumen;
  
  std::cout << "-----------BIENVENIDO----------" << std::endl;
  std::cout << "Escriba <<help>> para consultar menu de comandos" << std::endl;
  std::cout << "Escriba <<exit>> para salir" << std::endl;

  char temporal[500];
  std::string auxiliar;

  do {
    std::cout<<">>";
    std::getline(std::cin, cadena);
    
    char * ptr;
    std::strcpy(temporal, cadena.c_str());
    ptr = std::strtok(temporal, " ");
    auxiliar = std::string(ptr);
    if (auxiliar == "cargar_volumen") {
        
      ptr = std::strtok(NULL, " ");

      auxiliar = std::string(ptr);
      nombre_base = auxiliar;

      ptr = std::strtok(NULL, " ");
      auxiliar = std::string(ptr);
      n_im = auxiliar;

      char numeroImagenes[1000];
      std::strcpy(numeroImagenes, n_im.c_str());
      num_imagenes = atoi(numeroImagenes);

      volumen.cargar_volumen(nombre_base, num_imagenes);
      /*if (det_error == num_imagenes) {
        std::cout << "El volumen se cargo correctamente" << std::endl;
      } else if (det_error < num_imagenes && det_error > 0) {
        unsigned short resta = num_imagenes - det_error;
        std::string s_cadena = std::to_string(resta);
        std::cout << "Hubo error en " << s_cadena << "imagenes" << std::endl;
      } else if (det_error == 0) {
        std::cout << "Error en el nombre del volumen" << std::endl;
      }  //########################acá va comentario####################################
    } else if (auxiliar == "proyeccion2D") {
      ptr = std::strtok(NULL, " ");
      auxiliar = std::string(ptr);
      direccion = auxiliar;
        char direccion1 = direccion[0];
      ptr = std::strtok(NULL, " ");
      auxiliar = std::string(ptr);
      criterio = auxiliar;

      ptr = std::strtok(NULL, " ");
      auxiliar = std::string(ptr);
      nombre_archivo = auxiliar;

    
      volumen.proyeccion2D( direccion1,criterio, nombre_archivo);
    } else if (auxiliar == "codificar_imagen") {
        Img2d imagen_a_codificar;
        
      std::string entrada, salida;
      ptr = std::strtok(NULL," ");
      auxiliar = std::string(ptr);
      entrada = auxiliar;
        imagen_a_codificar.Set_nombre_basexx(entrada);
        imagen_a_codificar.cargarimg2d();
      ptr = std::strtok(NULL, " ");
      auxiliar = std::string(ptr);
      salida = auxiliar;
      imagen_a_codificar.codificar_Huffman( salida);

    } else if (auxiliar == "decodificar_imagen") {
        
        

      std::string entrada, salida;
      ptr = std::strtok(NULL," ");
      auxiliar = std::string(ptr);
      entrada = auxiliar;
        
      ptr = std::strtok(NULL, " ");
      auxiliar = std::string(ptr);
      salida = auxiliar;
      Img2d imagen_a_decodificar;
        imagen_a_decodificar.Set_nombre_basexx(salida);
      imagen_a_decodificar.decodificar_Huffman(entrada);
      //sis.descomprimir(entrada, salida);
      
    }
      else if (auxiliar == "help") {
      std::cout << "comando 1: cargar_volumen <nombre_base> <numero de imagenes>" << std::endl;
      std::cout << "comando 2: proyeccion2D <direccion> <criterio> <nombre_archivo.ppm> " << std::endl;
      std::cout << "comando 3: codificar_imagen <nombre_imagen.ppm> <nombre_archivo.huffman>>" << std::endl;
      std::cout << "comando 4: decodificar_imagen <nombre_archivo.huffman> <nombre_imagen.ppm>" << std::endl;
    } else {
      std::cout << auxiliar << " no es un comando válido o faltan parámetros" << std::endl;
    }
  } while (auxiliar != "exit");*/
}
   