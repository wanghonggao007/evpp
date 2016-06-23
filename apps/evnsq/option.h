#pragma once

#include <string>

#include "evnsq_export.h"

#include <evpp/duration.h>

namespace evnsq {

    // Option is a struct of NSQ options
    //
    // The only valid way to create a Config is via NewConfig, using a struct literal will panic.
    // After Config is passed into a high-level type (like Consumer, Producer, etc.) the values are no
    // longer mutable (they are copied).
    //
    // Use Set(option string, value interface{}) as an alternate way to set parameters
    struct EVNSQ_EXPORT Option {
    public:
        Option();
        std::string ToJSON() const;

    public:
        bool initialized;

        evpp::Duration dial_timeout; // default:"1s"

        // Deadlines for network reads and writes
        evpp::Duration read_timeout; // min:"100ms" max : "5m" default:"60s"
        evpp::Duration write_timeout; // min:"100ms" max : "5m" default:"1s"

        // Identifiers sent to nsqd representing this client
        // UserAgent is in the spirit of HTTP (default: "<client_library_name>/<version>")
        std::string client_id;// (defaults: short hostname)
        std::string hostname;
        std::string user_agent;

        // Duration of time between heartbeats. This must be less than ReadTimeout
        evpp::Duration heartbeat_interval;// default:"30s"
    };
}