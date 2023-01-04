from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                namespace='deepblue',
                package='test',
                executable='talker',
                name='talker_node'
            ),
            Node(
                namespace='deepblue',
                package='test',
                executable='listener',
                name='listener_node'
            )
        ]
    )
