#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//DES algorithm implementation: 16 round encryption
// Array to store the initial permutation
string roundKeys[16];


// 4 bit binary to decimal
string convertDecToBin(int dec){
    string bin = "";
    while(dec > 0){
        bin += to_string(dec%2);
        dec /= 2;
    }
    while(bin.length() < 4){
        bin += "0";
    }
    return bin;
}

int convertBinToDec(string bin){
    int dec = 0;
    int count = 0;
    int len = bin.length();
    for(int i = len - 1; i >= 0; i--){
        if(bin[i] == '1'){
            dec += pow(2, count);
        }
        count++;
    } 
    return dec;
}

string ASCIItoBin(string str){
    string bin = "";
    for ( char &c : str){
        int val = (int) c;
        string charBin = "";
        for ( int i = 0; i < 8; i++ ){
            charBin = ((val%2 == 0) ? "0" : "1") + charBin;
            val/=2; 
        }
        bin += charBin;
    }
    return bin;
}

string BintoASCII(string bin){
    string str = "";
    int len = bin.length();
    for ( int i = 0; i < len; i+=8){
        string bytes = bin.substr(i, 8);
        int val = convertBinToDec(bytes);
        str += (char)val;
    }
    return str;
}

// xor function
string XOR (string str1, string str2){
    string res = "";
    int len = str2.length();
    for (int i = 0; i < len; i++){
        (str1[i] == str2[i]) ? res += "0" : res += "1";
    }
    return res;
}

// Circular left shifts for each round by 1
string shiftToLeft (string key){
    string shifted = "";
    for(int i = 1; i < key.length(); i++)
        shifted += key[i];
    
    shifted += key[0];
    return shifted;
}

// Circular left shifts for each round by 2
string shiftToLeft2( string key){
    string shifted = "";
    for(int i=0; i < 2; i++){
        for (int j = 1; j < 28; j++)
        {
            shifted += key[j];
        }
        shifted += key[0];
        key = shifted;
        shifted = "";
    }
    return key;
}

void generateKeys(string key){
    // PC 1 table
    int pc1[56] = {
        57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4
    };
    // PC 2 table
    int pc2[48] = {
        14, 17, 11, 24, 1, 5, 3, 28, 
        15, 6, 21, 10, 23, 19, 12, 4, 
        26, 8, 16, 7, 27, 20, 13, 2, 
        41, 52, 31, 37, 47, 55, 30, 40, 
        51, 45, 33, 48, 44, 49, 39, 56,
        34, 53, 46, 42, 50, 36, 29, 32
    };

    string permKey = "";
    for (int i = 0; i < 56; i++)
        permKey += key[pc1[i]-1];
    
    string left = permKey.substr(0, 28);
    string right = permKey.substr(28, 28);

    for (int i = 0; i < 16; i++){
        if( i == 0 || i == 1 || i == 8 || i == 15){
            left = shiftToLeft(left);
            right = shiftToLeft(right);
        }else{
            left = shiftToLeft2(left);
            right = shiftToLeft2(right);
        }
        string combinedKey = left + right;
        string roundKey = "";

        for (int j = 0; j < 48; j++)
            roundKey += combinedKey[pc2[j]-1];
        roundKeys[i] = roundKey;
        // printf("Key %d: %s\n", i+1, roundKeys[i].c_str());
    }
    
}

