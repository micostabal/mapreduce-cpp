add_library(proto_master
  ${PROJECT_SOURCE_DIR}/generated/master.pb.cc
  ${PROJECT_SOURCE_DIR}/generated/master.grpc.pb.cc
)

target_include_directories(proto_master
  PUBLIC
    ${PROJECT_SOURCE_DIR}/generated
)

target_link_libraries(proto_master
  PUBLIC
    gRPC::grpc++
    protobuf::libprotobuf
)