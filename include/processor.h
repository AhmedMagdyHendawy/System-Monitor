#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
#include <string>
class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // DONE: Declare any necessary private members
 private:
    std::vector<std::string> cpu_utils;
};

#endif