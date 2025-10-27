#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

using namespace std;

#define PORT 3000
#define IP "127.0.0.1"

int main()
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    cout << "client socket: " << clientSocket << endl;
    if (clientSocket < 0)
    {
        perror("Socket creation failed");
        return 1;
    }
    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);

    if (inet_pton(AF_INET, IP, &serverAddress.sin_addr) <= 0)
    {
        perror("Invalid address");
        close(clientSocket);
        return 1;
    }
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        perror("Connection Failed");
        close(clientSocket);
        return 1;
    }
    cout << "Connected to server at " << IP << ":" << PORT << endl;
    char keyBuffer[32] = {0};
    int keyBytes = recv(clientSocket, keyBuffer, 32, 0);

    if (keyBytes <= 0)
    {
        cout << "Failed to receive key or server disconnected." << endl;
        close(clientSocket);
        return 1;
    }

    string keyHex(keyBuffer);
    cout << "Received key from server: " << keyHex << endl;
    cout << "--- Ready to send messages ---" << endl;

    string dataToSend;
    string userInput;
    while (true)
    {
        cout << "=====================================" << endl;
        cout << "Select menu:" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Your choices (1, 2, 3) default: 1 " << endl;
        getline(cin, userInput);
        if (userInput.empty() || userInput == "1")
        {
            cout << "Enter message (or 'exit' to quit): ";
            getline(cin, dataToSend);
            cout << "data to send: " << dataToSend << endl;
            if (dataToSend.empty()){
                cout << "Please enter an ASCII text" << endl;
                continue;
            }
            if (dataToSend == "exit")
                break;
            string msg = "encrypt " + dataToSend;
            cout << "message on client: " << msg << endl;

            if (send(clientSocket, msg.c_str(), msg.length(), 0) < 0)
            {
                perror("Send failed");
                break;
            }

            char ctBuffer[2048] = {0};
            int ctBytes = recv(clientSocket, ctBuffer, 2048, 0);

            if (ctBytes <= 0)
            {
                cout << "Server disconnected." << endl;
                break;
            }

            string ctHex(ctBuffer);
            cout << "Server response (Hex): " << ctHex << endl;
        }
        else if (userInput == "2")
        {
            string key;
            cout << "-- Type text then enter to continue or exit to cancel --" << endl;
            cout << "Enter hex input: ";
            getline(cin, dataToSend);

            bool isHex = true;
            for (char c : dataToSend)
            {
                if (!isxdigit(c))
                {
                    isHex = false;
                    break;
                }
            }
            if (!isHex)
            {
                cout << "Error: Input must be hexadecimal characters (0-9, A-F)." << endl;
                continue;
            }

            if (dataToSend.empty()){
                cout << "Input cannot be empty";
                continue;
            }
            if (dataToSend == "exit")
                break;
            string msg = "decrypt " + dataToSend;

            if (send(clientSocket, msg.c_str(), msg.length(), 0) < 0)
            {
                perror("Send failed");
                break;
            }
            char ctBuffer[2048] = {0};
            int ctBytes = recv(clientSocket, ctBuffer, 2048, 0);

            if (ctBytes <= 0)
            {
                cout << "Server disconnected." << endl;
                break;
            }

            string decrypted(ctBuffer);
            cout << "Server response: " << decrypted << endl;
        }
        else if (userInput == "3")
        {
            cout << "Thank you! See you later!" << endl;
            break;
        }
        else
        {
            cout << "Invalid input! Please try again" << endl;
        }
        cout << "=====================================" << endl;
    }

    close(clientSocket);
    cout << "Connection closed." << endl;
    return 0;
}