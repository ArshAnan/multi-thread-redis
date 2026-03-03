#include <iostream>
#include <sys/socket.h>

// Making sure the port is listening to the client
void listenToClient(int port) {
    // Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Failed to create a socket" << "\n";
        exit(1);
    }
}

void setupSocket(int server_fd, int port) {
    // Bind the socket to the port

}

int main() {
    listenToClient(6379);
    return 0;
}