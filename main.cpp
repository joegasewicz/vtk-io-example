#include <iostream>
#include <vtkPolyDataReader.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>


int main(int argc, char *argv[]) {
    std::cout << "VTK Demo #1 loading..." << std::endl;

    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " Filename" << std::endl;
        return EXIT_FAILURE;
    }

    std::string filename = argv[1];
    std::cout << "Loading Filename: " << filename << std::endl;

    // Read all the data file
    vtkSmartPointer<vtkPolyDataReader> reader = vtkSmartPointer<vtkPolyDataReader>::New();
    reader->SetFileName(filename.c_str());
    reader->Update();

    // get the specific polydata & check the results
    vtkPolyData *poly_data = reader->GetOutput();
    poly_data->Print(std::cout);


    return 0;
}
