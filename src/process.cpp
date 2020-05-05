#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// DONE: Return this process's ID
int Process::Pid() { return pid_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() { 
    long total_time=LinuxParser::ActiveJiffies(Process::Pid());
    float seconds=LinuxParser::UpTime(Pid());
    cpu_utils=(total_time/sysconf(_SC_CLK_TCK))/seconds;
    return cpu_utils;
}
// DONE: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(Process::Pid()); }

// DONE: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(Process::Pid());}

// DONE: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(Process::Pid());}

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(Process::Pid()); }

// DONE: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { return (a.cpu_utils > Process::cpu_utils); }