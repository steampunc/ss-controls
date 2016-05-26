#include "control/state_space_controller.h"
#include "control/state_space_plant.h"
#include "gtest/gtest.h"

using namespace muan::control::state_space;

TEST(Controller, doesDiverge) {
  Eigen::Matrix<double, 1, 1> A;
  A << 1;
  Eigen::Matrix<double, 1, 1> B;
  B << 1;
  Eigen::Matrix<double, 1, 1> C;
  C << 1;
  Eigen::Matrix<double, 1, 1> K;
  K << -1;
  StateSpacePlant<1, 1, 1> plant(A, B, C);
  StateSpaceController<1, 1> controller(K);
  Eigen::Matrix<double, 1, 1> X;
  X << 0;
  Eigen::Matrix<double, 1, 1> R;
  R << 10;
  plant.SetX(X);
  controller.SetGoal(R);
  for (float i; i < 10; i++) {
    controller.Update(plant.GetX());
    plant.Update(controller.GetU());
  }

  ASSERT_TRUE(plant.GetX()(0, 0) < 0);
}

TEST(Controller, doesConverge) {
  Eigen::Matrix<double, 1, 1> A;
  A << 1;
  Eigen::Matrix<double, 1, 1> B;
  B << 1;
  Eigen::Matrix<double, 1, 1> C;
  C << 1;
  Eigen::Matrix<double, 1, 1> K;
  K << .9;
  StateSpacePlant<1, 1, 1> plant(A, B, C);
  StateSpaceController<1, 1> controller(K);
  Eigen::Matrix<double, 1, 1> X;
  X << 0;
  Eigen::Matrix<double, 1, 1> R;
  R << 10;
  plant.SetX(X);
  controller.SetGoal(R);
  for (float i; i < 10; i++) {
    controller.Update(plant.GetX());
    plant.Update(controller.GetU());
  }

  ASSERT_NEAR(plant.GetX()(0, 0), 10, 0.1);
}
