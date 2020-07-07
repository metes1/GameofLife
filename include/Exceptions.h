/**
 * \file Exceptions.h
 * \brief Defines exceptions for this project.
 * \author Seda Mete metes1
 * \date April 9th, 2019
*/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class invalid_file : public std::exception {
   const char * what () const throw () {
      return "file not found";
   }
};

class out_of_bounds : public std::exception {
   const char * what () const throw () {
      return "out of bounds";
   }
};

#endif