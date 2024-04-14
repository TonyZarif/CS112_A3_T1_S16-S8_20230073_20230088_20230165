// FCAI – Structured Programming – 2024 - Assignment 2
// Program Name: Filters
// Program Description: program work with 15 Filters methods
// 12 Filters
// (Gray Scale - Black and Wight - Invert - Merge - Flip - Rotate - Darken and Lighten - Crop - Adding Frame - Edge Detection - Resize - Blur).
// 3 Bonus Filters
// (Sunlight - Purple - Infrared)
// Last Modification Date: 14/4/2024
// Author1 and ID and Group:
//Name: Zeinab Mohamed Tolba
//ID: 20230165
//Group:A Section 8
//solved Invert & Blur & Rotate & Adding Frame & Infrared
// Author2 and ID and Group:
//Name: Bassam Ashraf Ahmed Mostafa
//ID: 20230088
//Group:A Section 8
//solved Black and wight & Crop & Flip & Resize & Purple
// Author3 and ID and Group:
//Name:Antonious Magdy Zarif Zaky
//ID: 20230073
//Group:B Section 16
//solved Gray scale & Darken and Lighten & Merge & Edge Detection & Sunlight
// Teaching Assistant: Eng.Belal Tarek

#include <iostream>
#include <limits>
#include "image_CLass.h"
using namespace std;

void Print_Menu(){
    cout << "1) Gray_Scale        ";
    cout << "2) Black_Wight       ";
    cout << "3) Invert\n";
    cout << "4) Merge             ";
    cout << "5) Flip              ";
    cout << "6) Rotate\n";
    cout << "7) Darken            ";
    cout << "8) Lighten           ";
    cout << "9) Crop\n";
    cout << "10) Adding Frame     ";
    cout << "11) Edge Detection   ";
    cout << "12) Resize\n";
    cout << "13) Blur             ";
    cout << "14) Sunlight         ";
    cout << "15) Purple\n";
    cout << "16) Infrared         ";
    cout << "0) Exit\n";
}

int To_Continue();
Image gray_scale(Image& image);
Image black_wight(Image& image);
Image invert(Image& image);
Image merge(Image& image, Image image1);
Image flip(Image& image);
Image rotate(Image& image);
Image darken_and_lighten(Image& image, int choice);
Image Crop(Image& image);
Image frame(Image& image);
Image Edge_detection(Image& image);
Image resize(Image& image, int width1, int height1);
Image blur (Image& image);
Image sunlight(Image& image);
Image purple(Image& image);
Image infrared(Image& image);
void Save_Name(Image& image);

