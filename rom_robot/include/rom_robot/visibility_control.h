// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROM_ROBOT__VISIBILITY_CONTROL_H_
#define ROM_ROBOT__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROM_ROBOT_EXPORT __attribute__ ((dllexport))
    #define ROM_ROBOT_IMPORT __attribute__ ((dllimport))
  #else
    #define ROM_ROBOT_EXPORT __declspec(dllexport)
    #define ROM_ROBOT_IMPORT __declspec(dllimport)
  #endif
  #ifdef ROM_ROBOT_BUILDING_DLL
    #define ROM_ROBOT_PUBLIC ROM_ROBOT_EXPORT
  #else
    #define ROM_ROBOT_PUBLIC ROM_ROBOT_IMPORT
  #endif
  #define ROM_ROBOT_PUBLIC_TYPE ROM_ROBOT_PUBLIC
  #define ROM_ROBOT_LOCAL
#else
  #define ROM_ROBOT_EXPORT __attribute__ ((visibility("default")))
  #define ROM_ROBOT_IMPORT
  #if __GNUC__ >= 4
    #define ROM_ROBOT_PUBLIC __attribute__ ((visibility("default")))
    #define ROM_ROBOT_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ROM_ROBOT_PUBLIC
    #define ROM_ROBOT_LOCAL
  #endif
  #define ROM_ROBOT_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // ROM_ROBOT__VISIBILITY_CONTROL_H_
