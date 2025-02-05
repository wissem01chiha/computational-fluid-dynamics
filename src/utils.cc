#include "utils.h"

void str2array(const char* str, double* arr) {

    std::istringstream stream(str);
    int index = 0;
    double val;
    while (stream >> val) 
    {
        arr[index++] = val;
    }
}

void str2double(const char *in, double& num_) {
    try {
        num_ = std::stod(in);
    } catch (const std::exception& e) {
        //LOG_F(ERROR, "failed converting string to double: %s",  e.what());
    }
}

void split(const std::string& str, std::vector<std::string>& split_result,
    const std::string& delimiter) 
{
    size_t start = 0;
    size_t end   = 0;
    while ((end = str.find(delimiter, start)) != std::string::npos) {
        split_result.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }
    split_result.push_back(str.substr(start));
}
