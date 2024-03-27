#include "Image_Class.h"
#include "iostream"
using namespace std;
int main(){
    string file;
    int image_width,image_height,width_point,height_point;
    cout<<"please enter your file name";
    cin>>file;
    cout<<"insert your width point";
    cin>>width_point;
    cout<<"insert your height point";
    cin>>height_point;
    cout<<"insert your image width";
    cin>>image_width;
    cout<<"insert your image height";
    cin>>image_height;
    Image image(file);
    Image image2(image_width,image_height);
    for(int i=width_point;i<(width_point+image_width);++i)
    {
        for(int k=height_point;k<(height_point+image_height);++k)
        {
            for(int j=0;j<3;++j)
            {
                image2.setPixel(i-width_point,k-height_point,j,image(i,k,j));
            }
        }

    }
    cout<<"Done";
    image2.saveImage("hello world.jpg");
}