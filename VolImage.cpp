/**
 * Author: Rayaan Fakier
 * Date: 01-04-2017
 * VolImage class for Assignment 2
 */

#include "vim.h"
#include <sstream>
#include <math.h>

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
        delete[] p;
    }
    slices.clear();
}

/**
 * 
 *  (ignore vector<> container, dims etc)
 * @return number of bytes uses to store image, data bytes and pointers 
 */
int FKRRAY001::VolImage::volImageSize(){
    if ((this->width > 0) and (this->height > 0)){ // not empty
//        int x = slices.size();
        
        return (slices.size()*(this->height)*(this->width)) + (sizeof(int*)*slices.size());
    }
    return 0;
}

int FKRRAY001::VolImage::volNumImages(void){
    return this->num_imgs;
}

/** 
 * populate the object with images in stack and set member variables; define in .cpp
 */
bool FKRRAY001::VolImage::readImages(string baseName){
    ifstream ifile;
    ifile.open(baseName+".dat");
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
        
        ifile.close();
        
        int i = 0;
         while (i < num_imgs){ // each image
//            ifile.open("./brain_mri_raws/MRI" + to_string(i) + ".raw", ios::binary);
            ifile.open(baseName + to_string(i) + ".raw", ios::binary);

            ifile>>noskipws;
            
            unsigned char ** rows = new unsigned char * [this->height];
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
                rows[j] = line_chars;
                j++;
            }
            ifile.close();
            this->slices.push_back(rows);
            i++;
         }
        return true;
    }
    return false;
}

void FKRRAY001::VolImage::extract(int sliceId, string output_prefix){
    ofstream ofile;
    ofile.open(output_prefix + ".dat"); // header file
    string s = to_string(this->width) + " " + to_string(this->height) + " 1";
    ofile << s << endl;
    ofile.close();
    
    ofile.open(output_prefix +".raw", ios::binary); // output raw file
    int i = 0;
    while (i < this->height){ // each row
        int j = 0;
        while (j < this->width){ // each column
            ofile << this->slices[sliceId][i][j];
            j++;
        }
        i++;
    }
    ofile.close();
}

void FKRRAY001::VolImage::diffmap(int sliceI, int sliceJ, string output_prefix){
    ofstream ofile;
    ofile.open(output_prefix + ".raw"); // output file + ext?
        
    if (this->width != 0 && this->height != 0){
        int i = 0;
        while (i < height){
            int j = 0;
            while (j < width){
                ofile << (unsigned char)(fabs((float)slices[sliceI][i][j] - (float)slices[sliceJ][i][j])/2);
                j++;
            }
            i++;
        }
    }
    
    ofile.close();
}