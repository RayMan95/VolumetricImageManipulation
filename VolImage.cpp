/**
 * Author: Rayaan Fakier
 * Date: 01-04-2017
 * VolImage class for Assignment 2
 */

#include "vim.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int width, height; // width and height of image stack
vector<unsigned char**> slices; // data for each slice, in order

/**
 * 
 */
FKRRAY001::VolImage::VolImage(){
    this->width = 0;
    this->height = 0;
}

/**
 * 
 */
FKRRAY001::VolImage::~VolImage(){
    // NOP (I think))
}

/**
 * 
 *  (ignore vector<> container, dims etc)
 * @return number of bytes uses to store image, data bytes and pointers 
 */
int FKRRAY001::VolImage::volImageSize(){
    // TODO
    return 1;
}

/** 
 * populate the object with images in stack and set member variables; define in .cpp
 */
bool FKRRAY001::VolImage::readImages(string baseName){
    ifstream ifile;
//    string filename = ""; // account for new folder / filextension
    ifile.open("./brain_mri_raws/MRI.data"); // TODO delete
    if (ifile.is_open()){
        string width, height, num_images, line;
        getline(ifile, line);
        // extract sections of string
        stringstream ss(line);
        getline(ss,width,' ');
        getline(ss,height,' ');
        getline(ss,num_images,' ');
        
        this->width = stoi(width);
        this->height = stoi(height);
        
        
        
        return true;
    }
    return false;
}
