template <int NumStates, int NumInputs>
StateSpaceController<NumStates, NumInputs>::StateSpaceController(
    Eigen::Matrix<double, NumInputs, NumStates> K) {
  K_ = K;
}

template <int NumStates, int NumInputs>
StateSpaceController<NumStates, NumInputs>::~StateSpaceController() {}

template <int NumStates, int NumInputs>
void StateSpaceController<NumStates, NumInputs>::Update(
    Eigen::Matrix<double, NumStates, 1> X) {
  U_ = K_ * (R_ - X);
}

template <int NumStates, int NumInputs>
Eigen::Matrix<double, NumInputs, 1>
StateSpaceController<NumStates, NumInputs>::GetU() {
  return U_;
}

template <int NumStates, int NumInputs>
void StateSpaceController<NumStates, NumInputs>::SetGoal(
    Eigen::Matrix<double, NumStates, 1> R) {
  R_ = R;
}
