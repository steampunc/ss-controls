template <int NumStates, int NumInputs, int NumOutputs>
StateSpacePlant<NumStates, NumInputs, NumOutputs>::StateSpacePlant(
    Eigen::Matrix<double, NumStates, NumStates> A,
    Eigen::Matrix<double, NumStates, NumInputs> B,
    Eigen::Matrix<double, NumOutputs, NumStates> C) {
  A_ = A;
  B_ = B;
  C_ = C;
}

template <int NumStates, int NumInputs, int NumOutputs>
StateSpacePlant<NumStates, NumInputs, NumOutputs>::~StateSpacePlant() {}

template <int NumStates, int NumInputs, int NumOutputs>
void StateSpacePlant<NumStates, NumInputs, NumOutputs>::Update(
    Eigen::Matrix<double, NumInputs, 1> U) {
  U_ = U;
  X_ = A_ * X_ + B_ * U_;
  Y_ = C_ * X_;
}

template <int NumStates, int NumInputs, int NumOutputs>
Eigen::Matrix<double, NumStates, 1>
StateSpacePlant<NumStates, NumInputs, NumOutputs>::GetX() {
  return X_;
}

template <int NumStates, int NumInputs, int NumOutputs>
Eigen::Matrix<double, NumOutputs, 1>
StateSpacePlant<NumStates, NumInputs, NumOutputs>::GetY() {
  return Y_;
}

template <int NumStates, int NumInputs, int NumOutputs>
void StateSpacePlant<NumStates, NumInputs, NumOutputs>::SetX(
    Eigen::Matrix<double, NumStates, 1> X) {
  X_ = X;
}
