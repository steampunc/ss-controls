#include "state_space.h"

namespace muan {
namespace control {
namespace ss_controller {
 
StateSpace StateSpace::SetSystem(Eigen::Matrix <double, NumStates, NumStates> A,
                 Eigen::Matrix <double, NumStates, NumInputs> B,
                 Eigen::Matrix <double, NumSensors, NumStates> C);

        //TODO (Finn): Do stuff here

} //ss_controller
} //control
} //muan
