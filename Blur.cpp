#include <iostream>
#include "Image_Class.h"
using namespace std;

void blur (Image image){
    Image blured(image.width-10,image.height-10);

    for(int i = 10,lo=0; i < image.width -10;lo++, i++) {
        for (int j = 10,li=0; j < image.height - 10;li++, j++) {
            for (int k = 0; k < image.channels ; k++) {
                blured(lo, li, k) = (image(i, j, k) + image(i, j - 10, k) + image(i, j + 10, k) + image(i + 10, j, k) +
                                     image(i + 10, j + 10, k) + image(i + 10, j - 10, k) + image(i - 10, j, k) +
                                     image(i - 10, j - 10, k) + image(i - 10, j + 10, k)  ) / 9;
            }
        }
    }
    blured.saveImage("99eed.jpg");// save image

}

int main(){
    cout << "welcome to blur filter!!\n";
    string File_Name;
    cout << "Please enter the image name: \n";
    cin >> File_Name;
    Image image(File_Name);
    blur(File_Name);

    return 0;
}