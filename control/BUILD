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
