#include<chrono>
#include<functional>
#include<memory>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"

using namespace std::chrono_literals;
 
class MinimalPublisher  : public rclcpp::Node
{
    public:
        MinimalPublisher() : Node("minimal_publisher"), count_(0)
        {
            pub_ = this->create_publisher<tutorial_interfaces::msg::Num>("yourtopic",10);
            timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
        }
    private:
        void timer_callback()
        {
            auto msg = tutorial_interfaces::msg::Num();
            msg.num = this->count_++;
            RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: ' " << msg.num << " ' ");
            pub_->publish(msg);
        };
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr pub_;
        size_t count_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin( std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}