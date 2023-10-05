//
// Created by hong youjin on 2023/08/22.
//
#include <opencv2/opencv.hpp>

/// Sobel 필터는 이미지의 경계를 감지하는 데 사용되며, 엣지 검출에 널리 활용됩니다.
int main() {
    // 이미지 파일을 로드합니다.
    cv::Mat inputImage = cv::imread("/Users/howyoujini/CLionProjects/howyoujini/youjin.jpg", cv::IMREAD_GRAYSCALE);

    if (inputImage.empty()) {
        std::cout << "이미지를 로드할 수 없습니다." << std::endl;
        return -1;
    }

    // Sobel 필터를 적용합니다.
    cv::Mat gradientX, gradientY;
    cv::Mat absGradientX, absGradientY;
    cv::Mat gradientImage;

    // cv::Sobel 함수를 사용하여 Sobel 필터를 적용하고, X 및 Y 방향의 경계 감지 결과를 조합하여 최종 경계 이미지를 생성합니다.
    cv::Sobel(inputImage, gradientX, CV_16S, 1, 0);
    cv::convertScaleAbs(gradientX, absGradientX);

    cv::Sobel(inputImage, gradientY, CV_16S, 0, 1);
    cv::convertScaleAbs(gradientY, absGradientY);

    cv::addWeighted(absGradientX, 0.5, absGradientY, 0.5, 0, gradientImage);

    // 결과 이미지를 표시합니다.
    cv::imshow("Original Image", inputImage);
    cv::imshow("Sobel Filtered Image", gradientImage);

    // 키 입력 대기 후 종료합니다.
    cv::waitKey(0);

    return 0;
}
