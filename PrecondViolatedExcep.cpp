// Program Information /////////////////////////////////////////////////////
/**
 * @file PrecondViolatedExcep.cpp
 *
 * @brief Implementation file for PrecondViolatedExcep
 *
 * @details - none
 *
 * @version 1.01
 *          Hadi Rumjahn (18 September 2016)
 *          Adapted code Frank M. Carrano and Timothy M. Henry
 *
 *          Frank M. Carrano and Timothy M. Henry
 *          Copyright (2017) Retrieved from Reference 7-5
 *
 * @note requires PrecondViolatedExcep header file
 */

// Pre compiler directives ///////////////////////////////////////////////////

	// none

// Header Files /////////////////////////////////////////////////////////////
#include "PrecondViolatedExcep.h"
/**
 * @brief Displays error message if a logic error is produced during runtime of program
 *
 * @details Initializes a general message for the exception
 *
 * @pre none
 *
 * @post display error message adjusted by user
 *
 * @par Algorithm
 *      Initializes a precondition message
 *
 * @exception throws a logic error for debugging functions
 *
 * @param[in] message is the message that will output to the console describing what error occured
 *
 */
PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
	: std::logic_error("Precondition Violated Exception: " + message)
{
}
