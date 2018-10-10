
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include "template.hpp"
using namespace std;

picojson::value read(string filename){
    
    std::ifstream ifs(filename, std::ios::in);
    if (ifs.fail()) {
        std::cerr << "failed to read test.json" << std::endl;
        throw std::exception();
    }
    const std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    ifs.close();

    // JSONデータを解析する。
    picojson::value v;
    const std::string err = picojson::parse(v, json);
    if (err.empty() == false) {
        std::cerr << err << std::endl;
        throw std::exception();
    }
    return v;
}

int main(){

    picojson::value v = read("sample.json");
    std::cout << "all:" << v << std::endl << std::endl;

    auto data = getValue<string>(v, "license", "data", "key");
    std::cout << "result:" << data << std::endl;

    return 0;
}
