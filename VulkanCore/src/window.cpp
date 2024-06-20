#include "window.h"

#include <GLFW/glfw3.h>

namespace
{
  static void framebuffer_resize_callback(GLFWwindow* window, int width, int height)
  {
    auto w= reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
    w->setFrameBufferResized(true);
    int newWidth = 0;
    int newHeight = 0;
    glfwGetFramebufferSize(window, &newWidth, &newHeight);
    w->setWidth(newWidth);
    w->setHeight(newHeight);
  }
}

Window::Window(std::string_view title, int w, int h)
  : width_(std::move(w))
  , height_(std::move(h))
{
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  window_ = glfwCreateWindow(width_, height_, title.data(), nullptr, nullptr);
  glfwSetWindowUserPointer(window_, this);
  glfwSetFramebufferSizeCallback(window_, framebuffer_resize_callback);
}

Window::~Window()
{
  glfwDestroyWindow(window_);
}

void Window::setFrameBufferResized(bool resized)
{
  framebuffer_resized = resized;
}

bool Window::frameBufferResizied() const
{
  return framebuffer_resized;
}

void Window::setWidth(int w)
{
  width_ = w;
}

int Window::width() const
{
  return width_;
}

void Window::setHeight(int h)
{
  height_ = h;
}

int Window::height() const
{
  return height_;
}
