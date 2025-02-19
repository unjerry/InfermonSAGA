#include <iostream>
#include <manyfold.h>

int main()
{
    manyfold::manyfold M;
    std::string filename;
    std::string basename;

    basename = "sphere";
    filename = basename + ".obj";
    std::ifstream inFile(filename);
    if (!inFile)
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
    inFile >> M;
    inFile.close();
    filename = basename + "Out.obj";
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
    outFile << M;
    std::cout << M;
    outFile.close();

    basename = "cubeBlender";
    filename = basename + ".obj";
    inFile.open(filename);
    if (!inFile)
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
    inFile >> M;
    inFile.close();
    filename = basename + "Out.obj";
    outFile.open(filename);
    if (!outFile)
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
    outFile << M;
    std::cout << M;
    outFile.close();

    return 0;
}
