# pytorch-cpp-example
Sample scripts for testing PyTorch models in C++

Authors: Muralikeishnan Gopalakrishnan Meena & Matthew R. Norman (ORNL)
Email: gopalakrishm@ornl.gov

# Description

These are sample scripts to load a PyTorch model and run a forward step. These are adapted from PyTorch's docs for [LOADING A TORCHSCRIPT MODEL IN C++](https://pytorch.org/tutorials/advanced/cpp_export.html#loading-a-torchscript-model-in-c). They also have instructions in the doc to convert a PyTorch model to torch script in Python.

There are 2 examples:
1. CPU implementation `example_pytorchNN_cpu.cpp`
2. GPU implementation `example_pytorchNN_gpu.cpp`

For more details on the PyTorch C++ frontend API used, refer to `torch_interface.cpp`.

The sample [model](PyTModel_filteredNtrain100000regularized0_epoch4999_Cpp.pt) used here is for a fluid flow emulator which takes 36 inputs and gives 4 outputs.

# Usage

1. Go to [build](build/) folder
    ```
    cd build
    ```
3. Activate binaries using environment file corresponding to your machine
    ```
    source <machineName>_<cpu/gpu>.env
    ```
    Example: For running on GPU on Summit
    ```
    source summit_gpu.env
    ```
3. Compile: 
    ```
    ./cmakescript
    make -j
    ```
4. Run:
    ```
    ./example
    ```
    
* Sample output for the GPU usage (`example_pytorchNN_gpu.cpp`)
  ```
  Model loaded succefully!
  Number of CUDA devices: 1
  Sample output (scaled flow properties): -0.95627  4.08107  -2.88555  -0.970117
  ```
