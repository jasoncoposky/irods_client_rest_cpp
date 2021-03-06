/**
* iRODS REST API
* This is the iRODS REST API
*
* OpenAPI spec version: 1.0.0
* Contact: info@irods.org
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/

#include "pistache/endpoint.h"
#include "pistache/http.h"
#include "pistache/router.h"
#include "StreamGetApiImpl.h"

using namespace io::swagger::server::api;

namespace ir   = irods::rest;
namespace irck = irods::rest::configuration_keywords;

int main() {
    auto cfg  = ir::configuration{ir::service_name};
    auto port = cfg[irck::port];
    if(port.empty()) {
        std::cerr << "port is not configured for service name " << ir::service_name << std::endl;
        return 3;
    }

    auto threads = cfg[irck::threads];
    if(threads.empty()) {
        threads = 4;
    }

    auto addr = Pistache::Address(Pistache::Ipv4::any(), Pistache::Port(port.get<int>()));

    auto server = StreamGetApiImpl(addr);
    server.init(threads);
    server.start();

    server.shutdown();
}