int main() {
    cout << "Welcome to the filter APP...\n";
    string Image_Name;
    int choice, choice2;
    Image image;
    do {
        cout << "Enter the image name you want to filtration:\n";
        cin >> Image_Name;
        while (true) {
            try {
                image.loadNewImage(Image_Name);
                break;
            } catch (invalid_argument) {
                cout << "Please enter a valid photo \n";
                cin >> Image_Name;
            }
        }
        cout << "enter the filter you went to be done:\n";
        Print_Menu();
        while (!(cin >> choice) || cin.peek() != '\n' || choice > 16) {
            cout << "**Invalid choice. please enter a integer number between 1 and 16.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (choice == 1) {
            image = gray_scale(image);
            Save_Name(image);
            choice2 = To_Continue();
        } else if (choice == 2) {
            image = black_wight(image);
            Save_Name(image);
            choice2 = To_Continue();
        } else if (choice == 3) {
            image = invert(image);
            Save_Name(image);
            choice2 = To_Continue();
        }else if (choice == 4) {
            Image image2;
            string Image_Name2;
            cout << "Enter the image name you want to merge:\n";
            cin >> Image_Name2;
            while (true) {
                try {
                    image2.loadNewImage(Image_Name2);
                    break;
                } catch (invalid_argument) {
                    cout << "Please enter a valid photo \n" << endl;
                    cin >> Image_Name2;
                }
            }
            image = merge(image, image2);
            Save_Name(image);
            choice2 = To_Continue();
        } else if (choice == 5){
            image = flip(image);
            Save_Name(image);
            choice2 = To_Continue();
        } else if (choice == 6) {
            image = rotate(image);
            Save_Name(image);
            choice2 = To_Continue();
        } else if (choice == 7) {
            image = darken_and_lighten(image, choice);
            Save_Name(image);
            choice2 = To_Continue();
        } else if (choice == 8) {
            image = darken_and_lighten(image, choice);
            Save_Name(image);
            choice2 = To_Continue();
        } else if (choice == 9) {
            image = Crop(image);
            Save_Name(image);
            choice2 = To_Continue();
        }else if (choice == 10) {
            image = frame(image);
            Save_Name(image);
            choice2 = To_Continue();
        }else if (choice == 11) {
            image = Edge_detection(image);
            Save_Name(image);
            choice2 = To_Continue();
        }else if (choice == 12) {
            int width1,height1;
            cout<<"enter the new width you want:\n";
            while (!(cin >> width1) || cin.peek() != '\n') {
                cout << "**Invalid choice. please enter a integer.\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout<<"enter the new height you want:\n";
            while (!(cin >> height1) || cin.peek() != '\n') {
                cout << "**Invalid choice. please enter a integer.\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            image = resize(image, width1, height1);
            Save_Name(image);
            choice2 = To_Continue();
        }else if (choice == 13) {
            image = blur(image);
            Save_Name(image);
            choice2 = To_Continue();
        }else if (choice == 14){
            image = sunlight(image);
            Save_Name(image);
            choice2 = To_Continue();
        }else if (choice == 15){
            image = purple(image);
            Save_Name(image);
            choice2 = To_Continue();
        }else if (choice == 16){
            image = infrared(image);
            Save_Name(image);
            choice2 = To_Continue();
        }
    } while (choice != 0 && choice2 != 0);
    cout << "Thanks to use this App...\n";
    return 0;
}



int To_Continue(){
    int choice2;
    cout << "Do you need to continue?!\n";
    cout << "1) YES\t 2) NO\n";
    while (!(cin >> choice2) || cin.peek() != '\n' || choice2 > 2) {
        cout << "**Invalid choice. please enter a integer number between 1 and 2.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (choice2 == 2){
        return 0;
    }
    return 1;
}

Image gray_scale(Image& image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int ave = 0;
            for (int k = 0; k < 3; k++)
                ave += image(i, j, k);
            ave /= 3;
            for (int k = 0; k < 3; ++k)
                image(i, j, k) = ave;
        }
    }
    return image;
}

Image black_wight(Image& image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned ave = 0;
            for (int k = 0; k < 3; k++)
                ave += image(i, j, k);
            ave /= 3;
            if (ave < 128){
                for (int k = 0; k < 3; ++k)
                    image(i, j, k) = 0;
            }else{
                for (int k = 0; k < 3; ++k)
                    image(i, j, k) = 255;
            }
        }
    }
    return image;
}

Image invert(Image& image){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i , j, k);
            }
        }
    }
    return image;
}

Image merge(Image& image, Image image1){
    image1 = resize(image1, image.width, image.height);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (image(i, j, k) + image1(i, j, k)) / 2;
            }
        }
    }
    return image;
}

Image flip(Image& image){
    int choice;
    int width=image.width;
    int height=image.height;
    Image image2(width,height);
    cout << "How do you want to flip?\n";
    cout << "1) Horizontal\t2) Vertical\n";
    while (!(cin >> choice) || cin.peek() != '\n' || choice > 2) {
        cout << "**Invalid choice. please enter a integer number between 1 and 2.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (true)
    {
        if (choice == 1) {
            for (int i = 0; i < width; ++i) {
                for (int k = 0; k < height; ++k) {
                    for (int j = 0; j < 3; ++j) {
                        image2(i, k, j) = image((width - i - 1), (k), j);

                    }
                }
            }
            break;
        }
        else if (choice == 2) {
            for (int i = 0; i < width; ++i) {
                for (int k = 0; k < height; ++k) {
                    for (int j = 0; j < 3; ++j) {
                        image2(i, k, j) = image((i), (height - k - 1), j);

                    }
                }
            }
            break;
        }
        else {
            cout << "please enter a suitable number\n";
            cin >> choice;
            continue;
        }
    }
    return image2;
}

Image rotate_90(Image& image){
    Image Image_Trans(image.height, image.width);
    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                Image_Trans(i, j, k) = image(j, image.height - i - 1, k);
            }
        }
    }
    return Image_Trans;
}

