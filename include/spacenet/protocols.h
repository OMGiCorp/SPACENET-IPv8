#ifndef SPACENET_PROTOCOLS_H
#define SPACENET_PROTOCOLS_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct spacenet_protocol_info {
    const char *name;
    uint8_t number;
    const char *layer;
    const char *description;
    const char *rfc;
} spacenet_protocol_info_t;

const spacenet_protocol_info_t *spacenet_protocols(void);
size_t spacenet_protocols_count(void);
const spacenet_protocol_info_t *spacenet_find_protocol_by_name(const char *name);
const spacenet_protocol_info_t *spacenet_find_protocol_by_number(uint8_t number);

#ifdef __cplusplus
}
#endif

#endif
