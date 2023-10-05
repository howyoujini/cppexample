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

    // 가우시안 블러 필터를 적용합니다.
    cv::Mat blurredImage;
    // 커널의 사이즈는, 양수이고 홀수이어야 합니다.
    // Gaussian 필터는 이미지를 부드럽게 만들거나 노이즈를 줄이는 데 사용되는 필터 중 하나입니다.
    // 필터를 적용하는 동안 커널의 크기가 홀수인 경우, 커널 중심이 하나의 픽셀로 놓이게 됩니다.
    // 이렇게 하면 이미지의 픽셀들에 대해 대칭적으로 필터가 적용되고, 이미지의 변형을 최소화할 수 있습니다.
    // 반면에, 커널 크기가 짝수인 경우, 중심 픽셀이 정확하게 중앙에 위치하지 않고 픽셀 사이에 놓이게 됩니다. 이로 인해 필터링 결과의 대칭성이 깨지고, 이미지가 더 왜곡될 수 있습니다.
    // "커널"은 영어로 "kernel"입니다.
    // 필터링 작업에서 "kernel"은 이미지의 각 픽셀에 적용되는 작은 마스크 또는 행렬을 나타냅니다.
    // 이러한 커널은 필터링 프로세스에서 이미지의 픽셀들을 조작하고 변형시키는 데 사용됩니다.
    // Gaussian 블러와 같은 필터링 작업에서 커널은 이미지에 적용되는 블러 또는 필터의 형태와 특성을 결정합니다.
    cv::Size kernel_size = cv::Size(101, 11);
    cv::GaussianBlur(inputImage, blurredImage, kernel_size, 0);

    // 결과 이미지를 표시합니다.
    cv::imshow("Original Youjin", inputImage);
    cv::imshow("Blurred Youjin", blurredImage);

    // 키 입력 대기 후 종료합니다.
    cv::waitKey(0);

    return 0;
}
