#include <iostream>
#include <bitset>

using namespace std;

bool isEvenParity(const bitset<7>& binaryData) {
    int countOnes = binaryData.count();
    return (countOnes % 2 == 0);
}

bitset<8> addParityBit(const bitset<7>& binaryData) {
    bitset<8> dataWithParity(binaryData.to_string() + "0");
    // Calculate parity bit and append it to the data
    bool parityBit = isEvenParity(binaryData);
    dataWithParity.set(0, !parityBit);
    return dataWithParity;
}

bool checkParity(const bitset<8>& binaryData) {
    // Only consider the first 7 bits for parity check
    bitset<7> dataWithoutParity(binaryData.to_string().substr(1, 7));
    return !isEvenParity(dataWithoutParity);
}

int main() {
    bitset<7> sendData;
    bitset<8> receivedData;

    // Sender
    cout << "Sender:\n";
    cout << "Enter 7-bit binary data to be sent (e.g., 1101101): ";
    cin >> sendData;

    // Add parity bit
    bitset<8> sendDataWithParity = addParityBit(sendData);
    cout << "Data with parity bit: " << sendDataWithParity << "\n\n";

    // Receiver
    cout << "Receiver:\n";
    cout << "Enter received 8-bit binary data (including parity bit): ";
    cin >> receivedData;

    // Check parity
    if (checkParity(receivedData)) {
        cout << "Parity check passed. Data is correct.\n";
        cout << "Received data without parity bit: " << receivedData << "\n";
    } else {
        cout << "Parity check failed. Data may be corrupted.\n";
    }

    return 0;
}

