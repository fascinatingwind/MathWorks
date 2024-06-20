#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <string>

struct GLFWwindow;

class Window
{
  GLFWwindow* window_ = nullptr;
  int width_ = 0;
  int height_ = 0;
  bool framebuffer_resized = false;

public:
  explicit Window(std::string_view title, int w, int h);
  virtual ~Window();

  void setFrameBufferResized(bool resized);
  bool frameBufferResizied() const;

  void setWidth(int w);
  int width() const;

  void setHeight(int h);
  int height() const;
};
#endif