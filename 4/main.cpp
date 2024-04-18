#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui.hpp>
 
void tv_60(cv::Mat img) {
    // Создаем окно для отображения изображения
    cv::namedWindow("image");
    // Инициализация переменных для ползунков
    int slider = 0;
    int slider2 = 0;
    // Создаем ползунки для настройки параметров эффекта
    cv::createTrackbar("val", "image", &slider, 255, nullptr);
    cv::createTrackbar("threshold", "image", &slider2, 100, nullptr);
    // цикл для обработки изображения
    while (true) {
        // Получаем высоту и ширину изображения
        int height = img.size().height;
        int width = img.size().width;
        // Создаем монохромное изображение для обработки
        cv::Mat gray;
        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
        // Вычисляем порог и величину эффекта
        float thresh = slider2 / 100.0 * 255; // Преобразование в диапазон [0, 255]
        float val = slider;
        // Цикл обработки каждого пикселя изображения
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                // Применяем эффект изменения интенсивности пикселя с вероятностью, основанной на пороге
                if (rand() % 100 <= thresh) {
                    if (rand() % 2 == 0) {
                        gray.at<uchar>(i, j) = std::min(static_cast<int>(gray.at<uchar>(i, j)) + rand() % static_cast<int>(val + 1), 255);
                    } else {
                        gray.at<uchar>(i, j) = std::max(static_cast<int>(gray.at<uchar>(i, j)) - rand() % static_cast<int>(val + 1), 0);
                    }
                }
            }
        }
        // Отображаем оригинальное и обработанное изображения
        cv::imshow("original", img);
        cv::imshow("image", gray);
        // Выход из цикла по нажатию клавиши 'q'
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }
    // Закрываем все окна
    cv::destroyAllWindows();
}
/// @brief функция, которая редактирует данное изображение в изображение с эффектом телевизора 60ых
/// @return вывод оригинального и обработанного изображения
int main() {
    cv::Mat image = cv::imread("C:/tt/AAAR0687.jpg"); // Загрузка изображения с диска
    if (image.empty()) {
        std::cerr << "Could not read the image." << std::endl;
        return -1;
    }
    tv_60(image); // Вызов функции для обработки изображения
    return 0;
}