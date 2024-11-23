# SOCKETS

## INTRO

**==SOCKETS:==** are communication endpoints that enable network communication between processes (either on the same machine or multiple across multiple machines)

- They act as file descriptors that can be read from and written to
- Sockets are bidirectional communication channels and follow a client-server model

**TYPES:** they come with many options:
1. address fmaily (UNIX, INET, etc.)
2. socket tpye (DGRAM, STREAM, PACKET, RAW)
3. protocol type (TCP, UDP, etc.)


## SOCKETS
Include **headerfile** ==<sys/socket.h>== and 
