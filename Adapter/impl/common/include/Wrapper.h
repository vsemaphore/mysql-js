/*
 Copyright (c) 2012, Oracle and/or its affiliates. All rights
 reserved.
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; version 2 of
 the License.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 02110-1301  USA
 */


#include "node.h"

using namespace v8;

template <class T> class Wrapper : public node::ObjectWrap {
public:
  T *object;
  
  Wrapper<T>(T * obj) : node::ObjectWrap() , object(obj)                    {};
   Handle<Object> Wrap( Handle<Object> h)  {
    node::ObjectWrap::Wrap(h); 
    return h; 
  }
  
  static Wrapper <T> * Unwrap( Handle<Object> h) {
    return node::ObjectWrap::Unwrap<Wrapper <T> >(h);
  }
};
