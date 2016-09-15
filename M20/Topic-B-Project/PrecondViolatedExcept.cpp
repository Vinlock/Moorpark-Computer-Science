//
//  PrecondViolatedExcept.cpp
//  Topic B Project
//
//  Created by Dak Washbrook on 9/13/16.
//

#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message) : std::logic_error("Precondition Violated Exception: " + message) {}