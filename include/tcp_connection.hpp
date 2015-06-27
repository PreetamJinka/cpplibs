#pragma once

#include "sockaddr.hpp"

namespace cpl
{
namespace net
{

class TCP_Connection
{
public:
	TCP_Connection()
	{
	}

	TCP_Connection(int fd, SockAddr local_address, SockAddr remote_address)
	: fd(fd), local(local_address), remote(remote_address)
	{
	}

	~TCP_Connection()
	{
	}

	inline int recv(const void* buf, size_t len, int flags)
	{
		auto ret = (int)(::recv(fd, const_cast<void*>(buf), len, flags));
		return ret;
	}

	inline int send(const void* buf, size_t len, int flags)
	{
		auto ret = (int)(::send(fd, const_cast<void*>(buf), len, flags));
		return ret;
	}
private:
	int fd;
	SockAddr local;
	SockAddr remote;
};

} // net
} // cpl