Image rotate_180(Image& image){
    Image Image_Rotated(image.width, image.height);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                Image_Rotated(i, j, k) = image(image.width - i - 1, image.height - j - 1, k);
            }
        }
    }
    return Image_Rotated;
}

Image rotate_270(Image& image){
    image = rotate_90(image);
    image = rotate_180(image);
    return image;
}

Image rotate(Image& image){
    Image Image_Trans(image.height, image.width);
    Image Image_Rotated(image.width, image.height);
    int choice;
    cout << "How do you want to rotate?\n";
    cout << "1) 90\t2) 180\t3) 270\n";
    cout << "degree clockwise\n";
    do {
        while (!(cin >> choice) || cin.peek() != '\n' || choice > 3) {
            cout << "**Invalid choice. please enter a integer number between 1 and 3.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (choice == 1) {
            Image_Trans = rotate_90(image);
            return Image_Trans;
        } else if (choice == 2) {
            Image_Rotated = rotate_180(image);
            return Image_Rotated;
        } else if (choice == 3) {
            Image_Trans = rotate_270(image);
            return Image_Trans;
        } else {
            cout << "Invalid choice\n";
        }
    } while (choice > 3);
}

Image darken_and_lighten(Image& image, int choice) {
    if (choice == 7) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = image(i, j, k) / 2;
                }
            }
        }
    }
    if (choice == 8) {
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
    }
    return image;
}

