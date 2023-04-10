#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *ack_message;
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        return EXIT_FAILURE;
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Accept a connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        std::cerr << "Accept failed" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Receive message from client
    read(new_socket, buffer, 1024);
    std::cout << "Message received from client: " << buffer << std::endl;
    
    // Calculate number of characters
    int num_chars = strlen(buffer);
    
    // Create acknowledgement message
    ack_message = new char[30];
    snprintf(ack_message, 30, "Received message of %d characters", num_chars);

    // Send acknowledgement message back to client
    send(new_socket, ack_message, strlen(ack_message), 0);
    std::cout << "Acknowledgement message sent to client: " << ack_message << std::endl;
    
    // Close the connection
    close(new_socket);
    close(server_fd);
    
    return EXIT_SUCCESS;
}