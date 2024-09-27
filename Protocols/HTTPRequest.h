#include "../DataStructures/Dictionary/Dictionary.h"

enum HTTPMethods{
    POST,
    GET,
    PUT,
    PATCH,
    DELETE,
    OPTIONS,
    TRACE,
    HEAD,
    CONNECT
};

struct HTTPRequest{
    int method;
    char *URI;
    float HTTPVersion;
    struct Dictionary header_fields;
};

struct HTTPRequest http_request_constructor(char *request_string);
