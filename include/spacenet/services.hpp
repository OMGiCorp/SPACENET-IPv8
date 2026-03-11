#ifndef SPACENET_SERVICES_HPP
#define SPACENET_SERVICES_HPP

#include <string_view>
#include <vector>

#include "services.h"

namespace spacenet {

using ServiceInfo = spacenet_service_info_t;

const std::vector<ServiceInfo> &all_services();
const ServiceInfo *find_service(std::string_view name);
const ServiceInfo *find_service(uint16_t port, std::string_view transport);

} // namespace spacenet

#endif
