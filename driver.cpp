/**
 * Author: Rayaan Fakier
 * Date: 01-04-2017
 * Driver class for Assignment 2
 */

#include "vim.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    if(argc > 2){
         // do others
//         for (int i = 1; i < argc; ++i)0 {
//            string args = argv[i];
//        }
    }
    else{
        FKRRAY001::VolImage * vim = new FKRRAY001::VolImage();
        string bname(argv[1]);
        if(vim->readImages(bname)){
            cout << "File loaded successfully" << endl;
            delete vim;
            
        }
        else
            cout << "File load failed" << endl;
    }
    return 0;
}
