#include "Image_Class.h"
#include "iostream"
using namespace std;

int main(){
    string file;
    cout<<"enter your file name";
    cin>>file;
    Image image2;
    image2.loadNewImage(file);
    for(int i=0;i<image2.width;++i){
        for(int k=0;k<image2.height;++k) {
            unsigned avg=0;
            for (int j =0 ; j < 3; ++j) {
                avg +=image2(i,k,j);}
            for (int j =0 ; j < 3; ++j) {
                if ((avg / 3) >= 128) {
                    image2(i, k, j) = 255.;
                } else if ((avg / 3) < 128) {
                    image2(i, k, j) = 0;
                }
            }
        }
    }
    cout<<"Done";
    image2.saveImage("hello world.jpg");
}
