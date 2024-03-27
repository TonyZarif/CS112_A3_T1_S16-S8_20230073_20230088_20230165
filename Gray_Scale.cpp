#include <iostream>
#include "image_CLass.h"
using namespace std;

void gray_scale(Image image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int ave = 0;
            for (int k = 0; k < 3; k++) {
                ave += image(i, j, k);
            }
            ave /= 3;
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = ave;

            }
        }
    }
    string save_name;
    do {
        cout << "enter the name of the image:\n";
        cin >> save_name;
    } while (!image.saveImage(save_name));
}

int main() {
    string Image_Name;
    Image image;
    do {
        cout << "Enter the image name:\n";
        cin >> Image_Name;
    } while (!image.loadNewImage(Image_Name));
    gray_scale(image);
    return 0;
}
