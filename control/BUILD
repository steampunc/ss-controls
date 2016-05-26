cc_binary(
  name = "state_space",
  deps = ["//third_party/eigen:eigen",
          ":ss_plant"],
)

cc_library(
  name = "ss_plant",
  hdrs = ["state_space_plant.h"],
  srcs = ["state_space_plant.hpp"],
  visibility = ["//visibility:public"]
)

cc_library(
  name = "ss_controller",
  hdrs = ["state_space_controller.h"],
  srcs = ["state_space_controller.hpp"],
  visibility = ["//visibility:public"]
)
