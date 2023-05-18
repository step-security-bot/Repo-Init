#pragma once

#include <linux/if_packet.h>

#include <string>

/**
 * @brief Stats produced by RawSocket
 */
struct RawSocketStats {
	/// Number of bytes written to socket
	size_t sentBytes;
	/// Number of bytes read from socket
	size_t receivedBytes;
	/// Total execution time in nanoseconds
	double processingTime;
};

/**
 * @brief Raw socket reads and writes binary data to provided interface. Write operations does not modify any field
 * (MAC, IP etc). Only writes the full data directly like file write operations.
 */
class RawSocket {
  private:
	/// Ready flag
	bool isReady{false};
	/// Mode indicator. True = Write, False = Read
	bool writeMode{false};
	/// Socket descriptor
	int sockFd{-1};
	/// Currently used ethernet interface
	std::string iFace;
	/// Socket structure
	sockaddr_ll addr{};
	/// Internal structure for statistics
	RawSocketStats stats{};

	void init(int domain, int type, int protocol, sockaddr_ll &_addr);

  public:
	/**
	 * @brief Construct a new RawSocket class
	 * @param[in] iface Ethernet interface
	 * @param[in] isWrite True if write mode, false if read mode requested
	 */
	explicit RawSocket(std::string iface, bool isWrite = false);

	/// @brief Copy constructor
	RawSocket(const RawSocket & /*unused*/) = delete;

	/// @brief Move constructor
	RawSocket(RawSocket && /*unused*/) = delete;

	/// @brief Copy assignment operator
	RawSocket &operator=(RawSocket /*unused*/) = delete;

	/// @brief Move assignment operator
	RawSocket &operator=(RawSocket && /*unused*/) = delete;

	/**
	 * @brief Returns the binded ethernet interface
	 * @return std::string Name of the interface
	 */
	std::string getInterfaceName() const { return iFace; }

	/**
	 * @brief Writes data to interface
	 * @param[in] data Full payload data to write
	 * @param[in] dataLen Length of the data
	 * @return int Status of operation. Return the number of written bytes, negative on errors.
	 */
	int writeData(const void *data, size_t dataLen);

	/**
	 * @brief Reads data from interface
	 * @param[out] data User allocated data
	 * @param[out] dataLen Length of the data
	 * @return int Status of operation. Return the number of read bytes, negative on errors.
	 */
	int readData(void *data, size_t dataLen);

	/**
	 * @brief Get the statistics of class
	 * @param[in] resetInternalStats Whether internal statistics structure should be reset after returned
	 * @return RawSocketStats Produced statistics
	 */
	RawSocketStats getStats(bool resetInternalStats = false);

	/**
	 * @brief Destroy the RawSocket object
	 */
	~RawSocket();
};
