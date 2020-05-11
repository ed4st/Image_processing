#ifndef __IMG2D__CXX__
#define __IMG2D__CXX__

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
#include "Graph.h" 
#include <string.h>
#include <cstdlib>
#include <stack>
#include <queue>
#include <math.h>

//----------------------------------------------------------------
    Img2d::Img2d() { 
	std::string nombre_basexx = "";
        std::vector<std::vector<Pixel> > imagen2d={};    
        int largo=0;
        int alto=0;};

//----------------------------------------------------------------
   Img2d::~Img2d(){}; 
//----------------------------------------------------------------
 void Img2d:: print(){
        
        
        
        
        
        for(int i=0; i<imagen2d.size();i++){
                for(int j=0; j<imagen2d[0].size();j++){
                    imagen2d[i][j].print();
                     
                }
                std::cout<<std::endl;
            
        }
        
        
        
        }

//----------------------------------------------------------------
void Img2d::Set_imagen2d(std::vector<std::vector<Pixel>>pixeles){
            
            imagen2d = pixeles;   
                        
        }
//----------------------------------------------------------------
std::vector<std::vector<Pixel> > Img2d::Get_imagen2d(){
            return this->imagen2d;
        }
//----------------------------------------------------------------
void Img2d:: Set_nombre_basexx(std::string nombre){
            this->nombre_basexx = nombre;
        }
//----------------------------------------------------------------
        
void Img2d::Set_largo(int largo){
            this->largo = largo;
        }
//----------------------------------------------------------------
void Img2d::Set_alto(int alto){
            this->alto = alto;
        }
//----------------------------------------------------------------
        
std::string Img2d:: Get_nombre_basexx(){
            return this->nombre_basexx;
        }
//----------------------------------------------------------------
int Img2d::Get_largo( ){
            return this->largo ;
        }
//----------------------------------------------------------------
int Img2d:: Get_alto(){
            return this->alto;
        }
//----------------------------------------------------------------
//****************************************************************
       
