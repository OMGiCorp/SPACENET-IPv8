#ifndef SPACENET_SERVICES_H
#define SPACENET_SERVICES_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct spacenet_service_info {
    const char *name;
    uint16_t port;
    const char *transport;
    const char *description;
    const char *rfc;
} spacenet_service_info_t;

const spacenet_service_info_t *spacenet_services(void);
size_t spacenet_services_count(void);
const spacenet_service_info_t *spacenet_find_service_by_name(const char *name);
const spacenet_service_info_t *spacenet_find_service_by_port(uint16_t port, const char *transport);

#ifdef __cplusplus
}
#endif

#endif
