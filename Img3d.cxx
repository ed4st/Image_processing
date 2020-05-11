#ifndef __IMG3D__CXX__
#define __IMG3D__CXX__

#include <iostream>
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

   
Pixel Img3d::mayor_pixel(Pixel pixel1,Pixel pixel2){
        Pixel mayor_pixel;
        std::vector<int> p1 = pixel1.Get_pixel();
        std::vector<int> p2 = pixel2.Get_pixel();
        
        int r,g,b;
        r=0;g=0;b=0;
        
        if(p1[0]>=p2[0]){
            r=p1[0];
        }else{
            r=p2[0];
        }
        
        if(p1[1]>=p2[1]){
            g=p1[1];
        }
        else{
            g=p2[1];
        }
        
        if(p1[2]>=p2[2]){
            b=p1[2];
        }
        else{
            b=p2[2];
        }
        mayor_pixel.Set_pixel(r,g,b);
        return mayor_pixel;
}  
//----------la siguiente funcion calcula el "menor" entre dos pixeles"--
Pixel Img3d:: menor_pixel(Pixel pixel1,Pixel pixel2){
        Pixel menor_pixel;
        std::vector<int> p1 = pixel1.Get_pixel();
        std::vector<int> p2 = pixel2.Get_pixel();
        
        int r,g,b;
        r=0;g=0;b=0;
        
        if(p1[0]<=p2[0]){
            r=p1[0];
        }else{
            r=p2[0];
        }
        
        if(p1[1]<=p2[1]){
            g=p1[1];
        }
        else{
            g=p2[1];
        }
        
        if(p1[2]<=p2[2]){
            b=p1[2];
        }
        else{
            b=p2[2];
        }
        menor_pixel.Set_pixel(r,g,b);
        return menor_pixel;
}  

//----------------------------------------------------------------
Img3d::Img3d() {


	std::string nombre_base= "";
	std::vector<Img2d> volumen={};  
        int tamanho=0;//hace referencia al número de imágens
        };

//----------------------------------------------------------------
Img3d::~Img3d(){}; 
//----------------------------------------------------------------    

//gets y sets
//_______________________________________________________
   std::vector<Img2d>Img3d::Get_volumen(){
       
	
	 return volumen;
	
    }

//_______________________________________________________
    void  Img3d:: Set_volumen(std::vector<Img2d> nvolumen){
        this->volumen = nvolumen;
    }
//_______________________________________________________
    int Img3d::  Get_tamanho(){
        return this->tamanho;
    }
//_______________________________________________________   
    void Img3d:: Set_tamanho(int tamanho){
         this->tamanho=tamanho;
    }
    
//_______________________________________________________   
    
            void Img3d:: cargar_volumen(std:: string nombre_base, int tamanho){
            //char nombre[nombrebase.size() + 1];
            
            
            
            this->Set_tamanho(tamanho);
            
            
            for(int i = 1; i<=tamanho; i++){
            std::string nombre; 
                Img2d imagen;
                if (i<10){
                    
                    
                    nombre = nombre_base + std::to_string(0);
                    nombre = nombre + std::to_string(i);
                    nombre = nombre + ".ppm";
                }
                else{
                    nombre = nombre_base + std::to_string(i);
                    nombre = nombre + ".ppm";
                }
                
                imagen.Set_nombre_basexx(nombre);
                imagen.cargarimg2d();
                volumen.push_back(imagen);
                
            
            }
            std::cout<<"imágenes cargadas correctamente!"<<std::endl;
            
            
	
            
        }
        
 
    
 //Métodos de proyeccion en Z
 
 std::vector<std::vector<Pixel> > Img3d:: Proyectar_z_min(){
            std::vector<std::vector<Pixel> > proyeccion_z_min;
            
            
            std::vector<Img2d> copia3d, Img_temp;
            copia3d=volumen;
            
            
            
            Pixel pixel_temp;
            /*
           
            for(int t=0;t<tamanho-1;t++){
         
		       	for(int i=0; i<copia3d[0].size();i++){
		            pixel_temp.Set_pixel(255, 255,255);
		            for(int j=0; j<copia3d[0][0].size();j++){
		            
		                          
		                pixel_temp=menor_pixel(pixel_temp,menor_pixel(copia3d[t+1][i][j],copia3d[t][i][j]));
		                  
		            }
		        	//proyeccion_y_min.push_back(pixel_temp);
		        }
              
          
            
        
        }*/
        return proyeccion_z_min;
        
        
        }
        
