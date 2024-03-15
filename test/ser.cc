#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#pragma comment(lib, "Ws2_32.lib")

const int PORT = 12345; // 服务器监听的端口号
const int BUFFER_SIZE = 1024; // 接收缓冲区大小

SOCKET ListenSocket = INVALID_SOCKET;

void InitializeWinsock() {//
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cerr << "WSAStartup failed with error: " << result << std::endl;
        exit(1);
    }
}

SOCKET CreateServerSocket() {
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Could not create socket: " << WSAGetLastError() << std::endl;
        return INVALID_SOCKET;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (SOCKADDR *) &serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed with error: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        return INVALID_SOCKET;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed with error: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        return INVALID_SOCKET;
    }

    return serverSocket;
}

void AcceptClients() {
    char buffer[BUFFER_SIZE];
    while (true) {
        SOCKET clientSocket = accept(ListenSocket, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Accept failed with error: " << WSAGetLastError() << std::endl;
            continue;
        }

        std::cout << "Client connected." << std::endl;

        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived > 0) {
            std::cout << "Received from client: " << buffer << std::endl;
        } else {
            std::cerr << "Receive failed with error: " << WSAGetLastError() << std::endl;
        }

        closesocket(clientSocket);
    }
}

void CheckForClients() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // 每2秒检查一次

        // 这里可以添加代码来检查是否有新的客户端连接
        // 例如，可以设置一个标志变量，当接收到连接请求时将其设置为true
        // 然后在这里检查这个标志变量，如果为true，则调用AcceptClients()函数处理连接

        // 示例中直接调用AcceptClients处理连接请求
        AcceptClients();
    }
}

int main() {
    InitializeWinsock();

    ListenSocket = CreateServerSocket();
    if (ListenSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create server socket." << std::endl;
        return 1;
    }

    std::thread checkForClientsThread(CheckForClients);
    checkForClientsThread.detach(); // 分离线程，让它在后台运行

    // 主线程可以执行其他任务或保持运行状态以允许服务器继续运行
    while (true) {
        // 可以添加其他逻辑，比如处理关闭信号、日志记录等
        std::this_thread::sleep_for(std::chrono::seconds(2)); // 休眠1秒
    }

    // 清理资源
    closesocket(ListenSocket);
    WSACleanup();

    return 0;
}