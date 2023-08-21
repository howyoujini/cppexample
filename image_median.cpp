//
// Created by hong youjin on 2023/08/22.
//
#include <opencv2/opencv.hpp>

int main() {
    // 이미지 파일을 로드합니다.
    cv::Mat inputImage = cv::imread("/Users/howyoujini/CLionProjects/howyoujini/youjin.jpg", cv::IMREAD_COLOR);

    if (inputImage.empty()) {
        std::cout << "이미지를 로드할 수 없습니다." << std::endl;
        return -1;
    }

    // 미디언 필터를 적용합니다.
    cv::Mat medianFiltered;
    cv::medianBlur(inputImage, medianFiltered, 29);  // 두 번째 인자는 커널 크기

    // 결과 이미지를 표시합니다.
    cv::imshow("Original Youjin", inputImage);
    cv::imshow("Median Filtered Youjin", medianFiltered);

    // 키 입력 대기 후 종료합니다.
    cv::waitKey(0);

    return 0;
}
