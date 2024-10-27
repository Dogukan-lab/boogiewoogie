//
// Created by doguk on 10/24/2024.
//

#include "WebReader.hpp"

#include <algorithm>
#include <D:/GitHub/boogiewoogie/libs/curl/include/curl/curl.h>
#include <sstream>

void _trim(std::string &line) {
    line.erase(std::remove_if(line.begin(), line.end(), [](char c) {
        return c == '\r' || c == '\n';
    }), line.end());
}

WebReader::WebReader(const std::string &sourceFile): FileReader(sourceFile),
                                                     curlptr(curl_easy_init(), curl_easy_cleanup) {}

WebReader::~WebReader() = default;

std::string WebReader::ExtractFileType() {
    //PosA checks for the last occurence of the dot, because of looking for a file extension
    //PosB checks for the las occurence of the ?, because we dont want the query alongside the file extension
    const size_t posA = source.find_last_of('.');
    const size_t posB = source.find_last_of('?');
    auto string = source.substr(posA, posB - posA);
    std::cout << string << std::endl;
    return string;
}

void WebReader::OpenStream() {
    if (!curlptr) {
        std::cerr << "CURL POINTER NOT INITIALIZED!" << std::endl;
        curlptr = std::unique_ptr<CURL, decltype(&curl_easy_cleanup)>(curl_easy_init(), &curl_easy_cleanup);
    }

    //init curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    //Set url to read from
    curl_easy_setopt(curlptr.get(), CURLOPT_URL, source.c_str());
    //Set certificate
    curl_easy_setopt(curlptr.get(), CURLOPT_CAINFO, "../libs/curl/bin/curl-ca-bundle.crt");
    //Set certificate cache time (I believe this is 60seconds) + (optional).
    curl_easy_setopt(curlptr.get(), CURLOPT_CA_CACHE_TIMEOUT, 60L);
    //HTTP Redirection to HTTPS
    curl_easy_setopt(curlptr.get(), CURLOPT_FOLLOWLOCATION, 1L);
}

std::vector<std::string> WebReader::ReadLines() {
    std::stringstream buffer{};
    std::vector<std::string> data{};

    //Set stream locations
    curl_easy_setopt(curlptr.get(), CURLOPT_WRITEFUNCTION, StreamCallback);
    curl_easy_setopt(curlptr.get(), CURLOPT_WRITEDATA, &buffer);

    //Read webstream
    if (const CURLcode result = curl_easy_perform(curlptr.get()); result != CURLE_OK) {
        throw std::runtime_error(curl_easy_strerror(result));
    }

    //Copy stringstream data into temp vector
    std::string line{};
    while (std::getline(buffer, line)) {
        _trim(line);
        data.emplace_back(line);
    }

    return data;
}

void WebReader::CloseStream() {
    curl_global_cleanup();
    curlptr.reset();
}

size_t WebReader::StreamCallback(void *contents, size_t size, size_t nmemb, std::stringstream *userp) {
    //Have to count the total of bytes read.
    const size_t totalSize = size * nmemb;

    //Write contents of bytes read.
    userp->write(static_cast<char *>(contents), static_cast<std::streamsize>(totalSize));

    return totalSize;
}
