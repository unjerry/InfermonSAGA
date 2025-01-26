#include <iostream>
#include <manyfold.h>

int main()
{
    manyfold::manyfold M;
    std::string filename;

    filename = "cubeBlender.obj";
    std::ifstream inFile(filename);
    if (!inFile)
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
    inFile >> M;

    filename = "cubeBlenderOut.obj";
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
    outFile << M;
    std::cout << M;

    return 0;
}
