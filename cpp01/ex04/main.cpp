#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
    if (from.empty())
        return str;

    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str = str.substr(0, start_pos) + to + str.substr(start_pos + from.length());
        start_pos += to.length();
    }
    return str;
}

int main(int argc, char** argv)
{
    if (argc != 4){
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()){
        std::cerr << "error: search string cannot be empty" << std::endl;
        return 1;
    }

    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open()){
        std::cerr << "Error: could note open file " << filename << std::endl;
        return 1;
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: could not create file " << outFilename << std::endl;
        inFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::string replacedLine = replaceAll(line, s1, s2);

        outFile << replacedLine;

        if (!inFile.eof())
            outFile << std::endl;
    }

    inFile.close();
    outFile.close();

    std::cout << "Replacement complete. Output written " << outFilename << std::endl;
    return 0;
}