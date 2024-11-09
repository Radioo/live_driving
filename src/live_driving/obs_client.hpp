#pragma once

#include <string>
#include <curl/curl.h>
#include <rapidjson/document.h>

namespace live_driving {
    class obs_client {
    public:
        obs_client(std::string url, std::string password);

        void listen();
        void switch_scene(const std::string& scene_name) const;

    private:
        static inline bool curl_initialized = false;

        bool authenticated = false;

        std::string url;
        std::string password;

        CURL* curl = nullptr;

        void connect() const;

        void handle_response(const char* data);
        void handle_authentication(const rapidjson::Document& document) const;
        void send(const rapidjson::Document& document) const;
    };
}