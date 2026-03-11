#ifndef SPACENET_PROTOCOLS_HPP
#define SPACENET_PROTOCOLS_HPP

#include <string_view>
#include <vector>

#include "protocols.h"

namespace spacenet {

using ProtocolInfo = spacenet_protocol_info_t;

const std::vector<ProtocolInfo> &all_protocols();
const ProtocolInfo *find_protocol(std::string_view name);
const ProtocolInfo *find_protocol(uint8_t number);

} // namespace spacenet

#endif
