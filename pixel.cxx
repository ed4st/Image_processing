#ifndef __PIXEL__CXX__
#define __PIXEL__CXX__

#include "pixel.h"
#include <iostream>
#include <vector>

//______________________________________________________________________________________   
    Pixel::Pixel() {
std::vector<int> pixel={}; };
//______________________________________________________________________________________   
    Pixel:: ~Pixel(){}; 

//______________________________________________________________________________________   

std::vector<int> Pixel::Get_pixel(){
            return this->pixel;
        }
//______________________________________________________________________________________   
        void Pixel::Set_pixel(int r, int g, int b){
            this->pixel.push_back(r);
            this->pixel.push_back(g);
            this->pixel.push_back(b);        
        } 
        
        
//______________________________________________________________________________________   
        
void Pixel::print(){
            for(std::vector<int>::iterator it= pixel.begin();it !=pixel.end();it++){
                std::cout<<*it<<" ";       
            }
            std::cout<<"  ";
        }
        
//______________________________________________________________________________________   
#endif
