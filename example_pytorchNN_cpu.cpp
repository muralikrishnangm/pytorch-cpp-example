// Sample C++ script to test PyTorch model for flow evolution
// NN model from `MLprediction4Pytorch_v2crossval.ipynb`
// By MGM (ORNL)
// September 16 2020

#include <torch/script.h> // One-stop header.

#include <iostream>
#include <memory>

int main() {
  char const * fname = "../PyTorch_model_Cpp.pt";
  torch::jit::script::Module module;
  try {
    // Deserialize the ScriptModule from a file using torch::jit::load().
    module = torch::jit::load(fname);
  }
  catch (const c10::Error& e) {
    std::cerr << "\nError loading the model...\n";
    return -1;
  }
  std::cout << "\nModel loaded succefully!\n";

  // Create a vector of inputs.
  std::vector<torch::jit::IValue> inputs;
  inputs.push_back(torch::ones({1, 36}));

  // Execute the model and turn its output into a tensor.
  at::Tensor output = module.forward(inputs).toTensor();
  std::cout << "Sample output (scaled flow properties):"
  << output.slice(/*dim=*/1, /*start=*/0, /*end=*/4) << '\n';
}
