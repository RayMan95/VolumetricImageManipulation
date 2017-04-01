/**
 * Author: Rayaan Fakier
 * Date: 01-04-2017
 * Header file for Assignment 2
 */

#ifndef _VIM_H
#define _VIM_H

#include <vector>
#include <string>
#include <cstring>
namespace FKRRAY001
{
    class VolImage
    {
    private: // private members
        int width, height; // width and height of image stack
        std::vector<unsigned char**> slices; // data for each slice, in order
    public: // public members
        VolImage(); // default constructor - define in .cpp
        ~VolImage(); // destructor - define in .cpp file
        // populate the object with images in stack and set member variables; define in .cpp
        bool readImages(std::string baseName);
        // compute difference map and write out; define in .cpp
        void diffmap(int sliceI, int sliceJ, std::string output_prefix);
        // extract slice sliceId and write to output - define in .cpp
        void extract(int sliceId, std::string output_prefix);
        // number of bytes uses to store image, data bytes and pointers 
        //  (ignore vector<> container, dims etc)
        int volImageSize(void); // define in .cpp
    };
}

#endif