Pixel Img2d::mayor_pixel(Pixel pixel1,Pixel pixel2){
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
Pixel Img2d:: menor_pixel(Pixel pixel1,Pixel pixel2){
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
 
//****************************************************************            
void Img2d:: cargarimg2d(){

        std::string x,magic_number;
        
         int  max, W , H;
         std::string comentario;
         std::ifstream inFile;
        
         inFile.open(nombre_basexx.c_str());
         if (!inFile) {
             std::cout << "No se ha podido cargar la imagen: "<<nombre_basexx<<std::endl;
             exit(1); // terminate with error
         }
	        

	        inFile>>x;
	        magic_number = x;
	        // Asignación de encabezados del archivo
	        
	        
 			std::getline(inFile,comentario);
	        
	        inFile>>x;
	        W = std::stoi(x);
            this->largo=W; 
	        inFile>>x;
            H = std::stoi(x);
            this->alto=H;
            inFile>>x;
            max = std::stoi(x);
		
	 
	        for(int i=0; i<H;i++){
	  
                std::vector<Pixel> linea1;
                                
             for(int j=0; j<W;j++){
        
                 Pixel pixeli;
	              int r,g,b; 
    
                    inFile>>x;
                    r=stoi(x);
                    inFile>>x;
                    g=stoi(x);
                    inFile>>x;
                    b=stoi(x);
                    pixeli.Set_pixel(r,g,b);
                    linea1.push_back(pixeli);
    
            }
            imagen2d.push_back(linea1);
   
        }
    
        inFile.close();
    
    
}
//-----------------------------------------------------------------

void Img2d:: crear_ppm(std::string mippmfile){
            std::ofstream myfile;
            
            myfile.open (mippmfile);
            myfile << "P3"<<std::endl;
            myfile <<"# algun comentario xD" <<std::endl;
            myfile << largo <<" ";
            myfile << alto <<std::endl;
            
            
            myfile<<255<<std::endl;
            
            std::vector<std::vector<Pixel> >::iterator it_i;
            
            for(it_i = imagen2d.begin(); it_i!= imagen2d.end();it_i++){
            
                
                std::vector<Pixel> it_temp = *it_i;
                std::vector<Pixel>::iterator it_j;
                for( it_j = it_temp.begin(); it_j!= it_temp.end(); it_j++){
                    std::vector<int> ptemp;
                      ptemp = it_j->Get_pixel();
                      std::vector<int>::iterator pit = ptemp.begin();
                       myfile << *pit<<" ";
                       pit++;
                        myfile << *pit<<" ";
                       pit++;
                        myfile << *pit<<" ";
                      
                
                }
                myfile<<std::endl;
            }
            
    
            
        myfile.close();
        
        }



//--------------------------------------------------------------
std::vector<Pixel>  Img2d:: Proyectar_x_min(){
            std::vector<Pixel> proyeccion_x_min;
            std::vector < std::vector<Pixel> > copia2d;
            copia2d=imagen2d;
            
            std::vector<Pixel> pixel_temps;
            
            
            for(int j=0; j<copia2d[0].size();j++){
                Pixel pixel_temp;
                pixel_temp.Set_pixel(255, 255,255); 
                pixel_temps.push_back(pixel_temp);
                      
                }
            
         
            for(int i=0; i<copia2d.size()-1;i++){
                
                for(int j=0; j<copia2d[0].size();j++){
                
                              
                    pixel_temps[j]=menor_pixel(pixel_temps[j],menor_pixel(copia2d[i][j],copia2d[i+1][j]));
                      
                }
            
            }
              
          
            for(int j=0; j<copia2d[0].size();j++){
                proyeccion_x_min.push_back(pixel_temps[j]);
            }
            return proyeccion_x_min;
        }
//-----------------------------------------------------------        
std::vector<Pixel>  Img2d:: Proyectar_x_max(){
            std::vector<Pixel> proyeccion_x_max;
            
            
            std::vector < std::vector<Pixel> > copia2d;
            copia2d=imagen2d;
            
            std::vector<Pixel> pixel_temps;
            
            
            for(int j=0; j<copia2d[0].size();j++){
                Pixel pixel_temp;
                pixel_temp.Set_pixel(0,0,0); 
                pixel_temps.push_back(pixel_temp);
                      
                }
            
         
            for(int i=0; i<copia2d.size()-1;i++){
                
                for(int j=0; j<copia2d[0].size();j++){
                
                              
                    pixel_temps[j]=mayor_pixel(pixel_temps[j],mayor_pixel(copia2d[i][j],copia2d[i+1][j]));
                      
                }
            
            }
              
          
            for(int j=0; j<copia2d[0].size();j++){
                proyeccion_x_max.push_back(pixel_temps[j]);
            }
            return proyeccion_x_max;
        }
        
 //-----------------------------------------------------------        
std::vector<Pixel>  Img2d:: Proyectar_x_promedio(){
            std::vector<Pixel> proyeccion_x_promedio;
            
            
            std::vector < std::vector<Pixel> > copia2d;
            copia2d=imagen2d;
            
             
            int altura = copia2d.size();
            for(int j=0; j<copia2d[0].size();j++){
            
                int cont_col1 = 0;
                int cont_col2 = 0;
                int cont_col3 = 0;
                Pixel pixel_temp;
                for(int i=0; i<altura;i++){
                    
                    
                    
                    cont_col1 = cont_col1 + copia2d[i][j].Get_pixel()[0] ;      
                    
                    cont_col2 = cont_col2 + copia2d[i][j].Get_pixel()[1] ;      
                    cont_col3 = cont_col3 + copia2d[i][j].Get_pixel()[2] ;      
                    
                     
                }
                pixel_temp.Set_pixel((cont_col1/altura),(cont_col2/altura),(cont_col3/altura));
               
                proyeccion_x_promedio.push_back(pixel_temp);
                
            }
              
         
            return proyeccion_x_promedio;
        }
        
        
         //-----------------------------------------------------------        
std::vector<Pixel>  Img2d:: Proyectar_x_mediana(){
            std::vector<Pixel> proyeccion_x_mediana;
            
            
            std::vector < std::vector<Pixel> > copia2d;
            copia2d=imagen2d;
            
             
            int altura = copia2d.size();
            
            for(int j=0; j<copia2d[0].size();j++){
            
                std::vector<int> cont_col1;
                std::vector<int> cont_col2;
                std::vector<int> cont_col3;
                Pixel pixel_temp;
                
                for(int i=0; i<altura;i++){
                    
                    
                    
                    cont_col1.push_back(copia2d[i][j].Get_pixel()[0]); 
                    cont_col2.push_back(copia2d[i][j].Get_pixel()[1]);
                    cont_col3.push_back(copia2d[i][j].Get_pixel()[2]);     
                    
                     
                }
                
                int n = altura/2;
                sort(cont_col1.begin(),cont_col1.end());
                sort(cont_col2.begin(),cont_col2.end());
                sort(cont_col3.begin(),cont_col3.end());
                
                pixel_temp.Set_pixel(cont_col1[n],cont_col2[n],cont_col3[n]);
                proyeccion_x_mediana.push_back(pixel_temp);
                
            }
              
         
            return proyeccion_x_mediana;
        }

        
        
        
// Métodos de proyeccion en Y

//--------------------------------------------------------------------
std::vector<Pixel>  Img2d:: Proyectar_y_min(){
            std::vector<Pixel> proyeccion_x_max;
            
            
            std::vector < std::vector<Pixel> > copia2d;
            copia2d=imagen2d;
            
            std::vector<Pixel> pixel_temps;
            

         
            for(int i=0; i<copia2d.size();i++){
                int r,g,b;
                r = copia2d[i][0].Get_pixel()[0];
                g = copia2d[i][0].Get_pixel()[1];
                b = copia2d[i][0].Get_pixel()[2];
                for(int j=0; j<copia2d[0].size();j++){
                
                    if (r>=copia2d[i][j].Get_pixel()[0]) {
                        r = copia2d[i][j].Get_pixel()[0];
                    }
                    
                    if (g>=copia2d[i][j].Get_pixel()[1]) {
                        g = copia2d[i][j].Get_pixel()[1];
                    }
                    if (b>=copia2d[i][j].Get_pixel()[2]) {
                        b = copia2d[i][j].Get_pixel()[2];
                    }

                }
                Pixel pixel_temp;
                pixel_temp.Set_pixel(r,g,b); 
                pixel_temps.push_back(pixel_temp);
            }
              
          
            for(int j=0; j<copia2d[0].size();j++){
                proyeccion_x_max.push_back(pixel_temps[j]);
            }
            return proyeccion_x_max;
        }
//--------------------------------------------------------------------
 std::vector<Pixel>  Img2d:: Proyectar_y_max(){
            std::vector<Pixel> proyeccion_x_max;
            
            
            std::vector < std::vector<Pixel> > copia2d;
            copia2d=imagen2d;
            
            std::vector<Pixel> pixel_temps;
            

         
            for(int i=0; i<copia2d.size();i++){
                int r,g,b;
                r = copia2d[i][0].Get_pixel()[0];
                g = copia2d[i][0].Get_pixel()[1];
                b = copia2d[i][0].Get_pixel()[2];
                for(int j=0; j<copia2d[0].size();j++){
                
                    if (r<=copia2d[i][j].Get_pixel()[0]) {
                        r = copia2d[i][j].Get_pixel()[0];
                    }
                    
                    if (g<=copia2d[i][j].Get_pixel()[1]) {
                        g = copia2d[i][j].Get_pixel()[1];
                    }
                    if (b<=copia2d[i][j].Get_pixel()[2]) {
                        b = copia2d[i][j].Get_pixel()[2];
                    }

                }
                Pixel pixel_temp;
                pixel_temp.Set_pixel(r,g,b); 
                pixel_temps.push_back(pixel_temp);
            }
              
          
            for(int j=0; j<copia2d[0].size();j++){
                proyeccion_x_max.push_back(pixel_temps[j]);
            }
            return proyeccion_x_max;
        }
        
        
//-----------------------------------------------------------        
std::vector<Pixel>  Img2d:: Proyectar_y_promedio(){
            std::vector<Pixel> proyeccion_x_max;
            
            
            std::vector < std::vector<Pixel> > copia2d;
            copia2d=imagen2d;
            
           
            
           
           
           
            
            
           for(int i=0; i<copia2d.size();i++){
            
            	Pixel pixel_temp;
            	int r,g,b;
            	r=0;g=0;b=0;
                for(int j=0; j<copia2d[0].size();j++){
                
                              
                    r+=copia2d[i][j].Get_pixel()[0];
                    g+=copia2d[i][j].Get_pixel()[1];
                    b+=copia2d[i][j].Get_pixel()[2];    
                    //std::cout<<r<<std::endl;
                    
                  
                  
                }
                pixel_temp.Set_pixel(r/copia2d[0].size(),g/copia2d[0].size(),b/copia2d[0].size());
                proyeccion_x_max.push_back(pixel_temp);
            
            }
              
            return proyeccion_x_max;
        }
        
        
//-----------------------------------------------------------  
// Function for getting Fibonacci 
// numbers defined outside main 


std::vector<Pixel>  Img2d:: Proyectar_y_mediana(){
            std::vector<Pixel> proyeccion_y_mediana;
            
            
            std::vector < std::vector<Pixel> > copia2d;
            copia2d=imagen2d;
            
             
            int altura = copia2d.size();
            
            for(int i=0; i<altura;i++){
            
                std::vector<int> cont_col1;
                std::vector<int> cont_col2;
                std::vector<int> cont_col3;
                Pixel pixel_temp;
                
                for(int j=0; j<copia2d[0].size();j++) {
                    
                    
                    
                    cont_col1.push_back(copia2d[i][j].Get_pixel()[0]); 
                    cont_col2.push_back(copia2d[i][j].Get_pixel()[1]);
                    cont_col3.push_back(copia2d[i][j].Get_pixel()[2]);     
                    
                     
                }
                
                int n = copia2d[0].size()/2;
                sort(cont_col1.begin(),cont_col1.end());
                sort(cont_col2.begin(),cont_col2.end());
                sort(cont_col3.begin(),cont_col3.end());
                
                pixel_temp.Set_pixel(cont_col1[n],cont_col2[n],cont_col3[n]);
                proyeccion_y_mediana.push_back(pixel_temp);
                
            }
              
         
            return proyeccion_y_mediana;
        }

        
        
        
        




//###########################################   Huffmann  ############################################


//############################la siguiente funcion es de la segunda entrega ###################################
//-----------------------------------------------------------  
    struct dato
    {
        char valor;
        std::string codigo;
    };


    int fib(int n) { 
        if (n <= 1) 
            return n; 
        return fib(n - 1) + fib(n - 2); 
    } 

    void strconcat(char* str, char* parentcode, char add) 
    { 
        int i = 0; 
        while (*(parentcode + i) != '\0') { 
            *(str + i) = *(parentcode + i); 
            i++; 
        } 
        str[i] = add; 
        str[i + 1] = '\0'; 
    } 

    std::vector<dato> caminos(int hist[256], int width, int height);
    std::string buscar_camino(int valor,std::vector<dato> tabla){
        
        char cval = char(valor);
        std::string retorno="";
        for(int i = 0; i < tabla.size(); i++)
        {
            if (cval == tabla[i].valor) {
                retorno = tabla[i].codigo;
            }
            
            
            
        }
        return retorno;
    }

    char binary_to_char(std::string codigo){
        int cint=0;
        while(codigo.length()<8){
            codigo.push_back('0');
        }
        for(int i = 0; i <codigo.length(); i++)
        {
            if (codigo[i]=='1') {
                cint = cint + pow(2,codigo.length()-i-1); 
            }
                
        }
        return(char(cint));    
        
    }


    std::string char_to_binary(char c);






    void Img2d:: codificar_Huffman(std::string nombre_archivo){
                //std::cout<<binary_to_char("1");
                unsigned short W,H;
                W = this->largo;
                H=this->alto;
                unsigned char M='~';


                int hist[256];
                    std::vector<float> probs;
                    for(int k = 0; k < 256; k++)
                                {
                                    unsigned long cont=0;
                                    for(int i = 0; i < this-> imagen2d.size(); i++)
                                    {
                                        for(int j = 0; j < imagen2d[0].size(); j++)
                                        {
                                            if (imagen2d[i][j].Get_pixel()[0]==k) {
                                                cont++;
                                            }
                                            /*if (imagen2d[i][j].Get_pixel()[1]==k) {
                                                cont++;
                                            }
                                            if (imagen2d[i][j].Get_pixel()[2]==k) {
                                                cont++;
                                            }*/
                                        }
                                    
                                    }
                                    hist[k]=cont;
                                    probs.push_back((float)cont/(float)(alto*largo));
                                    //std::cout<<probs[k]<<std::endl;
                                }
                std::vector<dato> tabla;

                
                tabla =caminos(hist,largo,alto);
                for(int i = 0; i <tabla.size(); i++)
                {
                    //std::cout<<tabla[i].valor<< "   " << tabla[i].codigo<<std::endl;
                }



                std::ofstream ofile;
                ofile.open(nombre_archivo +".bin",std::ios::binary);

                if (ofile.is_open()) {
                    
                    ofile.write((char*)&W,sizeof(unsigned short));
                    ofile.write((char*)&H,sizeof(unsigned short));	
                    ofile.write((char*)&M,sizeof(char));	
                    for(int k = 0; k < 256; k++)
                    {
                        unsigned long cont=0;
                        for(int i = 0; i < imagen2d.size(); i++)
                        {
                            for(int j = 0; j < imagen2d[0].size(); j++)
                            {
                                if (imagen2d[i][j].Get_pixel()[0]==k) {
                                    cont++;
                                }
                                /*if (imagen2d[i][j].Get_pixel()[1]==k) {
                                    cont++;
                                }
                                if (imagen2d[i][j].Get_pixel()[2]==k) {
                                    cont++;
                                }*/
                            }
                        
                        }
                        ofile.write((char*)&cont,sizeof(unsigned long));
                        
                    }
                    std::string super_string="";
                    for(int i = 0; i < imagen2d.size(); i++)
                    {
                        for(int j = 0; j < imagen2d[0].size(); j++)
                        {
                            
                            std::string pix_cod =buscar_camino(imagen2d[i][j].Get_pixel()[0],tabla);
                            super_string = super_string + pix_cod;
                        }
                        
                    }
                
                    while(super_string.length()>=8){
                        //std::cout<<"super_string.length() :"<<super_string.length()<<std::endl ;
                        std::string str_temp;
                        for(int i = 0; i < 8; i++)
                        {
                            str_temp.push_back(super_string[i]);
                        }
                        char char_pix_cod = binary_to_char(str_temp);// std::cout<<str_temp<<std::endl;
                        ofile.write((char*)&char_pix_cod,sizeof(char));
                        super_string.erase(0,8);

                    }
                    if (super_string.length()<8) {
                        char char_pix_cod = binary_to_char(super_string);
                        ofile.write((char*)&char_pix_cod,sizeof(char));//std::cout<<(super_string)<<std::endl;
                    }
                    
                    //std::cout<<"stringcito  "<<super_string<<std::endl;

                    ofile.close();
                }

        std::cout << "se codificó la imagen correctamente" << std::endl;


            

                
            }
    std::string char_to_binary(char c){
        int cint = int(c);
        if (cint<0) {
            cint = 256+cint;
        }
        
        int cociente = cint;
        int residuo;
        std::string codigo;
        std::stack<int> binario;
    
        while(cociente!=0){
            residuo = cociente%2;
            cociente = cociente/2;
            binario.push(residuo);
        }
        while(!binario.empty()){
            if (binario.top()==1) {
                codigo.push_back('1');
            }
            else
            {
                codigo.push_back('0');
            }
            
                    
            binario.pop();
            
        }
        while (codigo.length()<8) {
            codigo = "0" + codigo;
        }
        
        //std::cout<<codigo;
        
        return codigo;

    }
    bool buscar_valor(std::string codigo, std::vector<dato> tabla, int &valor);

    void Img2d:: decodificar_Huffman(std::string nombre){
                
                int hist[256];
                unsigned short WR;
                unsigned short HR;
                char MR;
                unsigned long contR;
                std::ifstream infile;
                infile.open(nombre +".bin", std::ios::binary);
                if (infile.is_open()) {
                    
                    infile.read((char*)&WR,sizeof(unsigned short));
                    //std::cout<<WR<<std::endl;
                    infile.read((char*)&HR,sizeof(unsigned short));
                    //std::cout<<HR<<std::endl;
                    infile.read((char*)&MR,sizeof(char));
                    //std::cout<<2*int(MR)+3<<std::endl;
                    for(int k = 0; k < 256; k++)
                    {

                        infile.read((char*)&contR,sizeof(unsigned long));

                            //std::cout<<contR<<std::endl;
                        hist[k]=contR;

                    }

                        //std::cout<<"inicio: "<<std::endl;
                char c;
                //std::cout<<std::endl;   

                int contador=0;
                std::string super_string="";
                while(infile.read((char*)&c,sizeof(char))){
                        super_string = super_string +char_to_binary(c); 
                        //std::cout<<char_to_binary(c) <<std::endl;
                        
                        contador++;
            
                }

                //std::cout<< contador<<std::endl;
                //std::cout<<std::endl;   
                //std::cout<<"------------------------------------------"<<std::endl;
                //std::cout<<super_string;
                std::vector<dato> tabla;
                
                tabla =caminos(hist,WR,HR);
                for(int i = 0; i <tabla.size(); i++)
                {
                    //std::cout<<(int)tabla[i].valor<< "   " << tabla[i].codigo<<std::endl;
                }
                
                
                //-----------------------CREAR IMAGEN!! :D --------------------------------
                this->largo = WR;
                this->alto = HR;
                //imagen 0
                Pixel ptemp;
                ptemp.Set_pixel(0,0,0);
                std::vector<std::vector<Pixel>> imagen;
                for(int i = 0; i < WR; i++)
                {
                    std::vector<Pixel> vcol;
                    for(int j = 0; j < HR; j++)
                    {
                        vcol.push_back(ptemp);
                    }
                    imagen.push_back(vcol);
                }
                imagen2d = imagen;


                
                for(int i = 0; i <imagen2d.size(); i++)
                {
                    for(int j = 0; j <imagen2d[0].size(); j++)
                    {
                        std::string codigo ="";
                        int r=0;
                        int it=0;
                        while(!buscar_valor(codigo,tabla,r)){
                            codigo = codigo + super_string[it];
                            it++;   
                        }
                        
                        super_string.erase(0,it);
                        //std::cout<<"r "<<r<<", Codigo: "<<codigo<<std::endl;
                        
                        Pixel ptemp2;
                        ptemp2.Set_pixel(r,r,r);
                        imagen2d[i][j]=ptemp2;
                    }
                }
                
                this->crear_ppm(this->nombre_basexx);
                std::cout << "se decodificó la imagen correctamente" << std::endl;
                


                


                infile.close();
                                
                }



    }

            






    bool buscar_valor(std::string codigo, std::vector<dato> tabla, int &valor){
        //std::cout<<tabla.size();
        bool cambio = false;
        for(int i = 0; i <tabla.size(); i++)
        {   
            if (tabla[i].codigo==codigo) {
                if (int(tabla[i].valor)<0) {
                    valor = 256+int(tabla[i].valor);
                }
                else
                {
                    valor = int(tabla[i].valor);
                }
                cambio = true;
            }
            
            
        }
        return cambio;
        

    }






    std::vector<dato> caminos(int hist[256], int width, int height){

        std::vector<dato> tabla;
        
        int i,j;

        float p = 1;
            for(int i = 0; i <256; i++)
            {
                if (hist[i]!=0) {
                    
                    if ((float)hist[i] / (float)(width*height)<=p) {
                        p=(float)hist[i] / (float)(width*height);
                    }    
                }
                
                
            }

            // Finding number of  
            // non-zero occurences 
            int nodes = 0; 
            for (int i = 0; i < 256; i++)  
            { 
                if (hist[i] != 0) 
                    nodes += 1; 
            } 
            // Calculating max length  
            // of Huffman code word 
            int f = 0; 
            while ((1 / p) >    fib(f)) 
                f++; 
            int maxcodelen = f - 2; 
            
            //printf("%.6f",maxcodelen);

        // Defining Structures pixfreq 
        struct pixfreq  
        { 
            int pix; 
            float freq; 
            struct pixfreq *left, *right; 
            char code[20]; 
        }; 


        // Defining Structures huffcode 
        struct huffcode 
        { 
            int pix, arrloc; 
            float freq; 
        }; 
        // Declaring structs 
        struct pixfreq* pix_freq = new pixfreq[512]; 
        struct huffcode* huffcodes = new huffcode[512]; 


        int totalnodes = 2 * nodes - 1; 
        //pix_freq = (struct pixfreq*)malloc(sizeof(struct pixfreq) * totalnodes); 
        //huffcodes = (struct huffcode*)malloc(sizeof(struct huffcode) * nodes); 

        j = 0; 
        int totpix = height * width; 
        float tempprob; 
        for (int i = 0; i < 256; i++) 
        { 
            if (hist[i] != 0) 
            { 
                
                // pixel intensity value 
                
                huffcodes[j].pix = i; 
                pix_freq[j].pix = i; 
                
                
                // location of the node 
                // in the pix_freq array 
                huffcodes[j].arrloc = j; 
                
                // probability of occurrence 
                tempprob = (float)hist[i] / (float)totpix; 
                pix_freq[j].freq = tempprob; 
                huffcodes[j].freq = tempprob; 
                
                // Declaring the child of 
                // leaf node as NULL pointer 
                pix_freq[j].left = NULL; 
                pix_freq[j].right = NULL; 
                
                // initializing the code 
                // word as end of line 
                pix_freq[j].code[0] = '\0'; 
                j++; 
            } 
        } 

        // Sorting the histogram 
        struct huffcode temphuff; 

        // Sorting w.r.t probability 
        // of occurence 
        for (i = 0; i < nodes; i++) 
        { 
            for (j = i + 1; j < nodes; j++) 
        { 
                if (huffcodes[i].freq < huffcodes[j].freq) 
        { 
                    temphuff = huffcodes[i]; 
                    huffcodes[i] = huffcodes[j]; 
                    huffcodes[j] = temphuff; 
                } 
            } 
        } 


        // Building Huffman Tree 

        float sumprob; 
        int sumpix; 
        int n = 0, k = 0; 
        int nextnode = nodes; 

        // Since total number of 
        // nodes in Huffman Tree 
        // is 2*nodes-1 
        while (n < nodes - 1) 
        { 
            
            // Adding the lowest 
            // two probabilities 
            sumprob = huffcodes[nodes - n - 1].freq + huffcodes[nodes - n - 2].freq; 
            sumpix = huffcodes[nodes - n - 1].pix + huffcodes[nodes - n - 2].pix; 
            
            // Appending to the pix_freq Array 
            pix_freq[nextnode].pix = sumpix; 
            pix_freq[nextnode].freq = sumprob; 
            pix_freq[nextnode].left = &pix_freq[huffcodes[nodes - n - 2].arrloc]; 
            
            // arrloc points to the location 
            // of the child node in the 
            // pix_freq array 
            pix_freq[nextnode].right = &pix_freq[huffcodes[nodes - n - 1].arrloc]; 
            pix_freq[nextnode].code[0] = '\0'; 
            
            
            // Using sum of the pixel values as 
            // new representation for the new node 
            // since unlike strings, we cannot 
            // concatenate because the pixel values 
            // are stored as integers. However, if we 
            // store the pixel values as strings 
            // we can use the concatenated string as 
            // a representation of the new node. 
            i = 0; 
            
            // Sorting and Updating the huffcodes 
            // array simultaneously New position 
            // of the combined node 
            while (sumprob <= huffcodes[i].freq) 
                i++; 
                
            // Inserting the new node in 
            // the huffcodes array 
            for (k = nodes; k >= 0; k--) 
            { 
                if (k == i) 
                { 
                    huffcodes[k].pix = sumpix; 
                    huffcodes[k].freq = sumprob; 
                    huffcodes[k].arrloc = nextnode; 
                } 
                else if (k > i) 
                
                    // Shifting the nodes below 
                    // the new node by 1 
                    // For inserting the new node 
                    // at the updated position k 
                    huffcodes[k] = huffcodes[k - 1]; 
            } 
            n += 1; 
            nextnode += 1; 
        } 

        // Assigning Code through backtracking 
        char left = '0'; 
        char right = '1'; 
        int index; 
        for (i = totalnodes - 1; i >= nodes; i--) { 
            if (pix_freq[i].left != NULL) {
                //printf("%d",pix_freq[i].pix);printf("   ");printf("%s",pix_freq[i].code); printf("\n");
        
                strconcat(pix_freq[i].left->code, pix_freq[i].code, left); 
            } 
            if (pix_freq[i].right != NULL) { 
                strconcat(pix_freq[i].right->code, pix_freq[i].code, right); 
            } 
        } 
        for (i = 0; i < nodes; i++) {

            
            std::string codetemp(pix_freq[i].code);
            dato datotemp;
            
            
            char valtemp = char(pix_freq[i].pix);
            
            datotemp.valor=valtemp;
            datotemp.codigo=codetemp;
            tabla.push_back(datotemp);
            //std::cout<<(int)char(255)<<"<---->"<<datotemp.codigo<<std::endl;
        } 
        return tabla;
    }


















    /*

    void Img2d::cargar_caminos(){
        
        
        float p = 1;
        for(int i = 0; i <256; i++)
        {
            if (probs[i]<=p && probs[i]!=0) {
                p=probs[i];
            }
            
        }

        // Finding number of  
        // non-zero occurences 
        int nodes = 0; 
        for (int i = 0; i < 256; i++)  
        { 
            if (hist[i] != 0) 
                nodes += 1; 
        } 
        // Calculating max length  
        // of Huffman code word 
        int f = 0; 
        while ((1 / p) >=    fib(f)) 
            f++; 
        int maxcodelen = f - 2; 

        //std::cout<<maxcodelen<<std::endl;
        
        // Defining Structures pixfreq 
        struct pixfreq  
        { 
            int pix; 
            float freq; 
            pixfreq *left, *right; 
            std::vector<char> code; 
        }; 



        // Defining Structures huffcode 
        struct huffcode 
        { 
            int pix, arrloc; 
            float freq; 
        }; 

        // Declaring structs 
        std::vector<pixfreq> pix_freq; 
        std::vector<huffcode> huffcodes; 

        int totalnodes = 2 * nodes - 1; 

        //Initialize the two arrays pix_freq and 
        //huffcodes with information of the leaf nodes.
        int j = 0; 
        int totpix = alto * largo; 
        float tempprob; 
        for (int i = 0; i < 256; i++)  
        { 
            if (hist[i] != 0) 
            { 
                pixfreq pixfreq_temp;
                huffcode huffcode_temp;
                
                // pixel intensity value 
                huffcode_temp.pix=i;
                pixfreq_temp.pix = i;
                
                // location of the node 
                // in the pix_freq array 
                huffcode_temp.arrloc = j; 
                
                // probability of occurrence 
                tempprob = (float)hist[i] / (float)totpix;  
                pixfreq_temp.freq=tempprob;
                huffcode_temp.freq = tempprob;
                
                // Declaring the child of  
                // leaf node as NULL pointer 
                pixfreq_temp.left = NULL;
                pixfreq_temp.right = NULL;
                
                // initializing the code 
                // word as end of line
                pixfreq_temp.code.push_back('\0'); 
                //pix_freq[j].code[0] = '\0';  
                huffcodes.push_back(huffcode_temp);
                pix_freq.push_back(pixfreq_temp);
                
                j++; 
            } 
        }


        
        // Sorting the histogram 
        struct huffcode temphuff; 
        
        // Sorting w.r.t probability  
        // of occurence 
        for (int i = 0; i < nodes; i++) 
        { 
            for (int j = i + 1; j < nodes; j++)  
            { 
                if (huffcodes[i].freq < huffcodes[j].freq)  
                { 
                    temphuff = huffcodes[i]; 
                    huffcodes[i] = huffcodes[j]; 
                    huffcodes[j] = temphuff; 
                } 
            } 
        } /*
        float sum=0;
        for (int i = 0; i < nodes; i++) 
        { 
            
            sum = sum + huffcodes[i].freq;
        }

        std::cout<<sum<<std::endl;


        // Building Huffman Tree 
        
        float sumprob; 
        int sumpix; 
        int n = 0, k = 0; 
        int nextnode = nodes; 
        
        // Since total number of  
        // nodes in Huffman Tree  
        // is 2*nodes-1 
        while (n < nodes - 1)  
        { 
            
            // Adding the lowest  
            // two probabilities 
            sumprob = huffcodes[nodes - n - 1].freq + huffcodes[nodes - n - 2].freq; 
            sumpix = huffcodes[nodes - n - 1].pix + huffcodes[nodes - n - 2].pix; 
            
            // Appending to the pix_freq Array 
            pixfreq ptemp;
            ptemp.pix = sumpix;
            ptemp.freq = sumprob;
            ptemp.left = &pix_freq[huffcodes[nodes - n - 2].arrloc];
            ptemp.right =  &pix_freq[huffcodes[nodes - n - 1].arrloc];
            ptemp.code.push_back('\0');
            //std::cout<<ptemp.freq<<std::endl;

            
            pix_freq.push_back(ptemp);
            // Using sum of the pixel values as  
            // new representation for the new node 
            // since unlike strings, we cannot  
            // concatenate because the pixel values  
            // are stored as integers. However, if we 
            // store the pixel values as strings 
            // we can use the concatenated string as  
            // a representation of the new node. 
            int i = 0; 
            
            // Sorting and Updating the huffcodes  
            // array simultaneously New position 
            // of the combined node 
            while (sumprob <= huffcodes[i].freq) 
                i++; 
            
            // Inserting the new node in 
            // the huffcodes array 
            for (int k = nodes; k >= 0; k--)  
            { 
                if (k == i) 
                { 
                    huffcodes[k].pix = sumpix; 
                    huffcodes[k].freq = sumprob; 
                    huffcodes[k].arrloc = nextnode; 
                } 
                else if (k > i) 
                
                    // Shifting the nodes below 
                    // the new node by 1 
                    // For inserting the new node  
                    // at the updated position k 
                    huffcodes[k] = huffcodes[k - 1]; 
            } 
            n += 1; 
            nextnode += 1; 
        } 


        // Assigning Code through backtracking 
        char left = '0'; 
        char right = '1'; 
        int index; 
        for (int i = totalnodes - 1; i >= nodes; i--) {
            //std::cout<<pix_freq[i].pix<<std::endl; 
            
            if (pix_freq[i].left != NULL) { 
                
                strconcat(pix_freq[i].left->code, pix_freq[i].code, left);
            } 
            if (pix_freq[i].right != NULL) {
                //strconcat(pix_freq[i].right->code, pix_freq[i].code, right);
            }
                for(int j = 0; j < pix_freq[i].code.size(); i++)
                {
                    std::cout<<pix_freq[i].code[j];
                }
                std::cout<<std::endl;
        } 
        /*
        for(int i = 0; i < nodes; i++)
        {
            std::cout<<pix_freq[i].pix<<"  -> ";
            for(int j = 0; j < pix_freq[i].code.size(); i++)
            {
                std::cout<<pix_freq[i].code[j];
            }
            std::cout<<std::endl;
            
        }
        


        


    }
    */




    //******************************************************************************       
            
    // Métodos de proyeccion en Z

    //--------------------------------------------------------------------
            
    //******************************************************************************                    

    #endif
unsigned long parent_seed(std::vector< std::vector<long> > msts, long index){
    long index_temp, parent_seed;
    int cont ;
    std::vector<long> conts;
    index_temp=index;
    for (int k = 0; k < msts.size(); k++)
    {
        cont = 1;
        for (long l = 0; l < msts[k].size(); l++)
        {
            if(index_temp!=msts[k][l]){
                cont++;
                index = msts[k][l];
                
            }
        }
        conts.push_back(cont);
        
    }
    int min = 9999;
    for (int k = 0; k <conts.size(); k++)
    {
        if (conts[k]<=min)
        {
            min=conts[k];
            parent_seed = k;
        }
        
    }
    

    return parent_seed;
    

}

//---------------------------------------------------------------


    void Img2d::segmentar(std::string nombre,std::vector<std::vector<int> > seeds){
        

        Pixel red, orange, yellow, green, blue, purple,brown, black;
        red.Set_pixel(255,0,0);
        orange.Set_pixel(255,69,0);
        yellow.Set_pixel(255,255,0);
        green.Set_pixel(0,100,0);
        blue.Set_pixel(0,0,255);
        purple.Set_pixel(255,0,255);
        brown.Set_pixel(165,42,42);
        black.Set_pixel(0,0,0);

        std::vector<Pixel> colors;
        
        for (int i = 0; i < seeds.size(); i++)
        {
            if (0<=seeds[i][2] && seeds[i][2]<=32 )
                colors.push_back(red);
            else if (32<=seeds[i][2] && seeds[i][2]<=64 )
                colors.push_back(orange);
            else if (64<=seeds[i][2] && seeds[i][2]<=96 )
                colors.push_back(yellow);
            else if (96<=seeds[i][2] && seeds[i][2]<=128 )
                colors.push_back(green);
            else if (128<=seeds[i][2] && seeds[i][2]<=160 )
                colors.push_back(blue);
            else if (160<=seeds[i][2] && seeds[i][2]<=192 )
                colors.push_back(purple);
            else if (192<=seeds[i][2] && seeds[i][2]<=224 )
                colors.push_back(brown);
            else 
                colors.push_back(black);
            
            
            
        }
        
        typedef PUJ::Graph< Pixel, double > TGraph;
        TGraph g;  
        int sx1=1,sy1=2,sl1=200,sx2=3,sy2=0,sl2=100;
        std::vector<double> distances;
        //graph creation:

        //adding vertices
        for (int i = 0; i < alto; i++)
        {
            for (int j = 0; j < largo; j++)
            {
                g.AddVertex(imagen2d[i][j]);
            }
        }

        //adding edges
        for (int i = 0; i < alto; i++)
        {
            for (int j = 0; j < largo; j++)
            {
                int index , indexA, indexD,indexL,indexR;
                index=largo*i+j;
                double costD,costR,costA,costL;
                if(i == 0 && j == 0)
                {
                    Pixel down, right;
                    down = imagen2d[i+1][j];
                    right = imagen2d[i][j+1];
                    
                    costD = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])
                    );

                    costR = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])
                    );
                    
                    /*left = imagen2d[i][j-1];
                    above = imagen2d[i-1][j];
                    right = imagen2d[i][j+1];
                    down = imagen2d[i+1][j];*/
                    
                    indexD = largo*(i+1) + j;
                    indexR = largo*(i) + (j+1);

                    g.AddEdge(index,indexD,costD);//adding down edge
                    g.AddEdge(index,indexR,costR);//adding down edge
                    //g.PrintAsPNG("graph_image.png");                    
                }
                else if (j==0 && i==(alto -1))
                {
                    Pixel above, right;
                    above = imagen2d[i-1][j];
                    right = imagen2d[i][j+1];
                    costR = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])
                    );
                    costA = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])
                    );
                    index=largo*i+j;
                    indexA = largo*(i-1)+j;
                    indexR = largo*(i) + (j+1);

                    g.AddEdge(index, indexA, costA);
                    g.AddEdge(index, indexR, costR);

                }
                else if (j == (largo -1) && i == 0)
                {
                    Pixel left, down;
                    left = imagen2d[i][j-1];
                    down = imagen2d[i+1][j];

                    costL = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])
                    );
                    costD = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])
                    );
                    indexD = largo*(i+1) + j;
                    indexL = largo*(i) +(j-1);
                    g.AddEdge(index,indexL,costL);
                    g.AddEdge(index,indexD,costD);
                }
                else if (j == (largo - 1) && i == (alto - 1))
                {
                    Pixel left, above;
                    left = imagen2d[i][j-1];
                    above = imagen2d[i-1][j];

                    costL = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])
                    );
                    costA = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])
                    );
                    indexL = largo*(i) +(j-1);
                    indexA = largo*(i-1)+j;
                    g.AddEdge(index,indexL,costL);
                    g.AddEdge(index,indexA,costA);
                }
                else if (j==0)
                {
                    Pixel above, right, down;
                    above = imagen2d[i-1][j];
                    right = imagen2d[i][j+1];
                    down = imagen2d[i+1][j];
                    costA = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])
                    );
                    costR = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])
                    );
                    costD = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])
                    );
                    indexA = largo*(i-1)+j;
                    indexR = largo*(i) + (j+1);
                    indexD = largo*(i+1) + j;
                    g.AddEdge(index,indexA,costA);
                    g.AddEdge(index,indexR,costR);
                    g.AddEdge(index,indexD,costD);

                }
                else if (i==0)
                {
                    Pixel left, down, right;
                    left = imagen2d[i][j-1];
                    down = imagen2d[i+1][j];
                    right = imagen2d[i][j+1];

                    costL = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])
                    );
                    costD = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])
                    );
                    costR = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])
                    );
                    indexL = largo*(i) +(j-1);
                    indexD = largo*(i+1) + j;
                    indexR = largo*(i) + (j+1);
                    g.AddEdge(index,indexL,costL);
                    g.AddEdge(index,indexD,costD);
                    g.AddEdge(index,indexR,costR);
                }
                else if (j == largo - 1)
                {
                    Pixel above, left, down;
                    above = imagen2d[i-1][j];
                    left = imagen2d[i][j-1];
                    down = imagen2d[i+1][j];
                    costA = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])
                    );
                    costL = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])
                    );
                    costD = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])
                    );
                    indexA = largo*(i-1)+j;
                    indexL = largo*(i) +(j-1);
                    indexD = largo*(i+1) + j;
                    g.AddEdge(index,indexA,costA);
                    g.AddEdge(index,indexL,costL);
                    g.AddEdge(index,indexD,costD);
                }
                else if (i == alto - 1) 
                {
                    Pixel left, above, right;
                    left = imagen2d[i][j-1];
                    above = imagen2d[i-1][j];
                    right = imagen2d[i][j+1];

                    costR = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])
                    );
                    costA = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])
                    );
                    costL = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])
                    );

                    indexA = largo*(i-1)+j;
                    indexL = largo*(i) +(j-1);
                    indexR = largo*(i) + (j+1);
                    g.AddEdge(index,indexA,costA);
                    g.AddEdge(index,indexL,costL);
                    g.AddEdge(index,indexR,costR);


                }
                else
                {
                    Pixel left, above, right, down;
                    left = imagen2d[i][j-1];
                    above = imagen2d[i-1][j];
                    right = imagen2d[i][j+1];
                    down = imagen2d[i+1][j];
                    costD = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - down.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - down.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - down.Get_pixel()[2])
                    );

                    costR = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - right.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - right.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - right.Get_pixel()[2])
                    );
                    costA = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - above.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - above.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - above.Get_pixel()[2])
                    );
                    costL = sqrt(
                        (imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])*(imagen2d[i][j].Get_pixel()[0] - left.Get_pixel()[0])+
                        (imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])*(imagen2d[i][j].Get_pixel()[1] - left.Get_pixel()[1])+
                        (imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])*(imagen2d[i][j].Get_pixel()[2] - left.Get_pixel()[2])
                    );
                    indexA = largo*(i-1)+j;
                    indexD = largo*(i+1) + j;
                    indexL = largo*(i) +(j-1);
                    indexR = largo*(i) + (j+1);
                    g.AddEdge(index,indexL,costL);
                    g.AddEdge(index,indexR,costR);
                    g.AddEdge(index,indexA,costA);
                    g.AddEdge(index,indexD,costD);

                }
                
            }//end for
            
        }//end for
        //g.PrintAsPNG("graph_image.png");

        std::vector< std::vector<long> > msts;
        
        for (int i = 0; i <seeds.size(); i++)
        {
            msts.push_back(g.Dijkstra(largo*seeds[i][0]+seeds[i][1]));
        }
        

        //msts.push_back(g.Dijkstra(0));
        //msts.push_back(g.Dijkstra2(30));
        //msts.push_back(g.Dijkstra2(45));
        //msts.push_back(g.Dijkstra2(60));
        //msts.push_back(g.Dijkstra2(75));
        //msts.push_back(g.Dijkstra2(90));
        //msts.push_back(g.Dijkstra(200));
  
