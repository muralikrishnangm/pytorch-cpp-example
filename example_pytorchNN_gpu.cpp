// Sample C++ script to test PyTorch model for flow evolution
// NN model from `MLprediction4Pytorch_v2crossval.ipynb`
// By MGM (ORNL)
// September 16 2020

#include <iostream>
#include <memory>
#include "torch_interface.h"

int main() {
  // Create the model
  int mod_id = torch_add_module( "../PyTorch_model_Cpp.pt" );
  std::cout << "Model loaded succefully!\n";
  
  // Get number of CUDA devices
  std::cout << "Number of CUDA devices: " << torch_get_cuda_device_count() << "\n";

  // Use CUDA device # 2
  int devicenum = 0;
 
  // Move model to GPU
  torch_move_module_to_gpu( mod_id , devicenum );

  // Create a vector of inputs.
  int constexpr num_inputs = 36;
  std::vector<float> inputs(num_inputs);
  for (int i=0; i < num_inputs; i++) {
    inputs[i] = static_cast<double>( std::rand() ) / static_cast<double>(RAND_MAX);
  }
  // Create a tensor of inputs on the CPU
  int tensor_in_id = torch_add_tensor( inputs.data() , {1,num_inputs });
  // Move tensor of inputs to the GPU
  torch_move_tensor_to_gpu(tensor_in_id , devicenum);

  // Execute the model and turn its output into a tensor.
  int tensor_out_id = torch_module_forward( mod_id , {tensor_in_id} );

  // Move the output tensor to the cpu
  torch_move_tensor_to_cpu(tensor_out_id);

  // Convert the torch tensor to a std::vector
  std::vector<float> outputs;
  torch_tensor_to_vector( tensor_out_id , outputs );

  // Output the data
  std::cout << "Sample output (scaled flow properties): ";
  for (int i=0; i < outputs.size(); i++) {
    std::cout << outputs[i] << "  ";
  }
  std::cout << std::endl;
}
