#ifndef SIO_ClientImpl_DEFINED
#define SIO_ClientImpl_DEFINED

#include <string>

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Logger.h"
#include "Poco/Timer.h"
#include "Poco/NotificationCenter.h"
#include "Poco/Thread.h"
#include "Poco/ThreadTarget.h"
#include "Poco/RunnableAdapter.h"
#include "Poco/URI.h"

#include "Poco/JSON/Parser.h"

#include "SIONotificationHandler.h"
#include "SIOEventRegistry.h"
#include "SIOEventTarget.h"
#include "SIOPacket.h"

using Poco::Net::HTTPClientSession;
using Poco::Net::WebSocket;
using Poco::Logger;
using Poco::Timer;
using Poco::TimerCallback;
using Poco::NotificationCenter;
using Poco::Thread;
using Poco::ThreadTarget;


class SIOClientImpl: public Poco::Runnable
{
public:
	bool handshake();
	bool openSocket(); // Opens a WebSocket connection.
	bool init(); // Initializes the client.

	void release(); //Releases resources.
	void addref(); // Manages reference counting for the object.

	static SIOClientImpl* connect(Poco::URI uri); //establish a connection to server by uri
	void disconnect(std::string endpoint); // disconnect from endpoint
	void connectToEndpoint(std::string endpoint); // connect to specific endpoint
	void monitor(); // Monitors the connection status.
	virtual void run(); // The main run loop for the client's thread.
	void heartbeat(Poco::Timer& timer); // Manages the heartbeat mechanism to keep the connection alive.
	bool receive(); // Receives data from the WebSocket.
	void send(std::string endpoint, std::string s); // Sends a string message to a specific endpoint.
	void send(SocketIOPacket *packet); // Sends a SocketIOPacket.
	void emit(std::string endpoint, std::string eventname, std::string args); // Emits an event with string arguments.
  void emit(std::string endpoint, std::string eventname, Poco::JSON::Object::Ptr args); // Emits an event with JSON arguments.

	std::string getUri(); // 

private:


	SIOClientImpl();
	SIOClientImpl(Poco::URI uri);
	~SIOClientImpl(void);
	
	std::string _sid;
	int _heartbeat_timeout;
	int _timeout;
	std::string _host;
	int _port;
	Poco::URI _uri;
	bool _connected;
	SocketIOPacket::SocketIOVersion _version;

	HTTPClientSession *_session;
	WebSocket *_ws;
	Timer *_heartbeatTimer;
	Logger *_logger;
	Thread _thread;

	int _refCount;
	char *_buffer;
	std::size_t _buffer_size;
	
	//SIOEventRegistry* _registry;
	//SIONotificationHandler *_sioHandler;
};

#endif
