//
//  degree.h
//  Scripting and Programming - Applications C++ Project
//
//  Created by Aydan Harrison on 8/21/22.
//

//Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.

#pragma once
#include <string>

enum class DegreeProgram {SECURITY, NETWORK, SOFTWARE};
static const std::string degreeProgramStrings[] = {"SECURITY", "NETWORK", "SOFTWARE"}; //for outputting instead of 0 or 1

