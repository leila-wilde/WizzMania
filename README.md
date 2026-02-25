# WizzMania

An MSN messenger-style chat application built with C++, Qt6, and TCP/IP networking.

## overview

WizzMania is a real-time chat application featuring a centralized server handling multiple client connections. The project demonstrates networking fundamentals, GUI development with Qt, and multi-threaded application architecture.

## TCP/IP networking

- TCP (Transmission Control Protocol) ensures reliable, ordered delivery of data. It creates a persistent connection between client and server and guarantees all messages arrive intact and in order.
- IP (Internet Protocol) handles routing data packets across networks.

### how it works:

1. client connects to server via a socket
2. messages sent are guaranteed delivery over that connection
3. server can handle multiple simultaneous client connections
4. connection persists until either side closes it

## project structure

```
WizzMania/
├── CMakeLists.txt
├── server/
│   ├── src/
│   │   ├── main.cpp
│   │   ├── ServerManager.cpp
│   │   └── ServerManager.h
│   │   ├── mainwindow.cpp
│   │   └── mainwindow.h
├── client/
│   ├── src/
│   │   ├── main.cpp
│   │   ├── client.cpp
│   │   ├── client.h
│   │   ├── mainwindow.cpp
│   │   └── mainwindow.h
│   ├── ui/
│   │   └── mainwindow.ui
│   └── resources/
│       └── resources.qrc
├── docs/
└── README.md
```

## features

- **real-time messaging** - instant message delivery via TCP/IP protocol
- **multi-client support** - server handles concurrent client connections
- **Qt GUI** - cross-platform user interface (Qt 6)
- **integrated games** - built-in games accessible to all chat participants

## requirements

### build requirements
- **C++17** or later
- **Qt 6**
- **CMake 3.16+** (or Qt Creator qmake)
- **platform**: Linux, macOS, or Windows

### system requirements
- minimum 100MB disk space
- RAM: 512MB+

## building

### prerequisites installation

**ubuntu/debian:**
```bash
sudo apt-get install qt6-base-dev build-essential cmake
```

**macOS:**
```bash
brew install qt@6
```

**windows:**
- download Qt from [qt.io](https://www.qt.io/download)
- install with Qt Creator

### build steps

```bash
mkdir build
cd build
cmake ..
make
```

or using Qt Creator:
1. open `CMakeLists.txt` or `.pro` file in Qt Creator
2. configure the project
3. build

## running

### start the server
```bash
./build/server
```
server listens on `localhost:5000` (default)

### start client(s)
```bash
./build/client
```
connect to server address and port

## project status

- [x] project structure
- [ ] server implementation
- [ ] client implementation
- [ ] Qt UI
- [ ] tests

## contributing

**team members...**

## license

see LICENSE file

