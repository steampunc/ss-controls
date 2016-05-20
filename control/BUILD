cc_binary(
  name = "state_space",
  deps = ["//third_party/eigen:eigen",
          ":ss_controller"],
)

cc_library(
  name = "ss_controller",
  hdrs = ["state_space.h"],
  srcs = ["state_space.hpp"]
)
