# Livox CSV Capture 

Utility to capture incoming lidar signal into a location as csv. 


## Dependencies 
1. [pcl-ros]()
2. [livox-ros-driver](https://github.com/Livox-SDK/livox_ros_driver)
3. [perception_pcl](http://wiki.ros.org/perception_pcl)


## SAVE THE poincloud_to
1. Replace the contents of the file with the pointcloud_to_pcd.cpp.
`<workspaceName>/src/perception_pcl/pcl_ros/tools/pointcloud_to_pcd.cpp`
2. `catkin_make` the workspace. 
