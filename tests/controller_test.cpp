#include "gtest/gtest.h"
#include "control/state_space.h"

using namespace muan::control::state_space {

TEST(Plant, doesDiverge) {
  controller.SetSystem( // should be objectSetSystem(constants.K_a, constants.K_b, constants.K_c);
  plant.Reset();
  for(float i; i < 10; i++) {
    plant.Update(Voltageofsomesort)
  } 
}

TEST(Plant, doesConverge) {
  
}

} //muan::control::state_space
