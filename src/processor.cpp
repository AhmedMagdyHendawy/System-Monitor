#include "processor.h"
#include "linux_parser.h"
#include <string>

using std::stof;
using LinuxParser::CPUStates;

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() {
    cpu_utils=LinuxParser::CpuUtilization();
    float Idle = stof(cpu_utils[CPUStates::kIdle_]) + stof(cpu_utils[CPUStates::kIOwait_]);
    float NonIdle = stof(cpu_utils[CPUStates::kUser_]) + stof(cpu_utils[CPUStates::kNice_]) + stof(cpu_utils[CPUStates::kSystem_]) +stof(cpu_utils[CPUStates::kIRQ_])+ stof(cpu_utils[CPUStates::kSoftIRQ_]) +stof(cpu_utils[CPUStates::kSteal_]);
    float Total = Idle + NonIdle;
    return (Total-Idle)/Total;
 }