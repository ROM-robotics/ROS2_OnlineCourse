from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                namespace='deepblue',
                package='cpp_parameters',
                executable='param_set',
                name='blabla_param',
                output="screen",
                emulate_tty=True,
                parameters=[
                    {"my_param": "earth"},
                    {"Lab": "Deep Bule AI Lab"}
                ]
            )
        ]
    )
