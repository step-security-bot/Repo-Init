#pragma once

#include <zmq.hpp>

class ZeroMQ {
  private:
	// Internal context
	std::shared_ptr<zmq::context_t> contextPtr{std::make_shared<zmq::context_t>(1)};
	// Internal socket
	std::unique_ptr<zmq::socket_t> socketPtr;

	// Is currently active
	bool isActive{false};
	// Should be binded
	bool isBinded{false};
	// Address to bind/connect
	std::string socketAddr;

	// Initializes class
	void init(const std::shared_ptr<zmq::context_t> &ctx, const zmq::socket_type &type, const std::string &addr,
			  bool isBind);

  public:
	/**
	 * @brief Construct a new ZeroMQ class
	 * @param[in] type Type of the socket
	 * @param[in] addr Full socket address
	 * @param[in] isBind True if should be binded, false if should be connected
	 */
	ZeroMQ(const zmq::socket_type &type, const std::string &addr, bool isBind);

	/**
	 * @brief Construct a new ZeroMQ class
	 * @param[in] ctx ZeroMQ context
	 * @param[in] type Type of the socket
	 * @param[in] addr Full socket address
	 * @param[in] isBind True if should be binded, false if should be connected
	 */
	ZeroMQ(const std::shared_ptr<zmq::context_t> &ctx, const zmq::socket_type &type, const std::string &addr,
		   bool isBind);

	/// @brief Copy constructor
	ZeroMQ(const ZeroMQ & /*unused*/) = delete;

	/// @brief Move constructor
	ZeroMQ(ZeroMQ && /*unused*/) = delete;

	/// @brief Copy assignment operator
	ZeroMQ &operator=(ZeroMQ /*unused*/) = delete;

	/// @brief Move assignment operator
	ZeroMQ &operator=(ZeroMQ && /*unused*/) = delete;

	/**
	 * @brief Starts the connection
	 * @return True if successfully initialized
	 */
	bool start();

	/**
	 * @brief Stops the connection
	 */
	void stop();

	/**
	 * @brief Receives multipart message
	 * @return std::vector<zmq::message_t> Received messages
	 */
	std::vector<zmq::message_t> recvMessages();

	/**
	 * @brief Sends multipart message
	 * @param[in] msg Messages to send
	 * @return size_t Number of sent messages
	 */
	size_t sendMessages(std::vector<zmq::message_t> &msg);

	/**
	 * @brief Get the reference of socket
	 * @return const std::unique_ptr<zmq::socket_t>&
	 */
	const std::unique_ptr<zmq::socket_t> &getSocket() { return socketPtr; }

	/**
	 * @brief Destroy the ZeroMQ class
	 */
	~ZeroMQ();
};