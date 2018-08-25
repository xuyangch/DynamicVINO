/**
 * @brief A header file with declaration for BaseInput Class
 * @file base_input.h
 */
#ifndef OPENVINO_PIPELINE_LIB_BASE_INPUT_H
#define OPENVINO_PIPELINE_LIB_BASE_INPUT_H

#include <opencv2/opencv.hpp>

/**
 * @class BaseInputDevice
 * @brief This class is an interface for three kinds of
 * input devices: realsense camera, standard camera and video
 */
namespace Input {
class BaseInputDevice {
 public:
  BaseInputDevice() = default;
  virtual ~BaseInputDevice() = default;
  /**
   * @brief Initialize the input device,
   * for cameras, it will turn the camera on and get ready to read frames,
   * for videos, it will open a video file.
   * @return Whether the input device is successfully turned on.
   */
  virtual bool initialize() = 0;
  /**
   * @brief (Only work for standard camera)
   * Initialize camera by its index when multiple standard camera is connected.
   * @return Whether the input device is successfully turned on.
   */
  virtual bool initialize(int) = 0;
  /**
   * @brief Initialize the input device with given width and height.
   * @return Whether the input device is successfully turned on.
   */
  virtual bool initialize(size_t width, size_t height) = 0;
  /**
   * @brief Read next frame, and give the value to argument frame.
   * @return Whether the next frame is successfully read.
   */
  virtual bool read(cv::Mat *frame) = 0;
  virtual void config() = 0; //< TODO
  /**
   * @brief Get the width of the frame read from input device.
   * @return The width of the frame read from input device.
   */
  inline size_t getWidth() { return width_; }
  /**
   * @brief Set the width of the frame read from input device.
   * @param[in] width Width to be set for the frame.
   */
  inline void setWidth(size_t width) { width_ = width; }
  /**
   * @brief Get the height of the frame read from input device.
   * @return The height of the frame read from input device.
   */
  inline size_t getHeight() { return height_; }
  /**
   * @brief Set the height of the frame read from input device.
   * @param[in] width Width to be set for the frame.
   */
  inline void setHeight(size_t height) { height_ = height; }
  /**
   * @brief Check whether the input device is successfully initiated.
   * @return Whether the input device is successfully initiated.
   */
  inline bool isInit() { return is_init_; }
  /**
   * @brief Set the initialization state for input device.
   * @param[in] is_init The initialization state to be set.
   */
  inline void setInitStatus(bool is_init) { is_init_ = is_init; }
 private:
  size_t width_ = 0;
  size_t height_ = 0;
  bool is_init_ = false;
};
}
#endif //OPENVINO_PIPELINE_LIB_BASE_INPUT_H
