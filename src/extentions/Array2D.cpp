#include <Arduino.h>

template <typename T>
class Array2D
{
private:
  T *_data;
  int _width;
  int _height;

public:
  Array2D(int width, int height) : _width(width), _height(height)
  {
    _data = new T[width * height];
  }

  ~Array2D()
  {
    delete[] _data;
  }

  int Width() const
  {
    return _width;
  }

  int Height() const
  {
    return _height;
  }

  T &operator()(int x, int y)
  {
    return _data[x * _height + y];
  }

  const T &operator()(int x, int y) const
  {
    return _data[x * _height + y];
  }

  void ToString()
  {
    for (int i = 0; i < _width; i++)
    {
      for (int j = 0; j < _height; j++)
      {
        Serial.print((*this)(i, j));
        Serial.print(',');
      }
      Serial.println();
    }
  }
};
