/**
 * Author: Rayaan Fakier
 * Date: 01-04-2017
 * VolImage class for Assignment 2
 */

#include "vim.h"

using namespace std;

int width, height; // width and height of image stack
vector<unsigned char**> slices; // data for each slice, in order