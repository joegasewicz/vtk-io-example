#include <iostream>
#include <vtkPolyDataReader.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkDelaunay3D.h>
#include <vtkXMLDataSetWriter.h>
#include <vtkUnstructuredGridWriter.h>


int main(int argc, char *argv[]) {
    std::cout << "Jewel App loading..." << std::endl;

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

    // Triangulate the grid points
    vtkSmartPointer<vtkDelaunay3D> delaunay = vtkSmartPointer<vtkDelaunay3D>::New();
    delaunay->SetInputData(poly_data);
    delaunay->Update();

    // write to xml
    vtkSmartPointer<vtkXMLDataSetWriter> writer = vtkSmartPointer<vtkXMLDataSetWriter>::New();
    writer->SetFileName("../xml/delaunay_3dbox.xml");
    writer->SetInputConnection(delaunay->GetOutputPort());
    writer->SetDataModeToBinary();
    writer->Write();

    // write to legacy
    vtkSmartPointer<vtkUnstructuredGridWriter> poly_writer = vtkSmartPointer<vtkUnstructuredGridWriter>::New();
    poly_writer->SetFileName("../vtk/delaunay_3dbox_unstructured.vtk");
    poly_writer->SetInputConnection(delaunay->GetOutputPort());
    poly_writer->Write();

    return 0;
}
