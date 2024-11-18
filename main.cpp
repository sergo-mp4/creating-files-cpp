#include <string>
#include <iostream>
#include <fstream>

void createFile(const std::string& filename, const std::string& fileFormat) {
    std::string fullFilename = filename + '.' + fileFormat;

    //check
    std::ifstream infile(fullFilename);
    if (infile.good()) {
        std::cout << "File '" << fullFilename << "' already exists" << std::endl;
        return;
    }

    //create file
    std::ofstream outfile(fullFilename);
    if (!outfile) {
        std::cout << "The file could not be created" << std::endl;
        return;
    }

    if (fileFormat == "txt") {
        outfile << "hi" << std::endl;
    } else if (fileFormat == "csv") {
        outfile << "yeah" << std::endl;
        outfile << "sigma" << std::endl;
        outfile << "im love c++ lmao" << std::endl;
    } else if (fileFormat == "json") {
        outfile << "{\n\t\"1\": \"yeah\",\n\t\"prog\": im love c++ lmao\n}" << std::endl;
    } else {
        std::cout << "Successfully created Other file" << std::endl;
        return;
    }

    std::cout << "File '" << fullFilename << "' Successfully created" << std::endl;
}

int main() {
    std::string filename;
    std::string fileFormat;

    std::cout << "Enter the file name (without extension): ";
    std::getline(std::cin, filename);
    std::cout << "Enter the file format (txt, csv, json): ";
    std::getline(std::cin, fileFormat);

    createFile(filename, fileFormat);

    return 0;
}