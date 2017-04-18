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

int width, height, num_imgs; // width and height of image stack
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
    for (auto p : this->slices){
        int i = 0;
        while (i < this->height){
            delete [] p[i];
            i++;
        }
        delete [] p;
    }
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
        this->num_imgs = stoi(num_images);
        this->slices.reserve(num_imgs);
        
        // clean streams
        ifile.close();
        
        
        unsigned char* start = new unsigned char;
        unsigned char** start_ptr = new unsigned char*;
        
        int i = 0;
         while (i < num_imgs){ // each image
            ifile.open("./brain_mri_raws/MRI" + to_string(i) + ".raw", ios::binary); // hardcoded
        
            ifile.seekg(0, std::ios_base::end);
            size_t size = ifile.tellg(); // file size
            ifile.seekg(0, std::ios_base::beg);

            ifile>>noskipws;
            unsigned char c;
            
            int j = 0;
            while (j < this->height){ // each row
            	unsigned char * line_chars = new unsigned char[this->width];
            	int k = 0;
            	while (k < this->width){ // each column
                    ifile >> c;
                    line_chars[k] = c;
                    k++;	
            	}
            	if (j == 0) // first row
                    start = reinterpret_cast<unsigned char*>(line_chars);
                j++;
            }
            ifile.close();
            start_ptr = &start; // right?
            this->slices.push_back(start_ptr);
            i++;
         }
        return true;
    }
    return false;
}

void FKRRAY001::VolImage::extract(int sliceId, string output_prefix){
    ofstream ofile;
    ofile.open("output.dat"); // header file
    string s = to_string(this->width) + " " + to_string(this->height) + " 1";
    ofile << s << endl;
    ofile.close();
    
    ofile.open("output.raw", ios::binary); // output raw file
    int i = 0;
    while (i < this->height){ // each row
        int j = 0;
        while (j < this->width){ // each column
            ofile << this->slices[sliceId][i][j];
            j++;
        }
        ofile << endl;
        i++;
    }
    ofile.close();
}

void FKRRAY001::VolImage::dump(){
    int i = 0;
//    while (i < this->num_imgs){
        int j = 0;
        while (j < this->height){
            int k =0;
            while (k < this->width){
                cout << this->slices[i][j][k];
                k++;
            }
            cout << endl;
            j++;
        }
        cout << endl;        
        i++;
//    }
}