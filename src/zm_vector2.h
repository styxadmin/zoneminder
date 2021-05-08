//
// ZoneMinder Coordinate Class Interface, $Date$, $Revision$
// Copyright (C) 2001-2008 Philip Coombes
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
// 

#ifndef ZM_VECTOR2_H
#define ZM_VECTOR2_H

#include "zm_define.h"

//
// Class used for storing an x,y pair, i.e. a coordinate/vector
//
class Vector2 {
 public:
  Vector2() : x_(0), y_(0) {}
  Vector2(int32 x, int32 y) : x_(x), y_(y) {}

  static Vector2 Range(const Vector2 &coord1, const Vector2 &coord2) {
    Vector2 result((coord1.x_ - coord2.x_) + 1, (coord1.y_ - coord2.y_) + 1);
    return result;
  }

  bool operator==(const Vector2 &rhs) const { return (x_ == rhs.x_ && y_ == rhs.y_); }
  bool operator!=(const Vector2 &rhs) const { return (x_ != rhs.x_ || y_ != rhs.y_); }

  // These operators are not idiomatic. If lexicographic comparison is needed, it should be implemented separately.
  bool operator>(const Vector2 &rhs) const = delete;
  bool operator>=(const Vector2 &rhs) const = delete;
  bool operator<(const Vector2 &rhs) const = delete;
  bool operator<=(const Vector2 &rhs) const = delete;

  Vector2 operator+(const Vector2 &rhs) const {
    return {x_ + rhs.x_, y_ + rhs.y_};
  }
  Vector2 operator-(const Vector2 &rhs) const {
    return {x_ - rhs.x_, y_ - rhs.y_};
  }

  Vector2 &operator+=(const Vector2 &rhs) {
    x_ += rhs.x_;
    y_ += rhs.y_;
    return *this;
  }
  Vector2 &operator-=(const Vector2 &rhs) {
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    return *this;
  }

 public:
  int32 x_;
  int32 y_;
};

#endif // ZM_VECTOR2_H
