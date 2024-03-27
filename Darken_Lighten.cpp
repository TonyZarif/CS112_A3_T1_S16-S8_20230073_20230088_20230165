#include <iostream>
#include "Image_Class.h"

using namespace std;
void darken_and_lighten(Image image, int choice) {
    if (choice == 1) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = image(i, j, k) / 2;
                }
            }
        }
        string save_name;
        do {
            cout << "enter the name of the image:\n";
            cin >> save_name;
        } while (!image.saveImage(save_name));
        return;
    }
    if (choice == 2) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    float x = image(i, j, k);
                    x *= 1.5;
                    if (x > 255){
                        x =255;
                    }
                    image(i, j, k) = x;
                }
            }
        }
        string save_name;
        do {
            cout << "enter the name of the image:\n";
            cin >> save_name;
        } while (!image.saveImage(save_name));
        return;
    }
}

int main() {

    string Image_Name;
    int choice;
    Image image;
    do {
        cout << "Enter the image name:\n";
        cin >> Image_Name;
    } while (!image.loadNewImage(Image_Name));
    cout << "enter the filter you went to be done:\n";
    cout << "1) Darken\n2) Lighten\n";
    cin >> choice;
    if (choice == 1){
        darken_and_lighten(image, choice);
    }
    else if (choice == 2) {
        darken_and_lighten(image, choice);
    }

    return 0;
}