#include <iostream>
#include <fstream>
#include <openssl/sha.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

void computeSHA256(const std::string& data, unsigned char hash[SHA256_DIGEST_LENGTH]) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.length());
    SHA256_Final(hash, &sha256);
}

int main() {
    setlocale(LC_ALL, "");
    std::string imagePath = "C:\lab8\8.3\image1.jpg";
    cv::Mat image = cv::imread(imagePath);
    
    if (image.empty()) {
        std::cerr << "Ошибка при загрузке изображения" << std::endl;
        return 1;
    }
    
    std::vector<uchar> imageData;
    cv::imencode(".jpg", image, imageData);
    std::string imageDataStr(imageData.begin(), imageData.end()); 
    unsigned char prehash[SHA256_DIGEST_LENGTH];
    computeSHA256(imageDataStr, prehash);
    image.at<cv::Vec3b>(10, 10)[0] = 255;
    cv::imencode(".jpg", image, imageData);
    imageDataStr = std::string(imageData.begin(), imageData.end());
    unsigned char posthash[SHA256_DIGEST_LENGTH];
    computeSHA256(imageDataStr, posthash);
    bool hashesMatch = true;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        if (prehash[i] != posthash[i]) {
            hashesMatch = false;
            break;
        }
    }
    std::cout << "Предварительный хэш: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        printf("%02x", prehash[i]);
    }
    std::cout << std::endl;
    std::cout << "Последующая обработка: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        printf("%02x", posthash[i]);
    }
    std::cout << std::endl;
    std::ofstream outFile("hashsum.txt");
    if (outFile.is_open()) {
        outFile << "Предварительный хэш: ";
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            outFile << std::hex << static_cast<int>(prehash[i]);
        }
        outFile << std::endl;
        outFile << "Последующая обработка: ";
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            outFile << std::hex << static_cast<int>(posthash[i]);
        }
        outFile << std::endl;
        outFile << "Хэши совпадают: " << (hashesMatch ? "true" : "false") << std::endl;
        outFile.close();
    } else {
        std::cerr << "Ошибка при открытии выходного файла" << std::endl;
    }
    return 0;
}