
master_proto:
	mkdir -p generated
	protoc -I proto --cpp_out=generated --grpc_out=generated --plugin=protoc-gen-grpc=$(shell which grpc_cpp_plugin) proto/master.proto

worker_proto:
	mkdir -p generated
	protoc -I proto --cpp_out=generated --grpc_out=generated --plugin=protoc-gen-grpc=$(shell which grpc_cpp_plugin) proto/worker.proto
