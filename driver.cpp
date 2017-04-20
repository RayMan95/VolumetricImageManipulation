/**
 * Author: Rayaan Fakier
 * Date: 01-04-2017
 * Driver class for Assignment 2
 */

#include "vim.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    FKRRAY001::VolImage * vim = new FKRRAY001::VolImage();
    string bname(argv[1]);
    if(vim->readImages(bname)){
        // cout << "File loaded successfully" << endl;
        cout << "Number of images: " << vim->volNumImages() << endl;
        cout << "Number of bytes required: " << vim->volImageSize() << endl;
    }
    else{
        cout << "File load failed" << endl;
    }
    if(argc > 5 and string(argv[2])=="-d"){ // diffmap
//        cout << "diff" << args[0] << args[1] << args[2] << args[3] << args[4] << args[5] << endl;
        vim->diffmap(stoi(string(argv[3])), stoi(string(argv[4])), string(argv[5]));
        
        cout << "Performed a difference map of images " << string(argv[3]) << " and " << string(argv[4]);
        cout << " and stored the resulting image in " << string(argv[5]) << ".raw." << endl;
        
    }
    else if(argc > 2 and string(argv[2])=="-x"){ // extraction
//        cout << "extr" << args[0] << args[1] << args[2] << args[3] << endl;
        vim->extract(stoi(string(argv[3])), string(argv[4]));
        
        cout << "Performed an extraction of slice " << string(argv[3]) << " and wrote it to file " << string(argv[4]) << "." << endl; 
    }
    delete vim;
    return 0;
}
