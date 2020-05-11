#ifndef __PIXEL__H__
#define __PIXEL__H__

#include <vector>
 


//______________________________________________________________________________________   
class Pixel{
    protected:
    
        std::vector<int> pixel;    
    
    public:
	Pixel();
	virtual ~ Pixel();
        std::vector<int> Get_pixel();
        void Set_pixel(int r, int g, int b);
	 void print();
        
};
//______________________________________________________________________________________   
#endif
