#include "third_party/eigen/Eigen/Core"

namespace muan {
namespace control {
namespace state_space {

template <int NumStates, int NumInputs, int NumOutputs>
class StateSpacePlant {
 public:
  StateSpacePlant(Eigen::Matrix<double, NumStates, NumStates> A,
                  Eigen::Matrix<double, NumStates, NumInputs> B,
                  Eigen::Matrix<double, NumOutputs, NumStates> C);
  ~StateSpacePlant();
  void Update(Eigen::Matrix<double, NumInputs, 1> U);
  Eigen::Matrix<double, NumStates, 1> GetX();
  Eigen::Matrix<double, NumOutputs, 1> GetY();
  void SetX(Eigen::Matrix<double, NumStates, 1> X);

 protected:
  Eigen::Matrix<double, NumStates, 1> X_;
  Eigen::Matrix<double, NumOutputs, 1> Y_;
  Eigen::Matrix<double, NumInputs, 1> U_;
  Eigen::Matrix<double, NumStates, NumStates> A_;
  Eigen::Matrix<double, NumStates, NumInputs> B_;
  Eigen::Matrix<double, NumOutputs, NumStates> C_;
};

#include "state_space_plant.hpp"

}  // state_space
}  // control
}  // muan
