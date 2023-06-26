#include <ccn.hpp>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

cv::Mat mergeImage(cv::Mat img1, cv::Mat img2)
{
    int rows = (img1.rows > img2.rows) ? img1.rows : img2.rows;
    int cols = img1.cols + img2.cols;
    cv::Mat3b res(rows, cols, cv::Vec3b(0,0,0));
    img1.copyTo(res(cv::Rect(0, 0, img1.cols, img1.rows)));
    img2.copyTo(res(cv::Rect(img1.cols, 0, img2.cols, img2.rows)));
    return res;
}
// save display save-directory input-directory name of image(from input) conv-value CopyLightness conv-progress
int main(int argc, char **argv ) {
    bool save = false;
    bool show = false;
    bool copyLightness = false;
    bool convProgress = false;
    double conValue = 0.1;
    cv::String saveDirectory = INSTALL_PATH + static_cast<cv::String>("/test_output");
    cv::String inputDirectory = INSTALL_PATH + static_cast<cv::String>("/test_input/test_image.jpg");
    const cv::String keys =
            "{help h | | вывести подсказку }"
            "{s | | указать директорию сохранения }"
            "{i | | указать путь к входному изображению }"
            "{S | | сохранить изображение(если не указано, в стандартную [path]/bin/test_output) }"
            "{D | | вывести изображение }"
            "{L | | использовать CopyLightness алгоритм }"
            "{P | | вычислить прогрессию алгоритма (сохраняется и выводится вместе с результатом CCN) }"
            "{v | | указать пороговое значение сходимости изображения }"
    ;
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("CCN v1.0.0");
    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }
    if (parser.has("s")) {
        saveDirectory = parser.get<cv::String>("s");
    }
    if (parser.has("i")) {
        inputDirectory = parser.get<cv::String>("i");
    }
    if (parser.has("S")) {
        save = parser.get<bool>("S");
    }
    if (parser.has("D")) {
        show = parser.get<bool>("D");
    }
    if (parser.has("L")) {
        copyLightness = parser.get<bool>("L");
    }
    if (parser.has("P")) {
        convProgress = parser.get<bool>("P");
    }
    if (parser.has("v")) {
        conValue = parser.get<double>("v");
    }
    if (!parser.check())
    {
        parser.printErrors();
        return 0;
    }
    cv::Mat image = cv::imread(inputDirectory);
    if (image.empty()) {
        std::cout << "Could not read the image." << std::endl;
        return 1;
    }
    cv::Mat diffprogression;
    if (convProgress) {
        std::vector<cv::Mat> HMC = ccn::ComprColorImageNormDiff(image.clone(),conValue);
        diffprogression = HMC[0];
        for (int i = 1; i < HMC.size(); i++) {
            HMC[i].convertTo(HMC[i], CV_8UC3, 128);
            diffprogression = mergeImage(diffprogression, HMC[i]);
        }
        if (save) {
            cv::imwrite(saveDirectory + "/diff.jpg",
                        mergeImage(image,
                                   diffprogression));
            std::cout << HMC.size();
        }
        std::cout << "Количество итераций до схождения: " << HMC.size() << std::endl;
    }
    cv::Mat result = ccn::ComprColorImageNorm(image.clone(), conValue, copyLightness);
    if (save) {
        cv::imwrite(saveDirectory + "/normalized_image.jpg",
                    mergeImage(image,result));
    }
    if (show) {
        // Display the image.
        namedWindow("CCN result", cv::WINDOW_AUTOSIZE);
        imshow("CCN result", mergeImage(image,result));
        if (convProgress) {
            namedWindow("CCN progression", cv::WINDOW_AUTOSIZE);
            imshow("CCN progression", diffprogression);
        }
        // Wait for a keystroke in the window.
        int k = cv::waitKey(0);
        // Close the window.
        cv::destroyAllWindows();
    }
    return 0;

}



