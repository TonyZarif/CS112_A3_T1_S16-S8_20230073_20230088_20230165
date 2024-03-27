#include <iostream>
#include "Image_Class.h"
using namespace std;

//Filter 3 > invert

int main() {

    cout << "welcome to invert filter!!\n";
    string File_Name;
    cout << "Please enter the image name: \n";
    cin >> File_Name;
    Image image(File_Name);
    for(int i = 0; i < image.width; i++){
        for (int j = 0; j < image.height; j++){
            for(int k = 0; k < image.channels; k++){

                image(i, j, k) = 255 - image(i , j, k);
            }
        }
    }

    int x = image.saveImage(File_Name);
    cout << x;

    return 0;
}