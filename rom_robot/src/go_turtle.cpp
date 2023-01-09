// Copyright 2014 Open Source Robotics Foundation, Inc.
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

#include <chrono>
#include <cstdio>
#include <memory>
#include <utility>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "rom_robot/visibility_control.h"

using namespace std::chrono_literals;

namespace rom_robot
{
    class GoTurtle : public rclcpp::Node
    {
        public:
            ROM_ROBOT_PUBLIC
            explicit GoTurtle(const rclcpp::NodeOptions & options);

        protected:
            void on_timer();
            void blabla();

        private:
            size_t count_;
            rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
            rclcpp::TimerBase::SharedPtr timer_;
    };
    void GoTurtle::blabla() {};
    // IMPLEMENTATION
    GoTurtle::GoTurtle(const rclcpp::NodeOptions & options) : Node("go_publisher", options), count_(0)
    {
        pub_ = create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
        timer_ = create_wall_timer(1s, std::bind(&GoTurtle::on_timer, this));
    }

    void GoTurtle::on_timer()
    {
        auto msg = std::make_unique<geometry_msgs::msg::Twist>();
        msg->linear.x= 1.0;
        msg->angular.z= 0.1;
        RCLCPP_INFO(this->get_logger(), "Lin x: '%2f', Ang z: '%2f'", msg->linear.x, msg->angular.z);
        //std::flush(std::cout);
        pub_->publish(std::move(msg));
    }
}  // namespace rom_robot

RCLCPP_COMPONENTS_REGISTER_NODE(rom_robot::GoTurtle)
