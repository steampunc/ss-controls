#include "control/state_space_plant.h"
#include "gtest/gtest.h"

using namespace muan::control::state_space;

TEST(Plant, doesDiverge) {
  Eigen::Matrix<double, 1, 1> A;
  A << 2;
  Eigen::Matrix<double, 1, 1> B;
  B << 0;
  Eigen::Matrix<double, 1, 1> C;
  C << 1;
  StateSpacePlant<1, 1, 1> plant(A, B, C);
  Eigen::Matrix<double, 1, 1> X;
  X << 1E-2;
  plant.SetX(X);
  for (float i; i < 10; i++) {
    Eigen::Matrix<double, 1, 1> U;
    U << 0;
    plant.Update(U);
  }

  ASSERT_TRUE(plant.GetX()(0, 0) > 1);
}

TEST(Plant, doesConverge) {
  Eigen::Matrix<double, 1, 1> A;
  A << 0.5;
  Eigen::Matrix<double, 1, 1> B;
  B << 0;
  Eigen::Matrix<double, 1, 1> C;
  C << 1;
  StateSpacePlant<1, 1, 1> plant(A, B, C);
  Eigen::Matrix<double, 1, 1> X;
  X << 10;
  plant.SetX(X);
  for (float i; i < 10; i++) {
    Eigen::Matrix<double, 1, 1> U;
    U << 0;
    plant.Update(U);
  }

  ASSERT_NEAR(plant.GetX()(0, 0), 0, 0.01);
}
