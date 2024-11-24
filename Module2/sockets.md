# SOCKETS

## INTRO

**SOCKETS:** are communication endpoints that enable network communication between processes (either on the same machine or multiple across multiple machines)

- They act as file descriptors that can be read from and written to
- Sockets are bidirectional communication channels and follow a client-server model

**TYPES:** they come with many options:
1. address fmaily (UNIX, INET, etc.)
2. socket tpye (DGRAM, STREAM, PACKET, RAW)
3. protocol type (TCP, UDP, etc.)


## SOCKETS
Include **headerfile** `<sys/socket.h>` and **headerfile** `<netinet/in.h>`
**note:** returns a file descriptor of the socket on success and -1 on error
**int sockect(int family, int type, int protocol)**

**FAMILY:**: (AF = address family)
AF_UNIX = creates a UNIX SOCKET (a named pipe) 
- Think of it as passing notes between rooms in your house through a tube system 
AF_INET = internet protocol version 4 (IPv4)
- traditional address
AF_INET6 = internet protocal version 6 (IPv6)
- Much more address space available
**TYPES:**
SOCK_DGRAM - a datagram, (a bunch of bytes)
SOCK_STREAM - a connection stream between the client/server (like TCP)
SOCK_RAW - raw sockets (you will fill everything), requires a superuser
**PROTOCOL:**


## NETWORK BYTE ORDER
   
