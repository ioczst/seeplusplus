#include <iostream>
#include <curl/curl.h>
#include <string>

// This function will be called by libcurl when data is received
size_t write_callback(char* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append(ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string content;

    curl = curl_easy_init();
    if (curl) {
        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, "http://google.com");

        // Set the write callback function to capture the response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        // Pass a pointer to the string where the response will be stored
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);

        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        // Cleanup
        curl_easy_cleanup(curl);
    }

    // Print the retrieved content
    std::cout << "Retrieved content:\n" << content << std::endl;

    return 0;
}
