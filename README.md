# Minitalk

Minitalk is a small client-server communication program that uses signals to send and receive messages between two processes.

## Installation

To install Minitalk, simply clone the repository and compile the sources using the provided Makefile:

```sh
git clone https://github.com/EthanDelage/42_Minitalk.git minitalk
cd minitalk
make
```

This will generate two executable files: `server` and `client`.

## Usage

To start the server, run the following command:

```sh
./server
```

This will display the process ID of the server, which you will need to provide to the client in order to establish a connection.

To send a message from the client to the server, use the following command:

```sh
./client [server_pid] [message]
```

Replace `[server_pid]` with the process ID of the server, and `[message]` with the message you want to send.

The server will receive the message and display it in its terminal.

## Implementation

Minitalk is implemented using signal handling in C. The server process waits for incoming signals, while the client sends signals to the server to send a message. The message is transmitted as a series of 0 and 1 bits, and the server reconstructs the message using bitwise operations.
