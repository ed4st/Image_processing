#ifndef __IMG3D__H__
#define __IMG3D__H__

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "Img2d.h"
#include "pixel.h"

class Img3d{
 

    private:
        std::string nombre_base;
	std::vector<Img2d> volumen;  
        int tamanho;//hace referencia al número de imágens
        
    public:
    //gets y sets
    Img3d();
    virtual ~Img3d();
    Pixel menor_pixel(Pixel pixel1,Pixel pixel2);
    Pixel mayor_pixel(Pixel pixel1,Pixel pixel2);
    std::vector<Img2d> Get_volumen();
    void Set_volumen(std::vector<Img2d> nvolumen);
    int Get_tamanho();
    void Set_tamanho(int tamanho);
    void cargar_volumen(std:: string nombre_base, int tamanho);
    std::vector<std::vector<Pixel> > Proyectar_z_min();
    void print();
    void proyeccion2D (char direccion, std::string criterio, std::string nombre_archivo);
    
   
};
#endif