/*
        for (int i = 0; i <msts[0].size(); i++)
        {
            std::cout<<i<<"--->"<<msts[0][i]<<std::endl;//","<<msts[1][i]<<","<<msts[1][i]<<std::endl;
        }*/

        for (int i = 0; i < alto; i++)
        {
            for (int j = 0; j < largo; j++)
            {

                unsigned long index=largo*i+j;
                //unsigned long parent_seed;
                //std::cout<<index<<"->"<<parent_seed(msts,index)<<std::endl;

                switch (parent_seed(msts,index))
                {
                case 0:
                    imagen2d[i][j]=colors[0];
                    break;
                
                case 1:
                    imagen2d[i][j]=colors[1];
                    break;
                
                case 2:
                    imagen2d[i][j]=colors[2];
                    break;
                
                case 3:
                    imagen2d[i][j]=colors[3];
                    break;
                
                case 4:
                    imagen2d[i][j]=colors[4];
                    break;
                
                case 5:
                    imagen2d[i][j]=colors[5];
                    break;
                case 6:
                    imagen2d[i][j]=colors[6];
                    break;
                case 7:
                    imagen2d[i][j]=colors[7];
                    break;
                
                default:
                    imagen2d[i][j]=colors[8];
                    break;
                }
                
                
            }
        }


        crear_ppm(nombre);

        //reconstruct image



        

    }
  


