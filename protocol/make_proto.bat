protoc --cpp_out=. --proto_path=/projects/protobuf-2.5.0/src --proto_path=. *.proto
protoc --plugin=protoc-gen-ANT=comptest.exe --ANT_out=. --proto_path=/projects/protobuf-2.5.0/src --proto_path=. *.proto
