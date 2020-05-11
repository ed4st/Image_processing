#ifndef __IMG2D__H__
#define __IMG2D__H__

#include <vector>
#include <fstream>
#include "pixel.h"
#include <string.h>




//------------------------clase imagen dos dimensional--------------------
class Img2d{
    protected:
        std::string nombre_basexx;
        std::vector<std::vector<Pixel> > imagen2d;    
        int largo;
        int alto;
		
        
    public:
		Img2d();
		virtual ~Img2d();
		void print();
		void Set_imagen2d(std::vector<std::vector<Pixel>>pixeles);
		void cargarimg2d();
		std::vector<std::vector<Pixel> > Get_imagen2d();
		void Set_nombre_basexx(std::string nombre);  
		Pixel mayor_pixel(Pixel pixel1,Pixel pixel2 );
		Pixel promediar(Pixel pixel1,Pixel pixel2);	
		Pixel menor_pixel(Pixel pixel1,Pixel pixel2);  
		void Set_largo(int largo);
		void Set_alto(int alto);	
		std::string Get_nombre_basexx();
		int Get_largo( );
		int Get_alto();
		void crear_ppm(std::string mippmfile);




		std::vector<Pixel> Proyectar_x_min();
		std::vector<Pixel> Proyectar_x_max();
		std::vector<Pixel>  Proyectar_x_promedio();
		std::vector<Pixel>  Proyectar_x_mediana();
		
		std::vector<Pixel> Proyectar_y_min();
		std::vector<Pixel> Proyectar_y_max();
		std::vector<Pixel>  Proyectar_y_promedio();
		std::vector<Pixel> Proyectar_y_mediana();
		//####################################la siguiente función es para la segunda entrega ########################
		void codificar_Huffman(std::string nombre);
		void decodificar_Huffman(std::string nombre);

		//####################################la siguiente función es para la tercera entrega ########################
		void segmentar(std::string nombre,std::vector<std::vector<int> > seeds);
		
		
	       
	//----------------------------------------------------------------
	};
#endif
