#include "third_party/eigen/Eigen/Core"

namespace muan {
namespace control {
namespace state_space {

template <int NumStates, int NumInputs>
class StateSpaceController {
 public:
  StateSpaceController(Eigen::Matrix<double, NumInputs, NumStates> K);
  ~StateSpaceController();
  void Update(Eigen::Matrix<double, NumStates, 1> X);
  Eigen::Matrix<double, NumInputs, 1> GetU();
  void SetGoal(Eigen::Matrix<double, NumStates, 1> R);

 protected:
  Eigen::Matrix<double, NumStates, 1> R_;
  Eigen::Matrix<double, NumInputs, 1> U_;
  Eigen::Matrix<double, NumInputs, NumStates> K_;
};

#include "state_space_controller.hpp"

}  // state_space
}  // control
}  // muan
