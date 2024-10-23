//
// Created by hmkam on 03/10/2024.
//

#include "WebReader.hpp"

#include <sstream>

WebReader::WebReader(): curlptr(curl_easy_init(), &curl_easy_cleanup), result() {
    if (!curlptr)
        std::cerr << "CURL POINTER UNABLE TO INITIALIZE!" << std::endl;
}

std::vector<std::string> WebReader::openFile(const std::string &url) {
    // std::vector<char> buffer;
    std::stringstream buffer;
    std::vector<std::string> data;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl_easy_setopt(curlptr.get(), CURLOPT_URL, url.c_str()); //From where to read the data.
    //Set curl options
    curl_easy_setopt(curlptr.get(), CURLOPT_CAINFO, "../libs/curl/bin/curl-ca-bundle.crt");
    curl_easy_setopt(curlptr.get(), CURLOPT_CA_CACHE_TIMEOUT, 60L);
    curl_easy_setopt(curlptr.get(), CURLOPT_WRITEFUNCTION, StreamCallback); //Callback function for data processing
    // curl_easy_setopt(ptr, CURLOPT_VERBOSE, 1L); //Callback function for data processing
    curl_easy_setopt(curlptr.get(), CURLOPT_WRITEDATA, &buffer); //Where the data will be written to
    // curl_easy_setopt(ptr, CURLOPT_SSL_VERIFYPEER, 0L);
    // curl_easy_setopt(ptr, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curlptr.get(), CURLOPT_FOLLOWLOCATION, 1L); //HTTP Redirection to HTTPS

    //Read File
    result = curl_easy_perform(curlptr.get());

    if (result != CURLE_OK) {
        std::cerr << "RESULT CANT BE PARSED!" << " " << curl_easy_strerror(result) << std::endl;
    }

    //Process the data?

    std::cout << buffer.str() << std::endl;
    curl_global_cleanup();

    return data;
}

size_t WebReader::StreamCallback(void *contents, size_t size, size_t nmemb, std::stringstream *userp) {
    //Do things...
    const size_t totalSize = size * nmemb;
    userp->write(static_cast<char *>(contents), static_cast<std::streamsize>(totalSize));

    return totalSize;
}
