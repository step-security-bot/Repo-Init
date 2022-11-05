#pragma once

#include <string>

#include <curl/curl.h>

class HTTP
{
  private:
	// CURL handler
	CURL *curl;
	// Full path of server
	std::string hostAddr;

	static size_t writeDataCallback(void *contents, size_t size, size_t nmemb, void *userp);

  public:
	/**
	 * @brief Constructs a new HTTP class
	 * @param[in] addr Full path to server
	 * @param[in] timeoutInMs Connection timeout in milliseconds
	 */
	explicit HTTP(const std::string &addr, int timeoutInMs = 1000);

	/**
	 * @brief Sends a POST request
	 * @param[in] index Value to append to server address
	 * @param[in] payload Payload to send to server
	 * @param[out] receivedData Received reply from server
	 * @return CURLcode Status of operation. CURLE_OK if successful.
	 */
	CURLcode sendPOSTRequest(const std::string &index, const std::string &payload, std::string &receivedData);

	/**
	 * @brief Sends a GET request
	 * @param[in] index Value to append to server address
	 * @param[in] receivedData Received reply from server
	 * @return CURLcode Status of operation. CURLE_OK if successful.
	 */
	CURLcode sendGETRequest(const std::string &index, std::string &receivedData);

	/**
	 * @brief Destroys the HTTP object
	 */
	~HTTP();
};