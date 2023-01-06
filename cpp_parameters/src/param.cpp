#include<chrono>
#include<functional>
#include<memory>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;
 
class MinimalParam  : public rclcpp::Node
{
    public:
        MinimalParam() : Node("minimal_param")
        {
            this->declare_parameter("my_param","world");
            timer_ = this->create_wall_timer(1000ms, std::bind(&MinimalParam::timer_callback, this));
        }
    private:
        void timer_callback()
        {
            std::string my_param_ = this->get_parameter("my_param").get_parameter_value().get<std::string>();
            RCLCPP_INFO(this->get_logger(), "Hello %s", my_param_.c_str());

            std::vector<rclcpp::Parameter> new_params{rclcpp::Parameter("my_param", "world")};
            this->set_parameters(new_params);
        };
        rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin( std::make_shared<MinimalParam>());
    rclcpp::shutdown();
    return 0;
}