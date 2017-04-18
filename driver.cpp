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
        string bname = string(argv[2]);
        if(vim->readImages(bname)){
//            vim->dump();
            vim->extract(0,"raw");
            cout << "File loaded" << endl;
            
        }
        else
            cout << "File not found" << endl;
    }
    
    cout << "NOP" << endl;

    return 0;
}
