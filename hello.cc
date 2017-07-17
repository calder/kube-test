#include "grpc++/grpc++.h"
#include "hello.grpc.pb.h"

class HelloServiceImpl final : public HelloService::Service {
  grpc::Status Hello(grpc::ServerContext* context, const HelloRequest* request,
                  HelloResponse* response) override {
    response->set_message("Hello, " + request->name() + "!");
    return grpc::Status::OK;
  }
};

int main() {
  std::string server_address = "0.0.0.0:50051";

  HelloServiceImpl service;
  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}
