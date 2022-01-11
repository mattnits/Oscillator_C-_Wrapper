#include "Http_Request.h"

memory createSocket(const char *url) {
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    char *results;

    struct memory chunk;

    chunk.memory = NULL;
    chunk.size = 0;

    if (curl) {
        std::cout << "URL: " <<  url << std::endl;
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
        
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cout <<  "CURL ERROR" << std::endl;
        } else {
            std::cout << "Returned " << (int)chunk.size << " bytes" << std::endl;
            
        }
        
        curl_easy_cleanup(curl);
        curl = NULL;
    }

    curl_global_cleanup();

    return chunk;
}



size_t writeCallback(char *contents, size_t size, size_t nmemb, void *userp) {


    size_t realsize = size * nmemb;
    struct memory *mem = (struct memory *)userp;

    char *ptr = (char *)realloc(mem->memory, mem->size + realsize + 1);

    if (ptr == NULL) {
        return 0;
    }

    mem->memory = ptr;

    memcpy(&mem->memory[mem->size], contents, realsize);

    mem->size += realsize;
    mem->memory[mem->size] = 0;

    // std::cout << "Got " << (int)size*nmemb << " bytes" << std::endl;

    return realsize;
    
    
}


void cleanMemory(memory mem) {
    free(mem.memory);
    
    return;
}



std::string urlify(std::string& s) {
    std::string url = "";

    for (int i=0; i < s.length(); i++) {
        if (s.at(i) != ' ') {
            url += s.at(i);
        } else {
            url += "%20";
        }
    }
    
    return url;
}