#include "eigen/Eigen/Core"

template <int NumStates, int NumInputs, int NumSensors>
class StateSpace {
public:
  void SetGoal(Eigen::Matrix <double, NumStates, 1> R );
  StateSpace SetSystem(Eigen::Matrix <double, NumStates, NumStates> A,
                 Eigen::Matrix <double, NumStates, NumInputs> B,
                 Eigen::Matrix <double, NumSensors, NumStates> C);
  void Update(Eigen::Matrix <double, NumInputs, 1);
protected:
  Eigen::Matrix <double, NumStates, 1> X_;
  Eigen::Matrix <double, NumStates, 1> R_;
  Eigen::Matrix <double, NumSensors, 1> Y_;
  Eigen::Matrix <double, NumInputs, 1> U_;
  Eigen::Matrix <double, NumStates, NumStates> A_;
  Eigen::Matrix <double, NumStates, NumInputs> B_;
  Eigen::Matrix <double, NumSensors, NumStates> C_;
}
