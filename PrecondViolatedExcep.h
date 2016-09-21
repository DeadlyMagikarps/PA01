// Program Information /////////////////////////////////////////////////////
/**
 * @file PrecondViolatedExcep.h
 *
 * @brief Header file for Precondition Violated Exception
 *
 * @details Precondition Violated Exception header files that inherits a std::logic_error publicly
 *          for its member functions
 *
 * @version 1.01
 *          Hadi Rumjahn (18 September 2016)
 *          Adapted code Frank M. Carrano and Timothy M. Henry
 *
 *          Frank M. Carrano and Timothy M. Henry
 *          Copyright (2017) Retrieved from Reference 7-5
 */

// Pre compiler directives ////////////////////////////////////////////////
#ifndef PRECOND_VIOLATED_EXCEPT_
#define PRECOND_VIOLATED_EXCEPT_

// Header Files ///////////////////////////////////////////////////////////
#include <stdexcept>
#include <string>

// Class definition for Precondition Violated Exception
class PrecondViolatedExcept : public std::logic_error {
public:
	PrecondViolatedExcept(const std::string& message = "");
};

#endif // end PRECOND_VIOLATED_EXCEPT_
