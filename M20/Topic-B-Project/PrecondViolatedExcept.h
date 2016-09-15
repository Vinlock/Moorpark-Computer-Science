//
//  PrecondViolatedExcept.h
//  Topic B Project
//
//  Created by Dak Washbrook on 9/13/16.
//

#ifndef PrecondViolatedExcept_h
#define PrecondViolatedExcept_h

#include <stdexcept>
#include <string>

class PrecondViolatedExcept : public std::logic_error {
public:
    PrecondViolatedExcept(const std::string& message = " ");
};


#endif /* PrecondViolatedExcept_h */
