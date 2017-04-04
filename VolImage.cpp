/**
 * Author: Rayaan Fakier
 * Date: 01-04-2017
 * VolImage class for Assignment 2
 */

#include "vim.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <bitset>

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
//    string filename = ""; // account for new folder + baseName
    ifile.open("./brain_mri_raws/MRI.data"); // TODO delete
    if (ifile.is_open()){
        string width, height, num_images, line;
        getline(ifile, line);
        // extract sections of string
        istringstream ss(line);
        getline(ss,width,' ');
        getline(ss,height,' ');
        getline(ss,num_images,' ');
        ss.str(std::string());

        
        this->width = stoi(width);
        this->height = stoi(height);
        this->slices.reserve(stoi(num_images));
        
        // clean streams
        ifile.close();
        
        ifile.open("./brain_mri_raws/MRI0.raw", ios::binary);
        
        ifile.seekg(0, std::ios_base::end);
        size_t size = ifile.tellg();
        ifile.seekg(0, std::ios_base::beg);
        unsigned char file_chars[size];
        
        ifile>>noskipws;
        unsigned char c;
        
        int i = 0;
        while (ifile >> c){
            file_chars[i] = c;
            i++;
        }
        ifile.close();
        unsigned char* start = new unsigned char;
        start = reinterpret_cast<unsigned char*>(&file_chars);
        unsigned char** start_ptr = new unsigned char*;
        start_ptr = &start;
        this->slices.push_back(start_ptr);

        return true;
    }
    return false;
}

//void FKRRAY001::VolImage::dump(){
//    cout << *slices[0] << endl;
//}