Image Crop(Image& image){
    int image_width,image_height,width_point,height_point;
    cout<<"insert your width point:\n";
    while (!(cin >> width_point) || cin.peek() != '\n' ) {
        cout << "**Invalid choice. please enter a integer.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"insert your height point:\n";
    while (!(cin >> height_point) || cin.peek() != '\n' ) {
        cout << "**Invalid choice. please enter a integer.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"insert your image width:\n";
    while (!(cin >> image_width) || cin.peek() != '\n' ) {
        cout << "**Invalid choice. please enter a integer.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"insert your image height:\n";
    while (!(cin >> image_height) || cin.peek() != '\n' ) {
        cout << "**Invalid choice. please enter a integer.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    Image image2(image_width,image_height);
    for(int i=width_point;i<(width_point+image_width);++i){
        for(int k=height_point;k<(height_point+image_height);++k){
            for(int j=0;j<3;++j)
                image2.setPixel(i-width_point,k-height_point,j,image(i,k,j));
        }
    }
    return image2;
}

Image sample_frame(Image& image){
    for(int i = 0; i < 15; i++){
        for (int j = 0; j < image.height; j++){
            image(i , j , 0) = 0;
            image(i , j , 1 ) = 50;
            image(i , j , 2 ) = 150;
        }
    }
    for(int j = 0; j < 15; j++){
        for(int i = 0; i < image.width; i++){
            image(i , j , 0) = 0;
            image(i , j , 1 ) = 50;
            image(i , j , 2 ) = 150;
        }
    }
    for(int i = image.width - 15; i < image.width ; i++){
        for(int j = 0; j < image.height; j++){
            image(i , j , 0) = 0;
            image(i , j , 1 ) = 50;
            image(i , j , 2 ) = 150;
        }
    }
    for(int j = image.height - 15; j < image.height ; j++){
        for(int i = 0; i < image.width; i++){
            image(i , j , 0) = 0;
            image(i , j , 1 ) = 50;
            image(i , j , 2 ) = 150;
        }
    }
    return image;
}

Image fance_frame(Image& image){
    image = sample_frame(image);
    for(int i = 15; i <20; i++){
        for(int j = 15;j < image.height - 15; j++){
            image(i , j , 0) = 255;
            image(i , j , 1 ) = 255;
            image(i , j , 2 ) = 255;
        }
    }
    for (int j = 15; j < 20; j++){
        for(int i = 15; i < image.width - 15; i++){
            image(i , j , 0) = 255;
            image(i , j , 1 ) = 255;
            image(i , j , 2 ) = 255;
        }
    }
    for(int j = image.height - 20; j < image.height - 15; j++){
        for(int i = 15; i < image.width - 15; i++){
            image(i , j , 0) = 255;
            image(i , j , 1 ) = 255;
            image(i , j , 2 ) = 255;
        }
    }
    for(int i = image.width - 20; i < image.width -15; i++){
        for(int j = 15; j < image.height -15; j++){
            image(i , j , 0) = 255;
            image(i , j , 1) = 255;
            image(i , j , 2) = 255;
        }
    }
    return image;
}

Image frame(Image& image){
    string Save_Name;
    cout << "How do you want the frame to look?\n";
    cout << "1) sample frame\t2) fancy frame\n";
    int choice;
    do {
        while (!(cin >> choice) || cin.peek() != '\n' || choice > 2) {
            cout << "**Invalid choice. please enter a integer number between 1 and 2.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (choice == 1) {
            image = sample_frame(image);
        } else if (choice == 2) {
            image = fance_frame(image);
        } else {
            cout << "Invalid choice\n";
        }
    } while (choice > 2);
    return image;
}

Image Edge_detection(Image& image){
    Image edeg(image.width, image.height);
    int n_pixel, pr_pixel, next_pixel;
    image = black_wight(image);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 1; j < image.height-1; ++j) {
            n_pixel = image(i, j, 0);
            pr_pixel = image(i, j-1, 0);
            next_pixel = image(i, j+1, 0);
            if ((n_pixel == 0 && pr_pixel == 255) || (n_pixel == 0 && next_pixel == 255)){
                for (int k = 0; k < 3; ++k) {
                    edeg(i, j, k) = 0;
                }
            }
            else{
                for (int k = 0; k < 3; ++k) {
                    edeg(i, j, k) = 255;
                }
            }
        }
    }
    return edeg;
}

Image resize(Image& image, int width1, int height1){
    double width_scale,height_scale;
    int width=image.width;
    int height=image.height;
    Image image1(width1,height1);
    width_scale=float(width)/float(width1);
    height_scale=float(height)/float(height1);
    for(int i=0;i<width1;++i){
        for(int k=0;k<height1;++k){
            for (int j =0 ; j < 3; ++j){
                image1(i,k,j)=image(round(width_scale*i), round(height_scale*k),j);
            }
        }
    }
    return image1;
}

Image blur (Image& image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                int sum = 0;
                int count = 0;
                for (int x = i - 10; x <= i + 10; x++) {
                    for (int y = j - 10; y <= j + 10; y++) {
                        if (x >= 0 && x < image.width && y >= 0 && y < image.height) {
                            sum += image(x, y, k);
                            count++;
                        }
                    }
                }
                image(i, j, k) = sum / count;
            }
        }
    }
    return image;
}

Image sunlight(Image& image){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j)
            image(i, j, 2) *= 0.7;
    }
    return image;
}

Image purple(Image& image){
    for(int i=0;i<image.width;++i){
        for(int k=0;k<image.height;++k)
            image(i,k,1) *= 0.7;
    }
    return image;
}

Image infrared(Image& image){
    for(int i = 0; i < image.width; i++){
        for(int j = 0; j < image.height; j++){
            image(i , j , 0) = 255;
            image(i , j , 1) = 255 - image(i , j , 1);
            image(i , j , 2) = 255 - image(i , j , 2);
        }
    }
    return image;
}

void Save_Name(Image& image){
    cout << "Do you want save new image?\n";
    cout << "1) YES\t2) NO\n";
    int choice;
    while (!(cin >> choice) || cin.peek() != '\n' || choice > 2) {
        cout << "**Invalid choice. please enter a integer number between 1 and 2.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (choice == 1){
        string save_name;
        do {
            cout << "Enter the name of the image you want to save:\n";
            cin >> save_name;
        } while (!image.saveImage(save_name));
    }else if (choice == 2)
        return;
}