//-------------------------------------------------------------
        void Img3d::  print(){
        typedef std::vector<Img2d> vol;
        for(vol::iterator it = volumen.begin();it != volumen.end(); it++)
            it->print();
        }
//---------------------------------------------------------------

        void Img3d::proyeccion2D (char direccion, std::string criterio, std::string nombre_archivo){
        	
        	
        
    		

            Img2d proyeccion;
            std::vector<std::vector<Pixel> > imagen2d;
            
            
            
            
            
            
            

            if(direccion == 'x' || direccion == 'X'){
                //proyeccion.Set_alto(proyeccion.Get_largo());
                //proyeccion.Set_largo(tamanho);  
                
                
                if(criterio == "minimo"||criterio == "MINIMO"){
                    
                    for(int i = 0; i<tamanho;i++){
                          std::vector<Pixel> vect_pix_temp;
                    
                    vect_pix_temp = volumen[i].Proyectar_x_min();
                    imagen2d.push_back(vect_pix_temp);
                            
                    }
                                     
                
                     
                    proyeccion.Set_imagen2d(imagen2d);
                   
                    proyeccion.Set_alto(tamanho);
                    proyeccion.Set_largo(volumen[0].Get_imagen2d().size());
                }
                if(criterio == "maximo" ||criterio == "MAXIMO"){

                      
                    for(int i = 0; i<tamanho;i++){
                          std::vector<Pixel> vect_pix_temp;
                    
                    vect_pix_temp = volumen[i].Proyectar_x_max();
                    imagen2d.push_back(vect_pix_temp);
                            
                    }
                                     
                
                     
                    proyeccion.Set_imagen2d(imagen2d);
                   
                    proyeccion.Set_alto(tamanho);
                    proyeccion.Set_largo(volumen[0].Get_imagen2d().size());

                }
                if(criterio == "promedio"||criterio == "PROMEDIO"){

                      
                    for(int i = 0; i<tamanho;i++){
                          std::vector<Pixel> vect_pix_temp;
                    
                    vect_pix_temp = volumen[i].Proyectar_x_promedio();
                    imagen2d.push_back(vect_pix_temp);
                            
                    }
                                     
                
                     
                    proyeccion.Set_imagen2d(imagen2d);
                   
                    proyeccion.Set_alto(tamanho);
                    proyeccion.Set_largo(volumen[0].Get_imagen2d()[0].size());

                }
                if(criterio == "mediana" || criterio == "MEDIANA"){

                      
                    for(int i = 0; i<tamanho;i++){
                          std::vector<Pixel> vect_pix_temp;
                    
                    vect_pix_temp = volumen[i].Proyectar_x_mediana();
                    imagen2d.push_back(vect_pix_temp);
                            
                    }
                                     
                
                     
                    proyeccion.Set_imagen2d(imagen2d);
                   
                    proyeccion.Set_alto(tamanho);
                    proyeccion.Set_largo(volumen[0].Get_imagen2d()[0].size());

                }
              
                  proyeccion.crear_ppm(nombre_archivo + ".ppm");           
            }

            
            if(direccion == 'y'|| direccion == 'Y'){
               
                
                if(criterio == "minimo" ||criterio == "MINIMO"){

                    for(int i = 0; i<tamanho;i++){
                          std::vector<Pixel> vect_pix_temp;
                    
                    vect_pix_temp = volumen[i].Proyectar_y_min();
                    imagen2d.push_back(vect_pix_temp);
                            
                    }
                                     
                
                     
                    proyeccion.Set_imagen2d(imagen2d);
                   
                    proyeccion.Set_alto(tamanho);
                    proyeccion.Set_largo(volumen[0].Get_imagen2d().size());

                }
                if(criterio == "maximo"||criterio == "MAXIMO"){

                    for(int i = 0; i<tamanho;i++){
                          std::vector<Pixel> vect_pix_temp;
                    
                    vect_pix_temp = volumen[i].Proyectar_y_max();
                    imagen2d.push_back(vect_pix_temp);
                            
                    }
                                     
                
                     
                    proyeccion.Set_imagen2d(imagen2d);
                   
                    proyeccion.Set_alto(tamanho);
                    proyeccion.Set_largo(volumen[0].Get_imagen2d().size());

                }
                if(criterio == "promedio" ||criterio == "PROMEDIO"){

                    for(int i = 0; i<tamanho;i++){
                          std::vector<Pixel> vect_pix_temp;
                    
                    vect_pix_temp = volumen[i].Proyectar_y_promedio();
                    imagen2d.push_back(vect_pix_temp);
                            
                    }
                                     
                
                     
                    proyeccion.Set_imagen2d(imagen2d);
                   
                    proyeccion.Set_alto(tamanho);
                    proyeccion.Set_largo(volumen[0].Get_imagen2d().size());

                }
                if(criterio == "mediana" ||criterio == "MEDIANA"){

                    for(int i = 0; i<tamanho;i++){
                          std::vector<Pixel> vect_pix_temp;
                    
                    vect_pix_temp = volumen[i].Proyectar_y_mediana();
                    imagen2d.push_back(vect_pix_temp);
                            
                    }
                                     
                
                     
                    proyeccion.Set_imagen2d(imagen2d);
                   
                    proyeccion.Set_alto(tamanho);
                    proyeccion.Set_largo(volumen[0].Get_imagen2d().size());

                }
              proyeccion.crear_ppm(nombre_archivo + ".ppm");
                             
            }
            
            
            
            if(direccion == 'z'|| direccion == 'Z'){
                
                
                
                
                if(criterio == "minimo"||criterio == "MINIMO"){
                    std::vector< std::vector < Pixel> > proyeccion_z_min;
                    
                    

                    for(int i = 0; i < volumen[0].Get_imagen2d().size(); i++)
                    {
                        
                        std::vector < Pixel> proyeccion_z_min_vector;
                        for(int j = 0; j < volumen[0].Get_imagen2d()[0].size(); j++)
                        {
                            Pixel min;
                            min.Set_pixel(255,255,255);
                            
                            for(int k = 0; k < tamanho; k++)
                            {
                                min = menor_pixel(min,volumen[k].Get_imagen2d()[i][j]);
                               
                            }
                            //min.print();
                            proyeccion_z_min_vector.push_back(min);

                        }
                        proyeccion_z_min.push_back(proyeccion_z_min_vector);

                        
                    }
                    Img2d proyeccion_z_min1;
                    proyeccion_z_min1.Set_imagen2d(proyeccion_z_min);
                    proyeccion_z_min1.Set_alto(volumen[0].Get_imagen2d().size());
                    proyeccion_z_min1.Set_largo(volumen[0].Get_imagen2d()[0].size());

              
                    proyeccion_z_min1.crear_ppm(nombre_archivo + ".ppm");
                   
                }

                if(criterio == "maximo"||criterio == "MAXIMO"){
                    std::vector< std::vector < Pixel> > proyeccion_z_max;
                    proyeccion_z_max = this->Get_volumen()[0].Get_imagen2d();
                    std::cout<<this->Get_volumen()[0].Get_imagen2d().size();
                    
                    for(int j = 0; j < this->Get_volumen()[0].Get_imagen2d().size(); j++)
                    {
                                
                            for(int k = 0; k < this->Get_volumen()[0].Get_imagen2d()[0].size(); k++)
                            {
                                Pixel ptemp;
                                ptemp.Set_pixel(0,0,0); 
                                proyeccion_z_max[j][k]=ptemp;
                            }
                            

                    } 
                    
                    int r,g,b; r=0;b=0;g=0;
                    for(int i = 0; i < tamanho; i++)
                    {
                    for(int j = 0; j < this->Get_volumen()[0].Get_imagen2d().size(); j++)
                    {
                                
                            for(int k = 0; k < this->Get_volumen()[0].Get_imagen2d()[0].size(); k++)
                            {
                                
                                

                                    if (proyeccion_z_max[j][k].Get_pixel()[0]<=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[0]) {
                                        r=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[0];
                                    }
                                    if (proyeccion_z_max[j][k].Get_pixel()[1]<=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[1]) {
                                        g=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[1];
                                    }

                                    if (proyeccion_z_max[j][k].Get_pixel()[2]<=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[2]) {
                                        b=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[2];
                                    }
                                
                                Pixel ptemp;
                                ptemp.Set_pixel(r,g,b); 
                                proyeccion_z_max[j][k]=ptemp;
                            }
                            

                    } 
                    }
                    Img2d proyeccion_z_min1;
                    proyeccion_z_min1.Set_imagen2d(proyeccion_z_max);
                    proyeccion_z_min1.Set_alto(volumen[0].Get_imagen2d().size());
                    proyeccion_z_min1.Set_largo(volumen[0].Get_imagen2d()[0].size());

              
                    proyeccion_z_min1.crear_ppm(nombre_archivo + ".ppm");


                   
                }
                if(criterio == "promedio"||criterio == "PROMEDIO"){
                    std::vector< std::vector < Pixel> > proyeccion_z_max;
                    proyeccion_z_max = this->Get_volumen()[0].Get_imagen2d();
                    std::cout<<this->Get_volumen()[0].Get_imagen2d().size();
                    
                    for(int j = 0; j < this->Get_volumen()[0].Get_imagen2d().size(); j++)
                    {
                                
                            for(int k = 0; k < this->Get_volumen()[0].Get_imagen2d()[0].size(); k++)
                            {
                                Pixel ptemp;
                                ptemp.Set_pixel(0,0,0); 
                                proyeccion_z_max[j][k]=ptemp;
                            }
                            

                    } 
                    
                    int r,g,b; r=0;b=0;g=0;
                    for(int i = 0; i < tamanho; i++)
                    {
                    for(int j = 0; j < this->Get_volumen()[0].Get_imagen2d().size(); j++)
                    {
                                
                            for(int k = 0; k < this->Get_volumen()[0].Get_imagen2d()[0].size(); k++)
                            {
                                
                                

                                    if (proyeccion_z_max[j][k].Get_pixel()[0]<=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[0]) {
                                        r=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[0];
                                    }
                                    if (proyeccion_z_max[j][k].Get_pixel()[1]<=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[1]) {
                                        g=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[1];
                                    }

                                    if (proyeccion_z_max[j][k].Get_pixel()[2]<=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[2]) {
                                        b=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[2];
                                    }
                                
                                Pixel ptemp;
                                ptemp.Set_pixel(r,g,b); 
                                proyeccion_z_max[j][k]=ptemp;
                            }
                            

                    } 
                    }
                    Img2d proyeccion_z_min1;
                    proyeccion_z_min1.Set_imagen2d(proyeccion_z_max);
                    proyeccion_z_min1.Set_alto(volumen[0].Get_imagen2d().size());
                    proyeccion_z_min1.Set_largo(volumen[0].Get_imagen2d()[0].size());

              
                    proyeccion_z_min1.crear_ppm(nombre_archivo + ".ppm");


                   
                }
                if(criterio == "mediana"||criterio == "MEDIANA"){
                    std::vector< std::vector < Pixel> > proyeccion_z_max;
                    proyeccion_z_max = this->Get_volumen()[0].Get_imagen2d();
                    std::cout<<this->Get_volumen()[0].Get_imagen2d().size();
                    
                    for(int j = 0; j < this->Get_volumen()[0].Get_imagen2d().size(); j++)
                    {
                                
                            for(int k = 0; k < this->Get_volumen()[0].Get_imagen2d()[0].size(); k++)
                            {
                                Pixel ptemp;
                                ptemp.Set_pixel(0,0,0); 
                                proyeccion_z_max[j][k]=ptemp;
                            }
                            

                    } 
                    
                    int r,g,b; r=0;b=0;g=0;
                    for(int i = 0; i < tamanho; i++)
                    {
                    for(int j = 0; j < this->Get_volumen()[0].Get_imagen2d().size(); j++)
                    {
                                
                            for(int k = 0; k < this->Get_volumen()[0].Get_imagen2d()[0].size(); k++)
                            {
                                
                                

                                    if (proyeccion_z_max[j][k].Get_pixel()[0]<=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[0]) {
                                        r=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[0];
                                    }
                                    if (proyeccion_z_max[j][k].Get_pixel()[1]<=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[1]) {
                                        g=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[1];
                                    }

                                    if (proyeccion_z_max[j][k].Get_pixel()[2]<=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[2]) {
                                        b=this->Get_volumen()[i].Get_imagen2d()[j][k].Get_pixel()[2];
                                    }
                                
                                Pixel ptemp;
                                ptemp.Set_pixel(r,g,b); 
                                proyeccion_z_max[j][k]=ptemp;
                            }
                            

                    } 
                    }
                    Img2d proyeccion_z_min1;
                    proyeccion_z_min1.Set_imagen2d(proyeccion_z_max);
                    proyeccion_z_min1.Set_alto(volumen[0].Get_imagen2d().size());
                    proyeccion_z_min1.Set_largo(volumen[0].Get_imagen2d()[0].size());

              
                    proyeccion_z_min1.crear_ppm(nombre_archivo + ".ppm");


                   
                }
                    
            }
            
            //proyeccion.Set_imagen2d(imagen2d);
            
			






            
        };

#endif