// DES
string DES (string pt_block){
    int IP[64] = {
        58,50,42,34,26,18,10,2, 
        60,52,44,36,28,20,12,4, 
        62,54,46,38,30,22,14,6, 
        64,56,48,40,32,24,16,8, 
        57,49,41,33,25,17,9,1, 
        59,51,43,35,27,19,11,3, 
        61,53,45,37,29,21,13,5, 
        63,55,47,39,31,23,15,7 
    };

    int ExP[48] = {
        32,1,2,3,4,5,4,5, 
        6,7,8,9,8,9,10,11, 
        12,13,12,13,14,15,16,17, 
        16,17,18,19,20,21,20,21, 
        22,23,24,25,24,25,26,27, 
        28,29,28,29,30,31,32,1 
    };

    int S_box[8][4][16] = {
        {
            14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7, 
            0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8, 
            4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0, 
            15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 
        },
        {
            15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10, 
            3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5, 
            0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15, 
            13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 
        },
        {
            10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8, 
            13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1, 
            13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7, 
            1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
        },
        {
            7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15, 
            13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9, 
            10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4, 
            3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 
        },
        {
            2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9, 
            14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6, 
            4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14, 
            11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 
        },
        {
            12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11, 
            10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8, 
            9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6, 
            4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 
        },
        {
            4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1, 
            13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6, 
            1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2, 
            6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 
        },
        {
            13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7, 
            1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2, 
            7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8, 
            2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 
        }
    };

    int P[32] = {
        16, 7, 20, 21, 29, 12, 28, 17, 
        1, 15, 23, 26, 5, 18, 31, 10, 
        2, 8, 24, 14, 32, 27, 3, 9, 
        19, 13, 30, 6, 22, 11, 4, 25
    };

    int inverse[64] = {
        40,8,48,16,56,24,64,32, 
        39,7,47,15,55,23,63,31, 
        38,6,46,14,54,22,62,30, 
        37,5,45,13,53,21,61,29, 
        36,4,44,12,52,20,60,28, 
        35,3,43,11,51,19,59,27, 
        34,2,42,10,50,18,58,26, 
        33,1,41,9,49,17,57,25 
    };

    string permuted = "";
    for( int i = 0; i < 64; i++ ){
        permuted += pt_block[IP[i]-1];
    }

    string left = permuted.substr(0, 32);
    string right = permuted.substr(32, 32);

    for ( int i = 0; i < 16; i++ ){
        // Expand R to 48-bits
        string right_exp = "";
        for (int i = 0; i < 48; i++)
            right_exp += right[ExP[i] - 1];
        
        // Adds to subkey using XOR
        string xorted = XOR(roundKeys[i], right_exp);   
        string res = "";
        
        // Passes through 8 S-boxes to get 32-bit result
        for ( int i = 0; i < 8; i++ ){
            string row1 = xorted.substr(i*6, 1) + xorted.substr(i*6 + 5, 1);
            int row = convertBinToDec(row1);
            string col1 = xorted.substr(i*6 + 1, 1) + xorted.substr(i*6 + 2, 1) + xorted.substr(i*6 + 3, 1) + xorted.substr(i*6 + 4, 1);
            int col = convertBinToDec(col1);
            int val = S_box[i][row][col];
            res += convertDecToBin(val);
        }

        // Permutation to get 32 bit left half
        string permuted2 = "";
        for ( int i = 0; i < 32; i++ )
            permuted2 += res[P[i] - 1];
        
        xorted = XOR(permuted2, left);
        left = xorted;

        if(i < 15){
            string temp = right;
            right = xorted;
            left = temp;
        }
    }

    string combineText = left + right;
    string cihpertext = "";

    for ( int i = 0; i < 64; i++ )
        cihpertext += combineText[inverse[i]-1];

    return cihpertext;
}

string addPadding(string binText) {
    int len = binText.length();
    int remainder = len%64;
    int paddingNeeds = 64 - remainder;

    if(remainder == 0 && len > 0)
        paddingNeeds = 64;
    else if(len == 0)
        paddingNeeds = 64;
    
    string padding = "1";
    for ( int i = 0; i < paddingNeeds-1; i++)
        padding += "0";

    return binText + padding;
}

string removePadding(string binText){
    int last = binText.find_last_of('1');
    if(last != string::npos)
        return binText.substr(0, last);
    return binText;
}

string decrypt(string ct, string key){
    int i = 15, j = 0;
    while(i > j){
        string temp = roundKeys[i];
        roundKeys[i] = roundKeys[j];
        roundKeys[j] = temp;
        i--;
        j++;
    }
    string decryptedPt = "";
    int total_blocks = ct.length() / 64;
    
    for (int i = 0; i < total_blocks; i++){
        string ct_block = ct.substr(i*64, 64);
        decryptedPt += DES(ct_block);
    }

    string removedPadding = removePadding(decryptedPt);
    string finalText = BintoASCII(removedPadding);
    return finalText;
}

int main(){
    string key = "1010101010111011000010010001100000100111001101101100110011011101";
    string pt;
    cout << "Enter Plain Text: ";
    getline(cin, pt);
    
    generateKeys(key); 
    string binary_pt = ASCIItoBin(pt);
    string padded_pt = addPadding(binary_pt);

    cout << "Plaintext: " << pt << endl;
    cout << "Padded Binary Length: " << padded_pt.length() << " bits" << endl;

    string full_ct = "";
    int total_blocks = padded_pt.length() / 64;
    string apt = pt;

    for (int i = 0; i < total_blocks; i++) {
        pt = padded_pt.substr(i * 64, 64); 
        string block_ct = DES(pt); 
        full_ct += block_ct;
    }
    cout << "Ciphertext (in binary): " << full_ct << endl;

    // Decryption
    cout << "Apt: " << apt << endl;
    string decrypted = decrypt(full_ct, key);
    cout << "Decrypted text: " << decrypted << endl;

    if(decrypted == apt)
        cout << "Decryption successful!" << endl;
    else
        cout << "Decryption failed!" << endl;
    return 0;
}