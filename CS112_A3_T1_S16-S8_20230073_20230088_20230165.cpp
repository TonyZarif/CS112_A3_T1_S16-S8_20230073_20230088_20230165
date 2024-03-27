#include <iostream>
#include <limits>
#include <cmath>
#include "image_CLass.h"
using namespace std;

void Print_Menu(){
    cout << "1) Gray_Scale\n";
    cout << "2) Black_Wight\n";
    cout << "3) Invert\n";
    cout << "4) Darken\n";
    cout << "5) Lighten\n";
    cout << "6) Crop\n";
    cout << "7) Blur\n";
    cout << "0) Exit\n";
}

int To_Continue(){
    int choice2;
    cout << "Do you need to continue?!\n";
    cout << "1) YES\t 2) NO\n";
    cin >> choice2;
    if (choice2 == 2){
        return 0;
    }
    return 1;
}

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
        cout << "Enter the name of the image you want to save:\n";
        cin >> save_name;
    } while (!image.saveImage(save_name));
}

void black_wight(Image image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned ave = 0;
            for (int k = 0; k < 3; k++) {
                ave += image(i, j, k);
            }
            ave /= 3;
            if (ave < 128){
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 0;
                }
            }else{
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 255;
                }
            }
        }
    }
    string save_name;
    do {
        cout << "Enter the name of the image you want to save:\n";
        cin >> save_name;
    } while (!image.saveImage(save_name));
}

void invert(Image image){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i , j, k);
            }
        }
    }
    string save_name;
    do {
        cout << "Enter the name of the image you want to save:\n";
        cin >> save_name;
    } while (!image.saveImage(save_name));
}

void darken_and_lighten(Image image, int choice) {
    if (choice == 4) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = image(i, j, k) / 2;
                }
            }
        }
        string save_name;
        do {
            cout << "Enter the name of the image you want to save:\n";
            cin >> save_name;
        } while (!image.saveImage(save_name));
        return;
    }
    if (choice == 5) {
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
            cout << "Enter the name of the image you want to save:\n";
            cin >> save_name;
        } while (!image.saveImage(save_name));
        return;
    }
}

void Crop(Image image){
    int image_width,image_height,width_point,height_point;
    cout<<"insert your width point";
    cin>>width_point;
    cout<<"insert your height point";
    cin>>height_point;
    cout<<"insert your image width";
    cin>>image_width;
    cout<<"insert your image height";
    cin>>image_height;
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
    string save_name;
    do {
        cout << "Enter the name of the image you want to save:\n";
        cin >> save_name;
    } while (!image2.saveImage(save_name));
}

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
    string save_name;
    do {
        cout << "Enter the name of the image you want to save:\n";
        cin >> save_name;
    } while (!blured.saveImage(save_name));
}

int main() {
    cout << "Welcome to the filter APP...\n";
    string Image_Name;
    int choice, choice2;
    Image image;
    do{
        cout << "Enter the image name you want to filtration:\n";
        cin >> Image_Name;
        while(true){
            try {
                image.loadNewImage(Image_Name);
                break;
            } catch(invalid_argument) {
                cout << "Please enter a valid photo \n" << endl;
                cin>>Image_Name;
            }
        }
        cout << "enter the filter you went to be done:\n";
        Print_Menu();
        while (!(cin >> choice) || cin.peek() != '\n' || choice > 7)
        {
            cout <<"**Invalid choice. please enter a integer number between 1 and 7.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (choice == 1){
            gray_scale(image);
            choice2 = To_Continue();
        }
        else if (choice == 2){
            black_wight(image);
            choice2 = To_Continue();
        }
        else if (choice == 3){
            invert(image);
            choice2 = To_Continue();
        }
        else if (choice == 4){
            darken_and_lighten(image, choice);
            choice2 = To_Continue();
        }
        else if (choice == 5){
            darken_and_lighten(image, choice);
            choice2 = To_Continue();
        }
        else if (choice == 6){
            Crop(image);
            choice2 = To_Continue();
        }
        else if (choice == 7){
            blur(image);
            choice2 = To_Continue();
        }
    } while (choice != 0 && choice2 != 0);
    cout << "Thanks to use this App...\n";
    return 0;
}